#pragma once
#include <SFML/Graphics.hpp>

class Entidade
{
    protected:
        sf::RectangleShape corpo;
        sf::RenderWindow *window;

    public:
        Entidade();
        ~Entidade();

};