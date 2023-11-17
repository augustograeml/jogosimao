#include "../Estados/Fases/fase2.hpp"

namespace Estados
{
    namespace Fases
    {
        Fase2::Fase2() : Fase(2), musgos(false)
        {
            int i = rand() % 10;
            if (i == 3)
                musgos = true;

            Textura.loadFromFile("Design/imagens/cenario_fase2.jpeg");
            shape.setSize(Vector2f(950.f, 950.f));
            shape.setTexture(&Textura);
            shape.setPosition(sf::Vector2f(76.f, -10.f));

            criar_cenario(ARQUIVO_CENARIO_2);
        }

        Fase2::~Fase2()
        {
            salvar();
        }

        void Fase2::fim_de_jogo()
        {
            Textura.loadFromFile("Design/imagens/fim_de_jogo3.jpeg");
            shape.setSize(Vector2f(950.f, 950.f));
            shape.setTexture(&Textura);
            shape.setPosition(sf::Vector2f(76.f, -10.f));
            pGG->desenharFundo(&shape);
        }

        void Fase2::executar()
        {
            // cout << "palmeiras tem mundial sim" << endl;

            if (gC.get_sem_inimigos())
            {
                fim_de_jogo();
                return;
            }

            if(get_musgos())



            jogadores.executar();
            inimigos.executar();
            gerenciar_colisoes();
            // pGG->centralizarCamera((*(jogadores.get_primeiro()))->getPosicao() /*+ (*(jogadores.get_primeiro()++))->getPosicao())/2.f*/);
            pGG->desenharFundo(&shape);
            obstaculos.desenhar();
            jogadores.desenhar();
            inimigos.desenhar();
        }

        void Fase2::mover()
        {
        }

        void Fase2::atualizar()
        {
        }

        bool Fase2::get_musgos()
        {
            return musgos;
        }
    }
}