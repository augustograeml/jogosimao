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
                bool maldade;
                bool direcao;
                    
            public:
                Inimigo(sf::Vector2f pos, sf::Vector2f vel);
                ~Inimigo();
                sf::Vector2f getPosicao();
                void setPosicao(sf::Vector2f& p);
                void update(sf::Vector2f& posicao_jogador);
                void mudar_direcao();

                virtual void atualizar() = 0;
                virtual void mover() = 0;
                virtual std::vector<Projetil>* get_projeteis() {return nullptr;}
                virtual void executar() = 0;
                virtual void colidir(Entidade* pE, int a) = 0;
                virtual void atacar(Entidade* jg) = 0;
            };
        }
}