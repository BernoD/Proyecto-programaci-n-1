#include <iostream>
#include <ctime>
#include "modoUnJugador.h"
#include "modoDosJugadores.h"
#include "funciones.h"
#include "rlutil.h"
#include "puntajeMasAlto.h"
#include "inicio.h"

using namespace std;

int main()
{
    srand(time(0));

    int vecP[1]={0};
    string vecN[1]={"NADIE"};

    inicio( vecP , vecN);

    return 0;
}
