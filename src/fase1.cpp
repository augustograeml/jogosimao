#include "../Estados/Fases/fase1.hpp"
#include <iostream>
#include <math.h>

using namespace std;

namespace Estados
{
    namespace Fases
    {
        Fase1::Fase1() : Fase(1), neve(false)
        {
            if(get_neve())
            {

            }
            //geracao aleatoria de instancias de inimigos e obstaculos
            num_zumbi = rand()%3 + 3;
            num_arqueiro = rand()%3 + 3;
            num_espinhos = rand()%3 + 3;
            num_coracoes = rand()%3 + 3;
            std::cout << "numero de zumbis: " << num_zumbi << std::endl;
            std::cout << "numero de arqueiros: " << num_arqueiro << std::endl;
            std::cout << "numero de espinhos: " << num_espinhos << std::endl;
            std::cout << "numero de coracoes: " << num_coracoes << std::endl;

            //if(get_jogador) jogador2 = true

            Textura.loadFromFile("Design/imagens/cenario_op11.png");
            shape.setSize(Vector2f(2000.f, 1200.f));
            shape.setTexture(&Textura);
            shape.setPosition(sf::Vector2f(0.f, 0.f));


            criar_cenario(ARQUIVO_CENARIO_1, num_zumbi, num_arqueiro, num_espinhos, num_coracoes,0);

            /*criar_jogadores(1);
            criar_jogadores(0);
            criar_inimigos();*/

        }

        Fase1::~Fase1()
        {
            salvar();
        }

        void Fase1::fim_de_jogo()
        {
            Textura.loadFromFile("Design/imagens/fim_de_jogo2.jpeg");
            shape.setSize(Vector2f(950.f, 950.f));
            shape.setTexture(&Textura);
            shape.setPosition(sf::Vector2f(76.f, -10.f));
            pGG->desenharFundo(&shape);
           //escrita_tempo.setString("GAME OVER!");
            
        }

        bool Fase1::get_neve()
        {
            return neve;
        }

        //colocar bool pra executar direitin quando tiver dois jogadores
        void Fase1::executar()
        {
            if (gC.get_sem_inimigos())
            {
                fim_de_jogo();
                pGE->set_estado_atual(2);
                return;
            }

            jogadores.executar();
            inimigos.executar();
            gerenciar_colisoes();
            //if(jogador2)
            pGG->centralizarCamera(Vector2f((*(jogadores.get_primeiro()))->getPosicao() + (*(jogadores.get_primeiro()++))->getPosicao())/2.f);
            //else - fica sem nada
            pGG->desenharFundo(&shape);
            obstaculos.desenhar();
            jogadores.desenhar();
            inimigos.desenhar();
        }

        void Fase1::atualizar()
        {
        }

        void Fase1::pausar()
        {
        }

        void Fase1::menu()
        {
        }
    }
}