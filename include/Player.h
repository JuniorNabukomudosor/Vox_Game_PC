#pragma once
#include <string>
//El jugador sera el struct que se encargara de manterner los datos, puntos, elecciones y nombres de cada jugador.

struct Player
{
    std::string Name;
    int Points;
    int Id;
    int ChoisedOption = -1;
};
