#include <iostream>
#include "modosimulado.h"
#include "funciones.h"
#include "calcularPuntaje.h"
using namespace std;

///CARGAR DADOS MANUALMENTE
void modoSimulado(){
    const int tam = 6;
    int dado [tam];
    string jugador1 = nombre();

    //Puntaje
    int puntajeRonda = 0;
    bool hayEscalera = false;

    //Ronda
    int ronda = 1;


    //Inicio
    cout<<" INGRESE SU NOMBRE: "<<endl;
    jugador1 = nombre();
    system("cls");
    int puntajeTurno = 0;
    int maxPuntajeTurno = 0;

    cout<<"-----------Bienvenido "<< jugador1<< " a modo Simulado-------------" << endl;
    cout<<"En este modo podra ingresar el valor de los dados del 1 al 6."<< endl;
      system("pause");
    system("cls");


    while(hayEscalera ==false && puntajeRonda <100){

        int turno = 1;
        while(turno<4){

            cout<<"TURNO DE " << jugador1<<"  |  RONDA Nø "<<ronda<<"  |  PUNTAJE TOTAL: "<<puntajeRonda<<" PUNTOS"<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"Tirada Numero: "<<turno<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<endl;

        // Carga de dado
        {
            int n;
            for (int i = 0; i<tam ; i++)
            {
                system("cls");
                cout<< " Ingresar el valor deseado del dado Nø "<<i+1<<endl;
                cin >> n;
                dado [i] = n;

            }
        }
        // Mostrar Tirada
        PlaySound(TEXT("DADOS.wav"),NULL,SND_SYNC);
        mostrarTirada(dado, tam);

        //calcular puntajes
        hayEscalera = escalera(dado,tam);
        ordenarVector(dado, tam);
        int cantRepetidos = contRepetidos(dado, tam);
        if(cantRepetidos == 6)
        {
            puntajeTurno = sextetoX(dado, tam,puntajeTurno);
            puntajeTurno = sexteto6(dado, tam,puntajeTurno);
        }
        else
        {
            puntajeTurno = sumaDados(dado, tam,puntajeTurno);
        }
        cout<<"-------------------------------------------------------------"<<endl;
            cout<<"Puntaje de la tirada: "<<puntajeTurno<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"Maximo puntaje de la ronda: "<<maxPuntajeTurno<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
            turno++;

        if(hayEscalera == true)
        {
            cout<<endl;
            cout<<"    Felicitaciones " << jugador1 <<"!!"<<endl;
            cout<<"    Ha ganado por escalera!"<<endl;
            PlaySound(TEXT("ESCALERA.wav"),NULL,SND_SYNC);
        }
        system("pause");
        system("cls");


        if(puntajeTurno > maxPuntajeTurno){
            maxPuntajeTurno = puntajeTurno;
        }
    }
        system("pause");

        puntajeRonda += maxPuntajeTurno;
        cout<<" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"                      "<<jugador1<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"                   RONDA Nø "<<ronda<<"                    "<<endl;
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

}

