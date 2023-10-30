#pragma once
#include "entidade.hpp"
#include "jogador.hpp"

class Inimigo : public Entidade
{
    protected:
        sf::Vector2f posicao;
        int vida;
        Jogador* pjogador;
        
    private:
        bool maldade;
        
    public:
        Inimigo();
        ~Inimigo();
        sf::Vector2f getPosicao();
        void setPosicao(sf::Vector2f& p);
        void update(sf::Vector2f& posicao_jogador);
        virtual void executar();
};