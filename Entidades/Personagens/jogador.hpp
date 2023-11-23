#pragma once
#include <SFML/Graphics.hpp>
#include "personagem.hpp"
#include "../../Gerenciadores/gerenciador_estados.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class Jogador : public Personagem
        {
        protected:
            static Gerenciadores::Gerenciador_Estados* PGEstados;
            bool jogador2;
            float poder;
            std::string nome;
            double tempo;


        public:
            Jogador(sf::Vector2f pos, sf::Vector2f vel, bool jog2);
            ~Jogador();

            void atualizar();
            void executar();
            void colidir(Entidade* pE);
            
            void set_tempo(double x) {tempo = x;}
            double get_tempo() {return tempo;}

            void tela_pause();

            void mover();
            void mover_jog2();
            void atacar(Entidade* jg);
            void salvar(std::ostringstream* entrada);
           
        };

    }

}