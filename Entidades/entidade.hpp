//codigo reaproveitado do Peteco

#pragma once

#include "../ente.hpp"

#include <sstream>
#include <fstream>
#include <string>
#include <iostream>

#define TAM 50.f
#define TAM_CHEFAO 100.f
//tamanho da nossa flecha, la elwe
#define TAM_FLECHA 10.f

using namespace sf;

namespace Entidades
{
    class Entidade : public Ente
    {
        protected:
            bool pausado;

            sf::Texture Textura;
            sf::RectangleShape RS;
            sf::RenderWindow *window;

            sf::Vector2f posicao;
            sf::Vector2f velocidade;
            bool vivo;
            int vida;
            bool nochao;
        public:
            Entidade(sf::Vector2f pos = sf::Vector2f(0.f,0.f));
            ~Entidade();

            void executar();

            virtual void salvar(std::ostringstream* entrada){}

            virtual void mover() = 0;
            virtual void atualizar() = 0;
            virtual void colidir(Entidade* pE) = 0;

            const sf::Vector2f getPosicao() {return corpo.getPosition();}
            void setPosicao(sf::Vector2f p);
            const sf::Vector2f getTamanho()   {return corpo.getSize();}

            const bool get_pause() {return pausado;}
            void set_pausado(bool p) {pausado = p;}

            void set_vida(int v) {vida = v;}
            int get_vida() const {return vida;}

            bool get_vivo() {return vivo;}
            void set_vivo(bool a ){vivo = a;}

            void set_nochao(bool n) {nochao = n;}
            
            Vector2f getVelocidade() {return velocidade;}
            void setVelocidade(sf::Vector2f v) {velocidade = v;}

            void setWindow( sf::RenderWindow* window)   {this->window = window;} 
            void setSkin(const std::string filename);
    };

}