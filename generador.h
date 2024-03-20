#ifndef GENERADOR_H
#define GENERADOR_H

#include <iostream>
#include <string>
using namespace std;

string generarCadena(int n) {
    string cadena = "";
    srand(time(0));
    for(int i=0; i<n; i++) {
        cadena += (char)('a' + (rand() % 26));
    }
    return cadena;
}

string generarMejorCaso(int n, char C) {
    string cadena = "";
    for(int i=0; i<n; i++) {
        cadena += C;
    }
    return cadena;
}

string generarPeorCaso(int n, char C) {
    string cadena = "";
    srand(time(0));
    for(int i=0; i<n; i++) {
        char letra = 'a' +rand()%26;
        if(letra == C) {
            i--;
        }
        else {
            cadena += letra;
        }
    }
    return cadena;
}

#endif // GENERADOR_H