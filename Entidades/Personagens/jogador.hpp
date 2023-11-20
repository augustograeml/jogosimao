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
            bool jogador2;
            float poder;
            std::string nome;
            double tempo;

        public:
            Jogador(sf::Vector2f pos, sf::Vector2f vel, bool jog2);
            ~Jogador();

            void atualizar();
            void executar();
            void mover();
            void mover_jog2();
            void atacar(Entidade* jg);
            void salvar(std::ostringstream* entrada);
        };

    }

}