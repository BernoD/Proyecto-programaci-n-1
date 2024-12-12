#include <iostream>
#include <cstdlib>
#include "calcularPuntaje.h"
#include "funciones.h"

using namespace std;
int sexteto6(int vec[], int tam, int puntaje){

    ordenarVector(vec, tam);
    int suma = 0;
    for(int i=0;i<tam;i++){
        suma+=vec[i];
    }
    if(suma == 36){
        puntaje = 0;
    }
    PlaySound(TEXT("FAIL6X.wav"),NULL,SND_SYNC);
    return puntaje;
}


bool escalera(int vec[], int tam){
    int contRepetidos = 0;
    ordenarVector(vec,tam);
    for(int i=0;i<tam;i++){
        if(vec[i]==vec[i+1]){
            contRepetidos++;
        }
    }
    if(contRepetidos == 0){
        return true;
    }else{
        return false;
    }
}

int sextetoX(int vec[], int tam, int puntaje){
    int contRepetidos = 1;
    int valorDado;
    ordenarVector(vec, tam);
    for(int i=0;i<tam;i++){
        if(vec[i]==vec[i+1]){
            contRepetidos++;
        }
    }

    if(contRepetidos == 6){
        valorDado = vec[0];
        puntaje += valorDado*10;
        return puntaje;
    }else{
        return puntaje;
    }
}

int sumaDados(int vec[], int tam, int puntaje){
    ordenarVector(vec, tam);
    int contRepetidos = 0;
    int suma = 0;
    for(int i=0;i<tam;i++){
        if(vec[i]==vec[i+1]){
            contRepetidos++;
        }
    }
    if(contRepetidos <= 5){
        for(int i=0;i<tam;i++){
            suma += vec[i];
        }
    }
    puntaje = suma;
    return puntaje;

}

int contRepetidos(int vec[],int tam){
    int cantRepetidos = 1;
    ordenarVector(vec, tam);
    for(int i=0;i<tam;i++){
        if(vec[i]==vec[i+1]){
            cantRepetidos++;
        }
    }
    return cantRepetidos;
}

string desempate(string jugador1, int turnoJugador1, string jugador2, int turnoJugador2){
    string ganador;
    string empate = "empate";
    if(turnoJugador1 == turnoJugador2){
        ganador = empate;
    }else if(turnoJugador1 < turnoJugador2){
        ganador = jugador1;
    }else{
        ganador = jugador2;
        };


return ganador;
}
