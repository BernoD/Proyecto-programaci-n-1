#include <iostream>
#include "funciones.h"
#include "modoDosJugadores.h"
#include "calcularPuntaje.h"
#include "dibujarCuadrado.h"
#include "rlutil.h"
using namespace std;


void modoDosJugadores(int vecP[] , string vecN[]){

    const int tam = 6;
    int dadoJ1[tam];
    int dadoJ2[tam];

    string jugador1;
    string jugador2;

    ///Puntaje J1
    int puntajeRondaJ1 = 0;
    bool hayEscaleraJ1 = false;

    ///Puntaje J2
    int puntajeRondaJ2 = 0;
    bool hayEscaleraJ2 = false;

    ///Turnos
    int turnoJ1 = 1 , turnoJ2 = 1 ;
    int ronda =1;

    ///Desempate

    int rondaDesempateJ1 = 0;
    int turnoDesempateJ1 = 0;

    int rondaDesempateJ2 = 0;
    int turnoDesempateJ2 = 0;
    string ganador;

    system("cls");

    cout<<" INGRESE EL NOMBRE DEL JUGADOR NUMERO 1: "<<endl;
    jugador1 = nombre();
    PlaySound(TEXT("MENU.wav"),NULL,SND_SYNC);
    system("cls");
    int puntajeTurnoJ1 = 0;
    int maxPuntajeTurnoJ1 = 0;

    cout<<" INGRESE EL NOMBRE DEL JUGADOR NUMERO 2: "<<endl;
    jugador2 = nombre();
    PlaySound(TEXT("MENU.wav"),NULL,SND_SYNC);
    system("cls");
    int puntajeTurnoJ2 = 0;
    int maxPuntajeTurnoJ2 = 0;

    system("cls");

    cout<<"Bienvenidos "<<jugador1 << " y " << jugador2 <<" a Cien o Escalera."<<endl;
            cout<<endl;
    system("pause");
    system("cls");

    //while( (puntajeRondaJ1 < 100 || puntajeRondaJ2 < 100 || hayEscaleraJ1 == false || hayEscaleraJ2 == false)
       while((puntajeRondaJ1 <100 && hayEscaleraJ1==false) || (puntajeRondaJ2 <100 && hayEscaleraJ2 == false) ){


            ///CICLO FOR DE 3 TIRADAS PARA JUGADOR N°1
            for ( int turnoJ1=1 ; turnoJ1<4 ; turnoJ1++){

                cout<<"TURNO DE " << jugador1<<"  |  RONDA Nø "<<ronda<<"  |  PUNTAJE TOTAL: "<<puntajeRondaJ1<<" PUNTOS"<<endl;
                cout<<"-------------------------------------------------------------"<<endl;
                cout<<"Tirada n£mero: "<<turnoJ1<<endl;
                cout<<"-------------------------------------------------------------"<<endl;
                cout<<endl;

                // Cargar tirada
                tirada(dadoJ1,tam);
                //Mostrar tirada
                PlaySound(TEXT("DADOS.wav"),NULL,SND_SYNC);
                mostrarTirada(dadoJ1, tam);
                //Calcular puntajes
                ordenarVector(dadoJ1, tam);
                hayEscaleraJ1 = escalera(dadoJ1,tam);
                int cantRepetidosJ1 = contRepetidos(dadoJ1, tam);
                if(cantRepetidosJ1 == 5){
                    puntajeTurnoJ1 = sextetoX(dadoJ1, tam,puntajeTurnoJ1);
                    puntajeTurnoJ1 = sexteto6(dadoJ1, tam,puntajeTurnoJ1);
                }else{
                    puntajeTurnoJ1 = sumaDados(dadoJ1, tam,puntajeTurnoJ1);
                }


                cout<<"------Puntaje de la tirada: "<<puntajeTurnoJ1<<"------"<<endl;

                if(puntajeRondaJ1 >= 100){
                    turnoDesempateJ1 = turnoJ1;
                }

                system("pause");
                system("cls");




                if(puntajeTurnoJ1  > maxPuntajeTurnoJ1){
                    maxPuntajeTurnoJ1 = puntajeTurnoJ1;
                }
            }



            puntajeRondaJ1 += maxPuntajeTurnoJ1;


            /// CICLO FOR DE 3 TIRADAS PARA JUGADOR N°2
            for ( int turnoJ2=1 ; turnoJ2<4 ; turnoJ2++){

                cout<<"TURNO DE " << jugador2<<"  |  RONDA Nø "<<ronda<<"  |  PUNTAJE TOTAL: "<<puntajeRondaJ2<<" PUNTOS"<<endl;
                cout<<"-------------------------------------------------------------"<<endl;
                cout<<"Tirada n£mero: "<<turnoJ2<<endl;
                cout<<"-------------------------------------------------------------"<<endl;
                cout<<endl;


                // Cargar tirada
                tirada(dadoJ2,tam);
                //Mostrar tirada
                PlaySound(TEXT("DADOS.wav"),NULL,SND_SYNC);
                mostrarTirada(dadoJ2, tam);
                //Calcular puntajes
                ordenarVector(dadoJ2, tam);
                hayEscaleraJ2 = escalera(dadoJ2,tam);
                int cantRepetidosJ2 = contRepetidos(dadoJ2, tam);
                if(cantRepetidosJ2 == 5){
                    puntajeTurnoJ2 = sextetoX(dadoJ2, tam,puntajeTurnoJ2);
                    puntajeTurnoJ2 = sexteto6(dadoJ2, tam,puntajeTurnoJ2);
                }else{
                    puntajeTurnoJ2 = sumaDados(dadoJ2, tam,puntajeTurnoJ2);
                }

                cout<<"------Puntaje de la tirada: "<<puntajeTurnoJ2<<"------"<<endl;

                if(puntajeRondaJ2 >= 100){
                    turnoDesempateJ2 = turnoJ2;
                }


                system("pause");
                system("cls");




                if(puntajeTurnoJ2  > maxPuntajeTurnoJ2){
                    maxPuntajeTurnoJ2 = puntajeTurnoJ2;
                }
            }



            puntajeRondaJ2 += maxPuntajeTurnoJ2;

        cout<<" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"                   RONDA Nø "<<ronda<<"                    "<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"                      "<<jugador1<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"          MAYOR PUNTAJE DE LA RONDA: "<<maxPuntajeTurnoJ1<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"                 PUNTAJE TOTAL: "<<puntajeRondaJ1<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"                -----------------               "<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"                      "<<jugador2<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"          MAYOR PUNTAJE DE LA RONDA: "<<maxPuntajeTurnoJ2<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"                PUNTAJE TOTAL: "<<puntajeRondaJ2<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"                                                 "<<endl;
        cout<<"|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|"<<endl;
        system("pause");
        maxPuntajeTurnoJ1 = 0;
        maxPuntajeTurnoJ2 = 0;
        system("cls");

    ronda++;




        if(puntajeRondaJ1 >= 100 && puntajeRondaJ2 >=100){
            ganador = desempate(jugador1, turnoDesempateJ1, jugador2, turnoDesempateJ2);
            if(ganador == "empate"){
                if(puntajeRondaJ1 > puntajeRondaJ2){
                    system("cls");
                    cout<<"Por desempate, el ganador es: "<<jugador1<<endl;
                    cout<<"Su puntaje total es: "<<puntajeRondaJ1<<endl;
                    cout<<"Alcanzado en "<<ronda<<" rondas y "<<turnoDesempateJ1+1<< " tiradas."<<endl;
                    if (puntajeRondaJ1>vecP[0]){
                    vecP[0]=puntajeRondaJ1;
                    vecN[0]=jugador1;
                    }
                    PlaySound(TEXT("GANASTE.wav"),NULL,SND_SYNC);
                    system("pause");
                }else{
                    system("cls");
                    cout<<"Por desempate, el ganador es: "<<jugador2<<endl;
                    cout<<"Su puntaje total es: "<<puntajeRondaJ2<<endl;
                    cout<<"Alcanzado en "<<ronda<<" rondas y "<<turnoDesempateJ2+1<< " tiradas."<<endl;
                    if (puntajeRondaJ2>vecP[0]){
                    vecP[0]=puntajeRondaJ2;
                    vecN[0]=jugador2;
                    }
                    PlaySound(TEXT("GANASTE.wav"),NULL,SND_SYNC);
                    system("pause");
                }

            }

        }else if(puntajeRondaJ1 >=100){
            system("cls");
            cout<<"JUGADOR 1 HA GANADO"<<endl;
            if (puntajeRondaJ1>vecP[0]){
                    vecP[0]=puntajeRondaJ1;
                    vecN[0]=jugador1;
                    }
            PlaySound(TEXT("GANASTE.wav"),NULL,SND_SYNC);
            cout << "Felicidades " << jugador1 << " ha ganado!!!" << endl;
            cout << "Su puntaje es: " << puntajeRondaJ1 << " puntos." << endl;
            system("pause");
            break;

        }else if(puntajeRondaJ2 >=100){
            system("cls");
            cout<<"JUGADOR 2 HA GANADO"<<endl;
            if (puntajeRondaJ2>vecP[0]){
                    vecP[0]=puntajeRondaJ2;
                    vecN[0]=jugador2;
            }
            PlaySound(TEXT("GANASTE.wav"),NULL,SND_SYNC);
            cout << "Felicidades " << jugador2 << " ha ganado!!!" << endl;
            cout << "Su puntaje es: " << puntajeRondaJ2 << " puntos." << endl;
            system("pause");
            break;

        }





        //////////////////////////////////
        if (hayEscaleraJ1 == true ){
                cout<<endl;
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
                cout<<"           Felicitaciones " << jugador1 <<"!!"<<endl;
                cout<<"             Ganaste por escalera!"<<endl;
                break;
                }
        if (hayEscaleraJ2 == true ){
                cout<<endl;
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
                cout<<"           Felicitaciones " << jugador2 <<"!!"<<endl;
                cout<<"             Ganaste por escalera!"<<endl;
                break;
                }
            }

            system("cls");


}



