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
            RS.setSize(Vector2f(950.f, 950.f));
            RS.setTexture(&Textura);
            RS.setPosition(sf::Vector2f(76.f,-10.f));
            criar_cenario(ARQUIVO_CENARIO_1);
        }

        Fase1::~Fase1()
        {

        } 

        void Fase1::executar()
        {
            jogadores.executar();
            inimigos.executar();
            gerenciar_colisoes();
            //pGG->centralizarCamera((*(jogadores.get_primeiro()))->getPosicao() /*+ (*(jogadores.get_primeiro()++))->getPosicao())/2.f*/);
            obstaculos.desenhar();
            pGG->desenharFundo(&RS);
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