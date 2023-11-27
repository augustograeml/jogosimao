#pragma once
#include "../entidade.hpp"
#include "../projetil.hpp"
#include "jogador.hpp"  

namespace Entidades
{ 
    namespace Personagens
    {
        class Inimigo : public Personagem
        {
            protected:
                Jogador* pjogador;
                bool direcao;
                int pontos_cedidos;
                    
            public:
                Inimigo(sf::Vector2f pos, sf::Vector2f vel);
                ~Inimigo();
                sf::Vector2f getPosicao();
                void setPosicao(sf::Vector2f& p);
                void update(sf::Vector2f& posicao_jogador);
                void mudar_direcao();

                int get_pontos_cedidos() {return pontos_cedidos;}
                void set_pontos_cedidos(int a) {pontos_cedidos =  a;}

                virtual void atualizar() = 0;
                virtual void mover() = 0;
                virtual std::vector<Projetil>* get_projeteis() {return nullptr;}
                virtual void executar() = 0;
                virtual void colidir(Entidade* pE, int a) = 0;
                virtual void atacar(Entidade* jg) = 0;
            };
        }
}