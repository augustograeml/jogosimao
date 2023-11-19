#pragma once
#include "inimigo.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class Gigante : public Inimigo
        {
            private:
                bool maldade, ja_inc;
            public:
                Gigante(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f));
                ~Gigante();

                void executar();
                void mover();
                void atualizar();
                void atacar(Entidade* jg);
                void salvar(std::ostringstream* entrada);
        };
    }
}