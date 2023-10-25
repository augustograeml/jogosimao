#pragma once
#include <SFML/Graphics.hpp>
#include "entidade.hpp"


class Jogador: 
    public Entidade
{

private:
    sf::Texture texturaPersonagem;
public:
    Jogador();
    ~Jogador();

    void mover();
    

};