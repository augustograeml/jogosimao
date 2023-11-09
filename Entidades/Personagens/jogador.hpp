#pragma once
#include <SFML/Graphics.hpp>
#include "personagem.hpp"

namespace Entidades
{

class Jogador : public Personagem
{

protected:
    float poder;
    double tempo;

public:
    Jogador(Vector2f pos, Vector2f vel);
    ~Jogador();

    void atualizar();
    void executar();
    void mover(); 
    void atacar(Entidade* jg); 
};

}