#pragma once
#include "entidade.hpp"

class Personagem : public Entidade
{
    protected:
        int vidas;
    public:
        Personagem(Vector2f pos, Vector2f vel);
        ~Personagem();
        
        virtual void mover() = 0;
        virtual void atualizar() = 0;
        virtual void atacar() = 0;
};