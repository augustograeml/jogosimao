#pragma once
#include "jogador.hpp"
#include <SFML/Graphics.hpp>
#include "personagem.hpp"


class Jogador2 : public Personagem
{

protected:
    int vida;
    float poder;

    //contador pro tempo
    double tempo;

public:
    Jogador2(Vector2f pos, Vector2f vel);
    ~Jogador2();

    void atualizar();
    void executar();
    void mover(); 
    void atacar(); 
};