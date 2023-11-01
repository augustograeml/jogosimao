#pragma once
#include "entidade.hpp"
using namespace sf;

class Obstaculo : public Entidade
{
    private:
        bool danoso;
    public:
        Obstaculo(Vector2f pos = Vector2f(0.f, 0.f), bool dano = false);
        ~Obstaculo();
        virtual void executar() = 0;
};