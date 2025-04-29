/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ConjuntoJugadores.cpp
 * Author: juanan
 * 
 * Created on 8 de julio de 2024, 22:18
 */

#include "ConjuntoJugadores.h"
#include <string>
#include <iostream>
using namespace std;

//nuevo vector de jugadores con tamreservado a k y sin jugadores
ConjuntoJugadores::ConjuntoJugadores(int k) {
    vectorJugadores = new Jugador[k];
    numjugadores = 0;
    tamreservado = k;
}

ConjuntoJugadores & ConjuntoJugadores::operator=(const ConjuntoJugadores & orig){
    if(this != &orig){
        delete[] vectorJugadores;
        numjugadores = orig.numJugadores();
        tamreservado = orig.tamreservado;
        vectorJugadores = new Jugador[tamreservado];
        for(int i=0; i<numjugadores; i++){
            vectorJugadores[i] = orig.vectorJugadores[i];
        }
    }
    return *this;
}

//como el operador = pero en este caso el objeto se crea desde 0 con lo que
//no hace falta hacer delete y se reserva directamente
ConjuntoJugadores::ConjuntoJugadores(const ConjuntoJugadores& orig) {
   numjugadores = orig.numJugadores();
   tamreservado = orig.tamreservado;
   vectorJugadores = new Jugador[tamreservado];
   for(int i=0; i<numjugadores; i++){
       vectorJugadores[i] = orig.vectorJugadores[i];
   }
}

ConjuntoJugadores::~ConjuntoJugadores() {
    delete[] vectorJugadores;
}

//Crea un vector de jugadores a partir de un vector de strings
//en este caso reservamos el tamanio justo y necesario para almacenar
//la información
ConjuntoJugadores::ConjuntoJugadores(int n, string * vnicks){
    vectorJugadores = new Jugador[n];
    numjugadores = n;
    int temp = 1;
    for(int i=0; i<n; i++){
        vectorJugadores[i] = Jugador(temp, vnicks[i]);
        temp++;
    vectorJugadores[i].numPartidasGanadas() = 0;
    vectorJugadores[i].numPartidasPerdidas() = 0;
    }
}

//Ordenamos a todos los jugadores en función del criterio:
//partidasganadas/partidasjugadas
// y mostramos por pantalla
string ConjuntoJugadores::mostrarRanking(){
    
    string resultado;
    ConjuntoJugadores ranking(tamreservado);
    for(int i=0; i<numjugadores; i++){
        ranking.vectorJugadores[i] = vectorJugadores[i];
    }
    for(int i=0; i<numjugadores; i++){
        for(int j=0; j<numjugadores-i-1; j++){
            if(vectorJugadores[j].proporcion() < vectorJugadores[j+1].proporcion()){
                ranking.vectorJugadores[j] = vectorJugadores[j+1];
                ranking.vectorJugadores[j+1] = vectorJugadores[j];
            }
        }
    }
    for(int i=0; i<numjugadores; i++){
        resultado += to_string(ranking.vectorJugadores[i].getId()) + " " + 
                ranking.vectorJugadores[i].getNick() + " " + 
                to_string(ranking.vectorJugadores[i].proporcion()) + "\n";
    }
    return resultado;
}

//leemos un conjunto de jugadores de un fichero o flujo
//El fichero o obtención de datos se puede ver en el fichero ejemplo, es:
// 2
// 1 Juan 0 1
// 2 Pedro 1 1
//primero el numero de jugadores y luego en cada fila el id, nick
// partidas ganadas y partidas perdidas del jugador
std::istream & operator>> (std::istream & flujo,  ConjuntoJugadores & m){
    int numjugadores;
    flujo >> numjugadores; 
    m.resize(numjugadores);
    for(int i=0; i<m.numJugadores(); i++){
        int id, numPartidasGanadas, numPartidasJugadas;
        string nick;
        flujo >> id >> nick >> numPartidasGanadas >> numPartidasJugadas;
        m.vectorJugadores[i] = Jugador(id, nick);
        m.vectorJugadores[i].numPartidasGanadas() = numPartidasGanadas;
        m.vectorJugadores[i].numPartidasPerdidas() = numPartidasJugadas - numPartidasGanadas;
        
    }
    return flujo;
}

