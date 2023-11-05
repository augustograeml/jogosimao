#pragma once
#include <SFML/Graphics.hpp>
#include "personagem.hpp"


class Jogador : public Personagem
{

protected:
    Texture texturaPersonagem;
    Vector2f posicao;
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