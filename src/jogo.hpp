#pragma once
#include <SFML/Graphics.hpp>
#include "jogador.hpp"
#include "inimigo.hpp"

class Jogo
{
    private:
        sf::RenderWindow window;
        Jogador jogador1;
        Inimigo inimigo1;
        
    public:
        Jogo();
        ~Jogo();

        void Executar();
};