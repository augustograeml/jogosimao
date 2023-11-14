#pragma once
#include <SFML/Graphics.hpp>
#include "personagem.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class Jogador : public Personagem
        {

        protected:
            float poder;
            double tempo;

        public:
            Jogador(sf::Vector2f pos, sf::Vector2f vel);
            ~Jogador();

            void atualizar();
            void executar();
            void mover(); 
            void atacar(Entidade* jg);
            void salvar(std::ostringstream* entrada);
        };

    }

}