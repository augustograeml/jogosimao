#pragma once
#include "inimigo.hpp"

class Inimigo_Facil : public Inimigo
{
    private:
        int vidas;
        float velocidade;
        int forca;

    public:
        Inimigo_Facil();
        ~Inimigo_Facil();
        void executar();
        void atacar();
};