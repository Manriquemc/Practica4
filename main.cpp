/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanan
 *
 * Created on 8 de julio de 2024, 22:10
 */

#include <cstdlib>
#include "Jugador.h"
#include "ConjuntoJugadores.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Jugador jug(1,"Pedro");
    cout << jug << endl;
    Jugador jug2(jug);
    Jugador jug3 = jug;
    jug3.numPartidasGanadas() = 5;
    jug3.numPartidasPerdidas() = 5;
    cout << jug << endl  << jug2 << endl << jug3 << endl;
    if (jug3 > jug) cout << "correcto" << endl;
    if (jug == jug2) cout << "correcto" << endl;
    if (!(jug3 <= jug)) cout << "correcto" << endl;
    cout << "PRUEBAS DE CONJUNTOJUGADORES" << endl;
    //PRUEBA CONJUNTOJUGADORES
    ConjuntoJugadores conjug;
    conjug+=jug3;
    cout << conjug;

    string nicks[] = {"Cristina", "Juan", "Lucas","Pablo"};
    ConjuntoJugadores conjug2(4,nicks);
    cout << endl;
    cout << conjug2 << endl;
    cout << endl;
    conjug2 = conjug2 + conjug;
    cout << conjug2 << endl;
    cout << endl;
    conjug2[0].numPartidasGanadas() = 6;
    conjug2[0].numPartidasPerdidas() = 1;
    conjug2[1].numPartidasGanadas()= 3;
    conjug2[1].numPartidasPerdidas()=0;
    conjug2[2].numPartidasGanadas() = 4;
    conjug2[2].numPartidasPerdidas() = 6;
    conjug2[3].numPartidasGanadas() = 9;
    conjug2[3].numPartidasPerdidas() = 10;
    conjug2[4].numPartidasGanadas() =3;
    conjug2[4].numPartidasPerdidas() =4;
    cout << conjug2 << endl;
    cout << conjug2.mostrarRanking() << endl;

    conjug2.eliminaJugador(conjug2.buscaJugador("Lucas"));
    cout << conjug2 << endl;
    conjug2.optimizar();
    cout << endl;
    cout << conjug2 << endl;
    conjug2+=jug;
    cout << conjug2 << endl;

    ofstream fo;
    fo.open("jugadores.txt");
    fo << conjug2;
    fo.close();

    ConjuntoJugadores cj3;
    ifstream fi;
    fi.open("jugadores.txt");
    fi >> cj3;
    fi.close();
    cout << cj3 << endl;
    return 0;
}

