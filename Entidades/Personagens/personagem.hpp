#pragma once
#include "../entidade.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class Personagem : public Entidade
        {
            protected:
                int forca;
                
            public:
                Personagem(sf::Vector2f pos, sf::Vector2f vel);
                ~Personagem();
                
                virtual void mover() = 0;
                virtual void atualizar() = 0;
                virtual void atacar(Entidade* jg) = 0;
        };
    }
}