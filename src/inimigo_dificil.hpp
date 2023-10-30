#pragma once
#include "inimigo.hpp"

class Inimigo_Dificil : public Inimigo
{
    private:
        int vidas;
        float velocidade;
        int forca;

    public:
        Inimigo_Dificil();
        ~Inimigo_Dificil();
        void executar();
};