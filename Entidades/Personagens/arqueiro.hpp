#pragma once
#include "inimigo.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class Arqueiro : public Inimigo
        {
            private:
                int forca;
            public:
                Arqueiro(Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f));
                ~Arqueiro();

                void executar();
                void mover();
                void atualizar();
                void atacar(Entidade* jg);
                void salvar(std::ostringstream* entrada);
        };
    }
}