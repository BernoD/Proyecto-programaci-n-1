#include <iostream>
#include "funciones.h"
#include "dibujarCuadrado.h"
#include "rlutil.h"

using namespace std;

//Delaracion de funciones

int tirarDado(){
    return (rand()%6)+1;
}

void tirada(int vec[], int tam){
    for(int i=0; i<tam ;i++){
        vec[i] = tirarDado();
    }
}

void mostrarTirada(int vec[], int tam){

    for(int i=0;i<tam;i++){
        //cout<<"Dado #"<<i+1<<" :"<<vec[i]<<endl; "Funciona"
        cout<<endl;
        dibujarCuadrado(i*10, 6 );
        dibujarDados(vec[i], i*10, 6 );
        rlutil::resetColor();
        cout<<endl;
        cout<<endl;
        cout<<endl;
    }
}

string nombre(){
    string jugador;
    getline(cin,jugador);

    if(jugador == ""){    getline(cin,jugador);

    }
    return jugador;

}
void ordenarVector(int vec[],int tam){
    for(int i=0;i<tam;i++){
        for(int j=0;j<tam-1;j++){
            int aux;
            if(vec[j]>vec[j+1]){
                aux = vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=aux;
            }
        }
    }
}

void CalcularPuntajeMasAlto( string nombre , int puntaje){
int puntajeMaximo = 0;

    if (puntaje > puntajeMaximo){
        puntajeMaximo = puntaje;
    }
    if (puntajeMaximo == 0){
        cout << "Aún no se registra un puntaje máximo" << endl;
    }
    else{
        cout << "El puntaje máximo es de: " << nombre << " con la cantidad de: " << puntaje << " puntos." << endl;
    }

}



//Desarrollo de funciones
