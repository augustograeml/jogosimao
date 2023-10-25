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

        void setWindow( sf::RenderWindow* window){this->window = window;} 
        void draw(){window->draw(corpo);}

};