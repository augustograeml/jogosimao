#pragma once
#include "../ente.hpp"
#include <SFML/Graphics.hpp>

#define TAM 50.f
#define TAM_CHEFAO 100.f

using namespace sf;

namespace Entidades
{
    class Entidade : public Ente
    {
        protected:  
            sf::Texture Textura;
            sf::RectangleShape RS;
            sf::RenderWindow *window;

            sf::Vector2f posicao;
            sf::Vector2f velocidade;
            int vida;
            bool nochao;

        public:
            Entidade(sf::Vector2f pos = sf::Vector2f(0.f,0.f));
            ~Entidade();

            void executar();
            virtual void mover() = 0;
            virtual void atualizar() = 0;
            virtual void colidir();

            Vector2f getPosicao() {return corpo.getPosition();}
            void setPosicao(Vector2f p);
            Vector2f getTamanho()   {return corpo.getSize();}
            void set_vida(int v) {vida = v;}
            int get_vida() const {return vida;}
            void set_nochao(bool n) {nochao = n;}
            Vector2f getVelocidade() {return velocidade;}
            void setVelocidade(Vector2f v) {velocidade = v;}

            void setWindow( sf::RenderWindow* window)   {this->window = window;} 
            void setSkin(const std::string filename);
    };

}