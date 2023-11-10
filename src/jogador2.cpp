#include "../Entidades/Personagens/jogador2.hpp"
#include <iostream>
using namespace std;

namespace Entidades
{
    namespace Personagens
    {
        Jogador2::Jogador2(Vector2f pos, Vector2f vel) : Personagem(pos, vel), tempo(0.0)
        {
            corpo.setFillColor(Color::Yellow);
            this->setSkin("src/imagem/luigiDireita.png");
            poder = 1;
        }
        Jogador2::~Jogador2()
        {

        }

        void Jogador2::atualizar()
        {
            corpo.setPosition(corpo.getPosition() + velocidade);
        }

        void Jogador2::executar()
        {
            if(vida != 0)
            {
                mover();
            }
            else
            {

            }
            
        }

        void Jogador2::atacar(Entidade* jg)
        {
        }

        void Jogador2::mover()
        {
            if (!nochao)            
                velocidade.y += 0.1f;

            else
                velocidade.y = 0.0f;
                    
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    velocidade.x += 0.1f;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    velocidade.x += -0.1f;   
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && nochao)
                    velocidade.y += -5.0f;    
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    velocidade.y += 0.1f;  
                //if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
                    //atacar();  
                nochao = false;

                atualizar();
        }
    }
}