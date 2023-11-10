#pragma once
#include "entidade.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class Personagem : public Entidade
        {
            protected:
                int poder;
            public:
                Personagem(Vector2f pos, Vector2f vel);
                ~Personagem();
                
                virtual void mover() = 0;
                virtual void atualizar() = 0;
                virtual void atacar(Entidade* jg) = 0;
        };
    }
}