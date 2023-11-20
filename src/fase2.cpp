#include "../Estados/Fases/fase2.hpp"

namespace Estados
{
    namespace Fases
    {
        Fase2::Fase2() : Fase(3), musgos(false)
        {
            int i = rand() % 10;
            if (i == 3)
                musgos = true;

            num_zumbi = rand()%3 + 3;
            num_arqueiro = rand()%3 + 3;
            num_espinhos = rand()%3 + 3;
            num_coracoes = rand()%3 + 3;
            set_num_jogadores(2);

            Textura.loadFromFile("Design/imagens/cenario_op22.png");
            shape.setSize(Vector2f(2000.f, 1200.f));
            shape.setTexture(&Textura);
            shape.setPosition(sf::Vector2f(0.f, 0.f));

            criar_cenario(ARQUIVO_CENARIO_2,2,2,2,2,2);
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
                pGG->resetarCamera();
                fim_de_jogo();
                return;
            }

            if(get_musgos());



            jogadores.executar();
            inimigos.executar();
            gerenciar_colisoes();
            if(num_jogadores == 2)
                 pGG->centralizarCamera((*(jogadores.get_primeiro()))->getPosicao() /*+ (*(jogadores.get_primeiro()++))->getPosicao())/2.f*/);
            else
                pGG->centralizarCamera((*(jogadores.get_primeiro()))->getPosicao());
            pGG->desenharFundo(&shape);
            obstaculos.desenhar();
            jogadores.desenhar();
            inimigos.desenhar();
        }

        void Fase2::atualizar()
        {
        }

        bool Fase2::get_musgos()
        {
            return musgos;
        }

        void Fase2::pausar()
        {
        }
        
        void Fase2::menu()
        {
        }
    }
}