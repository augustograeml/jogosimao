#pragma once
#include <SFML/Graphics.hpp>
#include "personagem.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class Jogador2 : public Personagem
        {

        protected:
            //contador pro tempo
            double tempo;

        public:
            Jogador2(sf::Vector2f pos, sf::Vector2f vel);
            ~Jogador2();

            void atualizar();
            void executar();
            void mover(); 
            void atacar(Entidade* jg);
            void salvar(std::ostringstream* entrada);
        };
    }
}