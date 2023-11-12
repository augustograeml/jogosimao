#include "../Entidades/Personagens/jogador.hpp"
#include <iostream>
using namespace std;

namespace Entidades
{
    namespace Personagens
    {
        Jogador::Jogador(sf::Vector2f pos, sf::Vector2f vel) : Personagem(pos, vel), tempo(0.0)
        {
            corpo.setFillColor(sf::Color::Green);
            this->setSkin("src/imagem/op1.png");
            poder  = 1;
        }
        Jogador::~Jogador()
        {

        }

        void Jogador::atualizar()
        {
            corpo.setPosition(corpo.getPosition() + velocidade);
        }

        void Jogador::executar()
        {
            if(vida != 0)
            {
                if (vida < 2)
                {
                    corpo.setFillColor(sf::Color::Yellow);
                }
                mover();
            }
        else
        {
            corpo.setFillColor(sf::Color::Red);
            //morreu = true;
        }

        
        }

        void Jogador::atacar(Entidade* jg)
        {
        }

        void Jogador::mover()
        {
            if (!nochao)            
                velocidade.y += 0.1f;

            else
                velocidade.y = 0.0f;
                    
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    velocidade.x += 0.1f;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    velocidade.x += -0.1f;   
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && nochao)
                    velocidade.y += -6.0f;    
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    velocidade.y += 0.1f;  
                //if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
                    //atacar();  
                nochao = false;

                atualizar();
        }
    }
}