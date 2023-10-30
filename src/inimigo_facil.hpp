#pragma once
#include "inimigo.hpp"

class Inimigo_Facil : public Inimigo
{
    private:
        int vidas;
        float velocidade;
        float forca;
    public:
        Inimigo_Facil();
        ~Inimigo_Facil();
        void executar();
};