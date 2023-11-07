#pragma once
#include "inimigo.hpp"

class Inimigo_Dificil : public Inimigo
{
    private:
        int vidas;
        float velocidade;
        int forca;

    public:
        Inimigo_Dificil(Vector2f pos, Vector2f vel);
        ~Inimigo_Dificil();
};