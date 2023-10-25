#include <SFML/Graphics.hpp>
#pragma once
#include "jogador.hpp"

class Jogo
{
    private:
        sf::RenderWindow window;
        Jogador jogador1;
        
    public:
        Jogo();
        ~Jogo();

        void Executar();
};