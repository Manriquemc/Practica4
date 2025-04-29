/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Jugador.h
 * Author: juanan
 *
 * Created on 8 de julio de 2024, 22:12
 */

#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <string>

using namespace std;

class Jugador {
public:
    
    /**@brief Constructor de la clase jugador, deja los valores sin iniciar.
     */
    Jugador();
    
    /**@brief Constructor de copia. Copia los datos de orig en jugador.
     *
     */
    Jugador(const Jugador& orig);
    
    /**@brief Jugador no usa memoria dinámica con lo que no hay que implementar
     * aquí.
     */
    virtual ~Jugador();

    /**
     * @brief Devuelve el nick del jugador
     * @return una cadena con el nick del jugador
     */
    string getNick();


    /** @brief Devuelve una referencia a un entero con el número de partidas que ha ganado el jugador.
     * Gracias a la referencia, se puede modificar el valor desde fuera.
     * @retval Una referencia a entero con el numero de partidas que el jugador ha ganado.
     */
    int & numPartidasGanadas();

    /** @brief Devuelve una referencia a un entero con el número de partidas que ha perdido el jugador.
     * Gracias a la referencia, se puede modificar el valor desde fuera.
     * @retval Una referencia a entero con el numero de partidas que el jugador ha perdido.
     */
    int & numPartidasPerdidas();

    /** @brief Devuelve un entero con el número de partidas que ha jugado el jugador.
     * Se puede calcular como la suma de las partidas ganadas y las perdidas. 
     * @retval Un entero con el numero de partidas que el jugador ha jugado en total.
     */
    int numPartidasJugadas() const;

     /** @brief Devuelve el id del jugador.
     * @retval Devuelve el id del jugador.
     */
    int getId() const;
    
    /**
     * @brief Devuelve una referencia a un entero con el id del usuario. De esta forma,
     * se puede modificar el id del objeto desde fuera de este. 
     * @return Una referencia al id del jugador. 
     */
    int & setId();
    
    /** @brief Crea un objeto jugador con un id y nick determinado
    */
    Jugador(int id, string nuevoNick);
    
     /** @brief Devuelve un entero con el número de partidas que ha ganado el jugador.
     * La funcion es const para que pueda ser usado en los operadores > < == ...
     * @retval Un entero con el numero de partidas que el jugador ha ganado.
     */   
    int numPartidasGanadas() const;
    /**
     * @brief Operador de asignación (asigna los valores de orig al objeto).
     * @param orig objeto jugador que se asigna.
     * @return Devuelve el objeto jugador ya asignado.
     */
    Jugador & operator=(const Jugador & orig);

    /**@brief Operador de flujo de salida. Introduce en la variable ostream flujo
     * los valores de id, nick, partidasganadas y partidasjugadas en ese orden.
     * Los valores están separados por espacios.
     * @return Devuelve flujo con los valores del objeto jugador introducidos.
     */
    friend std::ostream & operator<< (std::ostream & flujo, const  Jugador & jug);
    
    int proporcion();

private:
    //nick del jugador 
    string nick;
    //id del jugador 
    int id;
    int numpartidasganadas=0;
    int numpartidasperdidas=0;
};


/**
 * @brief Determina si 2 jugadores tienen el mismo valor de 
 * numpartidasganadas/numpartidasjugadas.
 * @param izq uno de los jugadores.
 * @param dch el otro jugador.
 * @return true si los 2 jugadores obtienen el mismo valor de ganadas/jugadas*/
bool operator==(  const Jugador & izq,  const Jugador & dch);

/**
* @brief Determina si 2 jugadores tienen distinto número de ganadas/jugadas.
* @param izq uno de los jugadores.
* @param dch el otro jugador.
* @return true si los 2 jugadores obtienen distinto valor de ganadas/jugadas.
* false en otro caso.
*/
bool operator!=( const Jugador & izq,  const Jugador & dch);

/**
* @brief Determina si el jug izq obtiene menos valor de ganadas/jugadas que el jugador dch.
* @param izq uno de los jugadores.
* @param dch el otro jugador.
* @return true si el jugador izq obtiene menor valor de ganadas/jugadas que el jugador dch.
*/
bool operator<( const Jugador &izq,  const Jugador & dch);

/**
* @brief Determina si el jug izq obtiene mas valor de ganadas/jugadas que el jugador dch.
* @param izq uno de los jugadores.
* @param dch el otro jugador.
* @return true si el jugador izq obtiene mejor valor de ganadas/jugadas que el jugador dch.
*/
bool operator>( const Jugador &izq,  const Jugador & dch);

/**
* @brief Determina si el jug izq tiene menos o el mismo valor de ganadas/jugadas que el jugador dch.
* @param izq uno de los jugadores.
* @param dch el otro jugador.
* @return true si el jugador izq obtiene menos o el msimo valor de ganadas/jugadas que el jugador dch.
*/
bool operator<=( const Jugador &izq, const  Jugador & dch);

/**
* @brief Determina si el jug izq obtiene el mismo o mejor valor de ganadas/perdidas que el jugador dch.
* @param izq uno de los jugadores.
* @param dch el otro jugador.
* @return true si el jugador izq obtiene el mismo o mejor valor de ganadas/perdidas que el jugador dch.
*/
bool operator>=( const Jugador &izq, const Jugador & dch);


#endif /* JUGADOR_H */