//para mostrar por pantalla o escribir en fichero los datos del vector de
//jugadores
std::ostream & operator<< (std::ostream & flujo, const ConjuntoJugadores & conjug){
    for(int i=0; i<conjug.numJugadores(); i++){
         flujo << "Jugador: " << conjug[i].getNick() << ", ID:" 
            << conjug[i].getId()<< ", Partidas ganadas:" << conjug[i].numPartidasGanadas() 
            << ", Partidas jugadas:" << conjug[i].numPartidasJugadas() << "\n";
    }
    return flujo;
}

//anaide un jugador al final del vector
ConjuntoJugadores & ConjuntoJugadores::operator+=(const Jugador& newjug) {
     if (numjugadores >= tamreservado) {
        resize(tamreservado == 0 ? 1 : tamreservado * 2);  // Duplicar tamaño si es necesario
    }

    // Agregar el nuevo jugador al final del vector
    vectorJugadores[numjugadores] = newjug;
    numjugadores++;  // Incrementar el número de jugadores

    return *this;
}

//elimina un jugador del vector de jugadores en funcion del id
void ConjuntoJugadores::eliminaJugador(int jugid){
    for(int i=0; i<numjugadores; i++){
        if(vectorJugadores[i].getId() == jugid){
            for(int j=i; j<numjugadores-1; j++){
                vectorJugadores[j] = vectorJugadores[j+1];
            }
            numjugadores--; 
        }
    }
}
//buscamos la posicion de un jugador que tiene un determinado id
int ConjuntoJugadores::buscaJugador(int jugid){
    bool encontrado = false;
    for(int i=0; i<numjugadores; i++){
        if(vectorJugadores[i].getId() == jugid){
            encontrado = true;
            return i;
        }
    }
    return -1;
}

int ConjuntoJugadores::numJugadores() const{
    return numjugadores;
}

//buscamos al jugador por el nick y devolvemos -1 si no existe
int ConjuntoJugadores::buscaJugador(string nickbuscado){
    bool encontrado = false;
    for(int i=0; i<tamreservado; i++){
        if(vectorJugadores[i].getNick() == nickbuscado){
            encontrado = true;
            return i;
        }
    }
    return -1;
}
// optimizar hace que numjugadores == tamreservado,
// no reservamos ninguna posición de más

void ConjuntoJugadores::optimizar(){
    numjugadores = tamreservado;
    Jugador *nuevoVector = new Jugador[tamreservado];
    for(int i=0; i<numjugadores; i++){
        nuevoVector[i] = vectorJugadores[i];
    }
    delete[] vectorJugadores;
    vectorJugadores = nuevoVector;
}
Jugador & ConjuntoJugadores::operator[](int i) const{
    if (i < 0 || i >= numjugadores) {
        throw out_of_range("Índice fuera de rango en ConjuntoJugadores");
    }
    return vectorJugadores[i];
}
void ConjuntoJugadores::ordenaporId(){
   
    for(int i=0; i<tamreservado; i++){
        for(int j=0; j<tamreservado -i -1; j++){
            if(vectorJugadores[j].getId() < vectorJugadores[j+1].getId()){
                Jugador temp = vectorJugadores[j];
                vectorJugadores[j] = vectorJugadores[j+1];
                vectorJugadores[j+1] = temp;
            }
        }
    }
}
void ConjuntoJugadores::resize(int newtam){
    if(newtam > tamreservado){
        Jugador *nuevoVector = new Jugador[newtam];
        for(int i=0; i<numjugadores; i++){
            nuevoVector[i] = vectorJugadores[i];
        }
        delete[] vectorJugadores;
        vectorJugadores = nuevoVector;
        tamreservado = newtam;
    }
    else{
        cout << "El tamaño es menor o igual al anterior";
    }
}

//Une dos objetos conjunto jugadores
ConjuntoJugadores operator+( const ConjuntoJugadores & left, const ConjuntoJugadores & right){
    int newtam = left.numJugadores()+right.numJugadores();
    ConjuntoJugadores resultado(newtam);
    for(int i=0; i<left.numJugadores(); i++){
        resultado += left.vectorJugadores[i];
    }
    for(int i=0; i<right.numJugadores(); i++){
        resultado += right.vectorJugadores[i];
    }
    return resultado;
}