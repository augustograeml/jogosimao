#pragma once
#include "entidade.hpp"
#include "jogador.hpp"

class Inimigo : public Entidade
{
    private:
        sf::Vector2f posicao;
        bool maldade;
        int vida;
        Jogador* pjogador;
        

    public:
        Inimigo();
        ~Inimigo();
        sf::Vector2f getPosicao();
        virtual void executar();
        void setPosicao(sf::Vector2f& p);
        void update(sf::Vector2f& posicao_jogador);
        virtual void executar();
};