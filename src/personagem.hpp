#pragma once
#include "entidade.hpp"

class Personagem : public Entidade
{
    protected:
        int vidas;
    public:
        Personagem(Vector2f pos, Vector2f vel);
        ~Personagem();
        virtual void executar() = 0;
};