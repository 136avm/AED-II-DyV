#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include "generador.h"
#include <sys/time.h>
using namespace std;

array<int, 2> resolucionDirecta(string A, char C, int m) {

    // Variables
    array<int, 2> solucion = {0, 0}; // maxCont := array[0]; maxIdx := array[1]
    int n = A.length();

    // Algoritmo
    for(int i=0; i<m; i++) {
        if(A[i] == C) {
            solucion[0]++;
        }
    }

    if(solucion[0] == m) {
        return solucion;
    }

    int cont = solucion[0];

    for(int i=1; i<=(n - m); i++) {
        if(A[i-1] == C) {
            cont--;
        }
        if(A[i+m-1] == C) {
            cont++;
        }
        if(cont > solucion[0]) {
            solucion[0] = cont;
            solucion[1] = i;
        }
        if(solucion[0] == m) {
            return solucion;
        }
    }

    return solucion;
}

array<int, 2> combinar(array<int, 2> res1, array<int, 2> res2, string A, char C, int m) {

    // Variables
    int cont = 0;
    res2[1] += A.length()/2;
    array<int, 2> solucion = {0, 0};

    // Algoritmo
    if(res1[0] >= res2[0]) {
        solucion = res1;
    }
    else {
        solucion = res2;
    }

    if(solucion[0] == m) {
        return solucion;
    }

    for(int i=(A.length()/2-m+1); i<=(A.length()/2); i++) {
        if(A[i] == C) {
            cont++;
        }
    }

    if(cont > solucion[0]) {
        solucion[0] = cont;
        solucion[1] = A.length()/2-m+1;
    }

    for(int i=(A.length()/2-m+2); i<=(A.length()/2); i++) {
        if(A[i-1] == C) {
            cont--;
        }
        if(A[i+m-1] == C) {
            cont++;
        }

        if(cont > solucion[0]) {
            solucion[0] = cont;
            solucion[1] = i;
        }
        if(solucion[0] == m) {
            return solucion;
        }
    }

    return solucion;
}

array<int, 2> divideYVenceras(string A, char C, int m) {

    // Variables
    int n = A.length();

    // Algoritmo
    if(n >= 2*m /*Sustituir esto por n_{0}*/) {
        return combinar(divideYVenceras(A.substr(0, n/2), C, m), divideYVenceras(A.substr(n/2), C, m), A, C, m);
    }
    else {
        return resolucionDirecta(A, C, m);
    }
}

int main() {
    string A = generarCadena(1000000);
    char C = 'c';
    int m = A.length()/1000;
    double tiempo;
    struct timeval ti, tf;
    gettimeofday(&ti,NULL);
    array<int, 2> solucion = divideYVenceras(A, C, m);
    gettimeofday(&tf,NULL);
    tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000;
    if(solucion[0] == resolucionDirecta(A, C, m)[0]) {
        cout << tiempo << endl;
    }
    return 0;
}
