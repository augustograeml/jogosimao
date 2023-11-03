#pragma once
#include <SFML/Graphics.hpp>
#include "personagem.hpp"


class Jogador : public Personagem
{

private:
    sf::Texture texturaPersonagem;
    sf::Vector2f posicao;
    int vida;
    float poder;

    //contador pro tempo
    double tempo;

public:
    Jogador();
    ~Jogador();

    void executar();
    void mover();
};