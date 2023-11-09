#pragma once
#include "inimigo.hpp"

using namespace Entidades;
using namespace Entidades;

namespace Entidade
{
    namespace Personagens
    {
        class Inimigo_Dificil : public Inimigo
        {
            private:
                int forca;

            public:
                Inimigo_Dificil(Vector2f pos, Vector2f vel);
                ~Inimigo_Dificil();

                void executar();
                void mover();
                void atualizar();
                void atacar(Entidade* jg);
        };
    }
}