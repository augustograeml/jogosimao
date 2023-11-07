#pragma once
#include "ente.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

#define TAM 25.f

class Entidade : public Ente
{
    protected:  
        sf::Texture Textura;
        sf::RenderWindow *window;

        Vector2f posicao;
        Vector2f velocidade;
        bool nochao;

    public:
        Entidade(sf::Vector2f pos = sf::Vector2f(0.f,0.f));
        ~Entidade();

        virtual void executar()=0;
        virtual void colidir();

        Vector2f getPosicao() {return corpo.getPosition();}
        Vector2f getTamanho()   {return corpo.getSize();}
        void setPosicao(Vector2f p);
        void set_nochao(bool n) {nochao = n;}
        Vector2f getVelocidade() {return velocidade;}
        void setVelocidade(Vector2f v) {velocidade = v;}

        void setWindow( sf::RenderWindow* window)   {this->window = window;} 
        void setSkin(const std::string filename);
};