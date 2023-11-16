#pragma once
#include "inimigo.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class Zumbi : public Inimigo
        {
            private:
            public:
                Zumbi(Vector2f pos = Vector2f(0.f, 0.f), Vector2f vel = Vector2f(0.f, 0.f));
                ~Zumbi();

                void mover();
                void atualizar();
                void executar();
                void atacar(Entidade* jg);
                void salvar(std::ostringstream* entrada);
        };
    }
}