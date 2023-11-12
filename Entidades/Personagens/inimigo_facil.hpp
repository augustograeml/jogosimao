#pragma once
#include "inimigo.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class Inimigo_Facil : public Inimigo
        {
            private:
                int vidas;
                int forca;
            public:
                Inimigo_Facil(Vector2f pos = Vector2f(0.f, 0.f), Vector2f vel = Vector2f(0.f, 0.f));
                ~Inimigo_Facil();

                void mover();
                void atualizar();
                void executar();
                void atacar(Entidade* jg);
        };
    }
}