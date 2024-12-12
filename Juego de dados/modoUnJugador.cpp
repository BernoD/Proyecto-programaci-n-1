#include <iostream>
#include "funciones.h"
#include "modoUnJugador.h"
#include "calcularPuntaje.h"
#include "dibujarCuadrado.h"
#include "rlutil.h"
#include "puntajeMasAlto.h"
#include "inicio.h"

using namespace std;

void modoUnJugador( int vecP[] , string vecN[]){

    const int tam = 6;
    int dado[tam];
    string jugador1;

    //Puntaje
    int puntajeRonda = 0;
    bool hayEscalera = false;

    //Ronda
    int ronda=1;

    cout<<"    INGRESE SU NOMBRE: "<<endl;
    jugador1 = nombre();
    PlaySound(TEXT("MENU.wav"),NULL,SND_SYNC);
    system("cls");
    int puntajeTurno = 0;
    int maxPuntajeTurno = 0;

    cout<<"Bienvenido "<<jugador1<<" a Cien o Escalera."<<endl;
    system("pause");
    system("cls");

    while(puntajeRonda < 100  && hayEscalera == false){

        int turno=1;
        while(turno<4){

            system("cls");
            cout<<"TURNO DE " << jugador1<<"  |  RONDA Nø "<<ronda<<"  |  PUNTAJE TOTAL: "<<puntajeRonda<<" PUNTOS"<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"Tirada Numero: "<<turno<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<endl;
            // Cargar tirada
            tirada(dado,tam);
            //Mostrar tirada
            PlaySound(TEXT("DADOS.wav"),NULL,SND_SYNC);
            mostrarTirada(dado, tam);

            //Calcular puntajes
            ordenarVector(dado, tam);
            hayEscalera = escalera(dado,tam);
            int cantRepetidos = contRepetidos(dado, tam);
            if(cantRepetidos == 5){
                puntajeTurno = sextetoX(dado, tam,puntajeTurno);
                puntajeTurno = sexteto6(dado, tam,puntajeTurno);
            }else{
                puntajeTurno = sumaDados(dado, tam,puntajeTurno);
            }
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"Puntaje de la tirada: "<<puntajeTurno<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"Maximo puntaje de la ronda: "<<maxPuntajeTurno<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
            turno++;
            system("pause");


            if(hayEscalera == true){
                cout<<" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
                cout<<"|                                               |"<<endl;
                cout<<"|                  FELICIDADES!!!               |"<<endl;
                cout<<"|                                               |"<<endl;
                cout<<"|              HA GANADO CON ESCALERA           |"<<endl;
                cout<<"|                                               |"<<endl;
                cout<<"|                 EN LA RONDA Nø "<<ronda<<"              |"<<endl;
                cout<<"|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|"<<endl;
                PlaySound(TEXT("ESCALERA.wav"),NULL,SND_SYNC);
                cout<<endl;
                cout<<endl;
                cout<<endl;
            system("pause");
            return;
            }


            if(puntajeTurno>maxPuntajeTurno){
                maxPuntajeTurno = puntajeTurno;
            }
        }

        puntajeRonda += maxPuntajeTurno;

        system("cls");
        cout<<" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"                      "<<jugador1<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"                   RONDA Nø"<<ronda<<"                    "<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"          MAYOR PUNTAJE DE LA RONDA: "<<maxPuntajeTurno<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"                 PUNTAJE TOTAL: "<<puntajeRonda<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"                                                 "<<endl;
        cout<<"|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|"<<endl;
        system("pause");
        ronda++;
        maxPuntajeTurno = 0;
        system("cls");
    }


system("cls");
cout << "Felicidades " << jugador1 << " ha ganado!!!" << endl;
cout << "Su puntaje es: " << puntajeRonda << " puntos." << endl;
PlaySound(TEXT("GANASTE.wav"),NULL,SND_SYNC);

if (puntajeRonda>vecP[0]){
    vecP[0]=puntajeRonda;
    vecN[0]=jugador1;
}


}
