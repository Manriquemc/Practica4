/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Jugador.cpp
 * Author: juanan
 * 
 * Created on 8 de julio de 2024, 22:12
 */

#include "Jugador.h"
#include <string>
#include <iostream>
using namespace std;

Jugador::Jugador() {
    nick = "";
    id = 0;
    numpartidasganadas = 0;
    numpartidasperdidas = 0;
}

string Jugador::getNick(){
    return nick;
}

Jugador::Jugador(const Jugador& orig) {
    nick = orig.nick;
    id = orig.id;
    numpartidasganadas = orig.numPartidasGanadas();
    numpartidasperdidas = orig.numPartidasJugadas()- orig.numPartidasGanadas();
}

Jugador::~Jugador() {
}

int Jugador::numPartidasGanadas() const{
    return numpartidasganadas;
}
int & Jugador::numPartidasGanadas(){
    return numpartidasganadas;
}

int & Jugador::numPartidasPerdidas(){
    return numpartidasperdidas;
}
//como solo almacenamos las partidas ganadas y las perdidas necesitamos
//calcular las partidas jugadas como suma de ambas. Mejor así que duplicar
//información
int Jugador::numPartidasJugadas() const {
    return (numpartidasganadas + numpartidasperdidas);
}

int Jugador::getId() const{
    return id;
}

Jugador::Jugador(int newid, string nuevoNick){
    id = newid;
    nick = nuevoNick;
}
//devolvemos referencia al valor para cambiarlo desde fuera
int & Jugador::setId(){
    return id;
}


Jugador & Jugador::operator=(const Jugador & orig){
    if(this != &orig){
        nick = orig.getNick();
        id = orig.getId();
        numpartidasganadas = orig.numPartidasGanadas();
        numpartidasperdidas = orig.numPartidasJugadas() - orig.numPartidasGanadas();
    }
    return *this;
}
//Comparamos dos jugadores en funcion de partidasganadas/partidasjugadas
//implementamos todos los operadores
bool operator==( const Jugador & izq, const Jugador & dch){
    if(izq.proporcion() == dch.proporcion()){
        return true;
    }
    else return false;
}
bool operator!=( const Jugador & izq, const  Jugador & dch){
    if(izq.proporcion() != dch.proporcion()){
        return false;
    }
    else return true;
}
bool operator<( const Jugador &izq, const Jugador & dch){
    if(izq.proporcion() < dch.proporcion()){
        return true;
    }
    else return false;
}
bool operator>( const Jugador &izq, const Jugador & dch){
    if(izq.proporcion() > dch.proporcion()){
        return true;
    }
    else return false;
}
bool operator<=( const Jugador &izq,  const Jugador & dch){
    if(izq.proporcion() <= dch.proporcion()){
        return true;
    }
    else return false;
}
bool operator>=( const Jugador &izq, const Jugador & dch){
    if(izq.proporcion() >= dch.proporcion()){
        return true;
    }
    else return false;
}


//imprimimos todos los datos del jugador
std::ostream & operator << (std::ostream & flujo, const  Jugador & jug){
    flujo << "Jugador: " << jug.getNick() << ", ID:" 
          << jug.getId()<< ", Partidas ganadas:" << jug.numPartidasGanadas() 
          << ", Partidas jugadas:" << jug.numPartidasJugadas();
    return flujo;
}

int Jugador::proporcion(){
    return numpartidasganadas/(numpartidasganadas+numpartidasperdidas);
}