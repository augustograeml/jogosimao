#pragma once
#include <SFML/Graphics.hpp>

class Entidade
{
    protected:
        sf::RectangleShape corpo;
        sf::Texture Textura;
        sf::RenderWindow *window;

    public:
        Entidade();
        ~Entidade();

        void setWindow( sf::RenderWindow* window)   {this->window = window;} 
        void setSkin(const std::string filename);
        sf::RectangleShape getCorpo() {return corpo;}
        void draw(){window->draw(corpo);}
};