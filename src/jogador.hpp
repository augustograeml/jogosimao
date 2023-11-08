#pragma once
#include <SFML/Graphics.hpp>
#include "personagem.hpp"


class Jogador : public Personagem
{

protected:
    int vida;
    float poder;

    //contador pro tempo
    double tempo;

public:
    Jogador(Vector2f pos, Vector2f vel);
    ~Jogador();

    void atualizar();
    void executar();
    void mover(); 
    void atacar(); 
};