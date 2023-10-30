#pragma once
#include <SFML/Graphics.hpp>
#include "entidade.hpp"


class Jogador: 
    public Entidade
{

private:
    sf::Texture texturaPersonagem;
    sf::Vector2f posicao
    int vida;
    float poder;

public:
    Jogador();
    ~Jogador();

    void mover();
    //void getPosition();
};