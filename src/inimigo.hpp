#pragma once
#include "entidade.hpp"
#include "jogador.hpp"

class Inimigo : public Personagem
{
    protected:
        sf::Vector2f posicao;
        Jogador* pjogador;
        bool maldade;
        
    public:
        Inimigo(Vector2f pos, Vector2f vel);
        ~Inimigo();
        sf::Vector2f getPosicao();
        void setPosicao(sf::Vector2f& p);
        void update(sf::Vector2f& posicao_jogador);

        virtual void atualizar() = 0;
        virtual void mover() = 0;
        virtual void executar() = 0;
};