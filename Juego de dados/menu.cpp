#include <iostream>
#include "menu.h"
#include "modoUnJugador.h"
#include "modoDosJugadores.h"
#include "funciones.h"
#include "rlutil.h"
#include "puntajeMasAlto.h"
#include "modosimulado.h"
#include <windows.h>
#include <mmsystem.h>
#include "inicio.h"

using namespace std;

void menu(int vecP[], string vecN[]){
bool juego = true;

    int opc;

    do{
        system("cls");
        cout<<"|-----------------MENU PRINCIPAL----------------|"<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"|-1) PRESIONE 1 PARA MODO UN JUGADOR------------|"<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"|-2) PRESIONE 2 PARA MODO DOS JUGADORES---------|"<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"|-3) PRESIONE 3 PARA VER LA PUNTUACION MAS ALTA-|"<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"|-4) PRESIONE 4 PARA ENTRAR AL MODO SIMULADO    |"<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"|-0)-------------------SALIR--------------------|"<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"|---------------INGRESE UNA OPCION--------------|"<<endl;
        cout<<"|_______________________________________________|"<<endl;
        cin>>opc;


        switch(opc){
            case 0:
                PlaySound(TEXT("MENU.wav"),NULL,SND_SYNC);
                system("cls");
                cout<<"Saliendo del juego..."<<endl;
                system("pause");
                juego = false ;
                break;
            case 1:
                PlaySound(TEXT("MENU.wav"),NULL,SND_SYNC);
                system("cls");
                modoUnJugador(vecP , vecN);
                system("pause");
                break;

            case 2:
                PlaySound(TEXT("MENU.wav"),NULL,SND_SYNC);
                system("cls");
                modoDosJugadores(vecP , vecN);
                system("pause");
                break;

            case 3:
                PlaySound(TEXT("MENU.wav"),NULL,SND_SYNC);
                system("cls");
                puntajeMasAlto(vecP , vecN);
                system("pause");
                break;

            case 4:
                PlaySound(TEXT("MENU.wav"),NULL,SND_SYNC);
                system("cls");
                modoSimulado();
                system("pause");
                break;

            default:
                PlaySound(TEXT("WRONG.wav"),NULL,SND_SYNC);
                system("cls");
                cout<< "Opcion incorrecta!!" << endl;
                system("pause");
                break;
        }

    }

     while(juego);

}
