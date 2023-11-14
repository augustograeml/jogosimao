#pragma once
#include "inimigo.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class Inimigo_Dificil : public Inimigo
        {
            private:
                int forca;
            public:
                Inimigo_Dificil(Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f));
                ~Inimigo_Dificil();

                void executar();
                void mover();
                void atualizar();
                void atacar(Entidade* jg);
                void salvar(std::ostringstream* entrada);
        };
    }
}