#pragma once
#include "entidade.hpp"

class Personagem : public Entidade
{
    protected:
        int vidas;
    public:
        Personagem();
        ~Personagem();
        virtual void executar() = 0;
};