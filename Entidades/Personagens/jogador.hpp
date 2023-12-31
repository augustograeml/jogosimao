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
            bool jogador2, leu_fase;
            float poder;
            std::string nome;
            double tempo;


        public:
            Jogador(sf::Vector2f pos, sf::Vector2f vel, bool jog2);
            ~Jogador();

            void atualizar();
            void executar();
            void colidir(Entidade* pE, int a);

            void set_tempo(double x) {tempo = x;}
            double get_tempo() {return (int)tempo;}

            void set_nome(std::string a)  {nome = a;}
            string get_nome(){return nome;}

            void criar_jogadores(string arquivo, bool jogador2);
            void tela_pause();

            void mover();
            void mover_jog2();
            void atacar(Entidade* jg);
            void salvar(std::ostringstream* entrada);
            void salvar_tempo(string caminho);
           
        };

    }

}