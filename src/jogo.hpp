#include <SFML/Graphics.hpp>
#pragma once

class Jogo
{
    private:
        sf::RenderWindow window;
        sf::RectangleShape shape;
        sf::RectangleShape shape2;
        sf::Texture texturaPersonagem;
        sf::Texture texturaPersonagem2;
    public:
        Jogo();
        void Executar();
};