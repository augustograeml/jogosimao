#pragma once
#include "obstaculo.hpp"

class Obstaculo_Dificil : public Obstaculo
{
    private:
        int cura;
    public:
        Obstaculo_Dificil(Vector2f pos = Vector2f(0.f, 0.f));
        ~Obstaculo_Dificil();
        void executar();
        int get_cura() {return cura;}
        void mover();
        void atualizar();
};