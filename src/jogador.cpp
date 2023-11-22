#include "../Entidades/Personagens/jogador.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

namespace Entidades
{
    namespace Personagens
    {
        Gerenciadores::Gerenciador_Estados *Jogador::PGEstados(Gerenciadores::Gerenciador_Estados::get_instancia());

        Jogador::Jogador(sf::Vector2f pos, sf::Vector2f vel, bool jog2) : Personagem(pos, vel),
                                                                          tempo(0.0), poder(1), jogador2(jog2)
        {
            if (!jog2)
            {
                corpo.setFillColor(sf::Color::Green);
                this->setSkin("Design/imagens/op1.png");
            }
            else
            {
                corpo.setFillColor(sf::Color::Green);
                this->setSkin("Design/imagens/luigiDireita.png");
            }
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
            if (vida > 0)
            {
                corpo.setFillColor(sf::Color::Green);
                if (vida < 3)
                {
                    corpo.setFillColor(sf::Color::Yellow);
                }

                if (!jogador2)
                    mover();
                else
                    mover_jog2();
            }
            else
            {
                corpo.setFillColor(sf::Color::Red);
                // morreu = true;
            }

            // std::cout << get_vida() << std::endl;
        }

        void Jogador::tela_pause()
        {
        }

        void Jogador::atacar(Entidade *jg)
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !pausado)
            {
                pausado = !pausado;
                PGEstados->set_estado_atual(0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && pausado)
            {
                pausado = !pausado;
            }

            nochao = false;

            atualizar();
        }

        void Jogador::mover_jog2()
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
                velocidade.y += -6.0f;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                velocidade.y += 0.1f;

            // if(pausado == false)
            atualizar();

            nochao = false;
        }

        void Jogador::salvar(std::ostringstream *entrada)
        {
            (*entrada) << "{ \"posicao\": [" << corpo.getPosition().x << "," << corpo.getPosition().y << "], \"velocidade\": [" << velocidade.x << "," << velocidade.y << "] }" << std::endl;
        }
    }
}