#include <iostream>
#include "dibujarCuadrado.h"
#include "rlutil.h"

using namespace std;


/// DIBUJAR LOS CUADRADOS DE LOS DADOS

void dibujarCuadrado (int posx , int posy){
    rlutil::setColor(rlutil::WHITE);
    for (int x=posx+1 ; x<=posx+7 ; x++){
        for (int y=posy ; y<=posy+2 ; y++){
            rlutil::locate(x , y);
            cout << (char) 219;
        }
    }
}

/// DIBUJAR NÚMEROS EN LOS DADOS

/**void dibujarDados (int dado[],int tam, int posx, int posy){
    int variableAux = 0;
    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);
    for (int i=0;i<tam;i++){
        dado[i] = variableAux;
        switch(variableAux){

        case 1:
            rlutil::locate(posx+3 , posy+1);
            cout << (char) 254;
        break;

        case 2:
            rlutil::locate(posx+2 , posy);
            cout << (char) 220;
            rlutil::locate(posx+6 , posy+2);
            cout << (char) 223;
        break;

        case 3:
            rlutil::locate(posx+2 , posy);
            cout << (char) 220;
            rlutil::locate(posx+4 , posy+1);
            cout << (char) 254;
            rlutil::locate(posx+6 , posy+2);
            cout << (char) 223;
        break;

        case 4:
            rlutil::locate(posx+2 , posy);
            cout << (char) 220;
            rlutil::locate(posx+6 , posy+2);
            cout << (char) 223;
            rlutil::locate(posx+6 , posy);
            cout << (char) 220;
            rlutil::locate(posx+2 , posy+2);
            cout << (char) 223;
        break;

        case 5:
            rlutil::locate(posx+2 , posy);
            cout << (char) 220;
            rlutil::locate(posx+6 , posy+2);
            cout << (char) 223;
            rlutil::locate(posx+6 , posy);
            cout << (char) 220;
            rlutil::locate(posx+2 , posy+2);
            cout << (char) 223;
            rlutil::locate(posx+4 , posy+1);
            cout << (char) 254;
        break;

        case 6:
            rlutil::locate(posx+2 , posy);
            cout << (char) 220;
            rlutil::locate(posx+4 , posy);
            cout << (char) 220;
            rlutil::locate(posx+6 , posy);
            cout << (char) 220;
            rlutil::locate(posx+2 , posy+2);
            cout << (char) 223;
            rlutil::locate(posx+4 , posy+2);
            cout << (char) 223;
            rlutil::locate(posx+6 , posy+2);
            cout << (char) 223;
        break;



    }
}
}**/


void dibujarDados(int numero, int posx, int posy){
    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);
    switch(numero){
    case 1:
            rlutil::locate(posx+4 , posy+1);
            cout << (char) 254;
        break;

        case 2:
            rlutil::locate(posx+2 , posy);
            cout << (char) 220;
            rlutil::locate(posx+6 , posy+2);
            cout << (char) 223;
        break;

        case 3:
            rlutil::locate(posx+2 , posy);
            cout << (char) 220;
            rlutil::locate(posx+4 , posy+1);
            cout << (char) 254;
            rlutil::locate(posx+6 , posy+2);
            cout << (char) 223;
        break;

        case 4:
            rlutil::locate(posx+2 , posy);
            cout << (char) 220;
            rlutil::locate(posx+6 , posy+2);
            cout << (char) 223;
            rlutil::locate(posx+6 , posy);
            cout << (char) 220;
            rlutil::locate(posx+2 , posy+2);
            cout << (char) 223;
        break;

        case 5:
            rlutil::locate(posx+2 , posy);
            cout << (char) 220;
            rlutil::locate(posx+6 , posy+2);
            cout << (char) 223;
            rlutil::locate(posx+6 , posy);
            cout << (char) 220;
            rlutil::locate(posx+2 , posy+2);
            cout << (char) 223;
            rlutil::locate(posx+4 , posy+1);
            cout << (char) 254;
        break;

        case 6:
            rlutil::locate(posx+2 , posy);
            cout << (char) 220;
            rlutil::locate(posx+4 , posy);
            cout << (char) 220;
            rlutil::locate(posx+6 , posy);
            cout << (char) 220;
            rlutil::locate(posx+2 , posy+2);
            cout << (char) 223;
            rlutil::locate(posx+4 , posy+2);
            cout << (char) 223;
            rlutil::locate(posx+6 , posy+2);
            cout << (char) 223;
        break;
    }

    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);

}
