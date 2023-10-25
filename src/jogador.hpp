#pragma once
#include <SFML/Graphics.hpp>
#include "entidade.hpp"


class Jogador: 
    public Entidade
{

private:
    int j;
public:
    Jogador();
    ~Jogador();

    void mover();


};