#include "../Estados/Fases/fase1.hpp"
#include <iostream>

using namespace std;

namespace Estados
{
    namespace Fases
    {
        Fase1::Fase1() : Fase(1)
        {
            Textura.loadFromFile("src/imagem/cenario_op1.jpg");
            shape.setSize(Vector2f(950.f, 950.f));
            shape.setTexture(&Textura);
            shape.setPosition(sf::Vector2f(76.f, -10.f));

            criar_cenario(ARQUIVO_CENARIO_1);

            /*criar_jogadores(1);
            criar_jogadores(0);
            criar_inimigos();*/
        }

        Fase1::~Fase1()
        {
        }

        void Fase1::fim_de_jogo()
        {
            Textura.loadFromFile("src/imagem/fim_de_jogo1.jpeg");
            shape.setSize(Vector2f(950.f, 950.f));
            shape.setTexture(&Textura);
            shape.setPosition(sf::Vector2f(76.f, -10.f));
            pGG->desenharFundo(&shape);
        }

        void Fase1::executar()
        {

            if (gC.get_sem_inimigos())
            {
                fim_de_jogo();
                return;
            }

            jogadores.executar();
            inimigos.executar();
            gerenciar_colisoes();
            //pGG->centralizarCamera((*(jogadores.get_primeiro()))->getPosicao() /*+ (*(jogadores.get_primeiro()++))->getPosicao())/2.f*/);
            pGG->desenharFundo(&shape);
            obstaculos.desenhar();
            jogadores.desenhar();
            inimigos.desenhar();
        }

        void Fase1::mover()
        {
        }

        void Fase1::atualizar()
        {
        }
    }
}