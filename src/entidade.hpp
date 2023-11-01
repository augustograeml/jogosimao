#pragma once
#include <SFML/Graphics.hpp>

class Entidade
{
    protected:
        sf::RectangleShape corpo;
        sf::Texture Textura;
        sf::RenderWindow *window;

    public:
        Entidade(sf::Vector2f pos = sf::Vector2f(100.f,100.f));
        ~Entidade();

        virtual void executar() {}
        virtual void colidir() {}

        void setWindow( sf::RenderWindow* window)   {this->window = window;} 
        void setSkin(const std::string filename);
        sf::RectangleShape getCorpo() {return corpo;}
        sf::Vector2f getPosicao();
        void draw(){window->draw(corpo);}
};