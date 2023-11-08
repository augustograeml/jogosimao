#pragma once
#include "inimigo.hpp"

class Inimigo_Dificil : public Inimigo
{
    private:
        int vidas;
        int forca;

    public:
        Inimigo_Dificil(Vector2f pos, Vector2f vel);
        ~Inimigo_Dificil();

        void executar();
        void mover();
        void atualizar();
        void atacar();
};