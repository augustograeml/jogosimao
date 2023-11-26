#include "../Estados/Fases/fase1.hpp"
#include "../Entidades/Personagens/jogador.hpp"
#define ARQUIVO_OUTPUT_FASE_1 "Design/imagens/rankingfase1.txt"
#include <iostream>
#include <math.h>

using namespace std;

namespace Estados
{
    namespace Fases
    {
        Fase1::Fase1(int id, bool ja) : Fase(id, ja), neve(false)
        {
            identidade = id;
            // geracao aleatoria de instancias de inimigos e obstaculos
            /*for (int i = 0; i < 3; i++)
                num_obstaculos[i] = rand() % 3 + 3;*/

            if (id == 7)
            {
                set_num_jogadores(2);
                jogador2 = true;
            }

            /*
                0 - zumbi
                1 - arqueiro
                2 - espinhos
                3 - coracoes
                4 - caixas
                5 - gigante
            */
            Textura.loadFromFile("Design/imagens/cenario_op11.png");
            shape.setSize(Vector2f(2000.f, 1200.f));
            shape.setTexture(&Textura);
            shape.setPosition(sf::Vector2f(0.f, 0.f));

            criar_cenario(ARQUIVO_CENARIO_1/*, num_obstaculos[0], num_obstaculos[1], num_obstaculos[2]*/);

            if (!ja_criado)
                criar_inimigos(ARQUIVO_CENARIO_1);

            tempo_inicio = clock();
        }

        Fase1::~Fase1()
        {
        }

        void Fase1::fim_de_jogo()
        {
            set_tempo_jogadores();
            Textura.loadFromFile("Design/imagens/fim_de_jogo2.jpeg");
            shape.setSize(Vector2f(950.f, 950.f));
            shape.setTexture(&Textura);
            shape.setPosition(sf::Vector2f(76.f, -10.f));
            pGG->desenharFundo(&shape);
            Entidades::Personagens::Jogador *jog = static_cast<Entidades::Personagens::Jogador *>(*jogadores.get_primeiro());
            jog->salvar_tempo(ARQUIVO_OUTPUT_FASE_1);
            if(num_jogadores == 2)
            {
                Entidades::Personagens::Jogador* jogad22 = static_cast<Entidades::Personagens::Jogador*> (*jogadores.get_primeiro()++);  
            jogad22->salvar_tempo(ARQUIVO_OUTPUT_FASE_1);
            }

              
        }

        bool Fase1::get_neve()
        {
            return neve;
        }

        // colocar bool pra executar direitin quando tiver dois jogadores
        void Fase1::executar()
        {

            pGG->desenharFundo(&shape);
            obstaculos.desenhar();
            jogadores.desenhar();
            inimigos.desenhar();

            // fase 2 pra dois jogadores
            if (gC.get_inimigos_vivos() && identidade == 7)
            {
                pGG->resetarCamera();
                pGE->set_estado_atual(9);
                return;
            }
            // fase 2 pra um jogadores
            else if (gC.get_inimigos_vivos() && identidade == 6)
            {
                fim_de_jogo();
                clock_t tempo_final = clock();

                Entidades::Personagens::Jogador *jog = static_cast<Entidades::Personagens::Jogador *>(*jogadores.get_primeiro());
                jog->set_tempo((tempo_final - tempo_inicio) / CLOCKS_PER_SEC);

                if (num_jogadores == 2)
                {
                    Entidades::Personagens::Jogador *jog2 = static_cast<Entidades::Personagens::Jogador *>(*jogadores.get_primeiro()++);
                    jog2->set_tempo((tempo_final - tempo_inicio) / CLOCKS_PER_SEC);
                }
                pGG->resetarCamera();
                pGE->set_estado_atual(10);

                return;
            }

            // verifica se os jogadores tao vivos e se n tiverem eles entram no loop e voltam pro menu inicial
            if (gC.get_jogadores_vivos())
            {
                pGG->limpar();
                pGG->resetarCamera();
                pGE->set_estado_atual(0);
                return;
            }

            jogadores.executar();
            inimigos.executar();
            gerenciar_colisoes();

            atualizar();
        }

        void Fase1::atualizar()
        {
            if (num_jogadores == 2)
            {
                Entidades::Personagens::Jogador *aux = static_cast<Entidades::Personagens::Jogador *>(*(jogadores.get_primeiro()));
                Entidades::Personagens::Jogador *aux1 = static_cast<Entidades::Personagens::Jogador *>(*(jogadores.get_primeiro()++));
                // if(jogador2)
                if (num_jogadores == 2 && aux->get_vida() && aux1->get_vida())
                    pGG->centralizarCamera(Vector2f((*(jogadores.get_primeiro()))->getPosicao() + (*(jogadores.get_primeiro()++))->getPosicao()) / 2.f);
                if (aux->get_vida() && !aux1->get_vida())
                    pGG->centralizarCamera((*(jogadores.get_primeiro()))->getPosicao());
                if (!aux->get_vida() && aux1->get_vida())
                    pGG->centralizarCamera((*(jogadores.get_primeiro()++))->getPosicao());
            }
            else
                pGG->centralizarCamera((*(jogadores.get_primeiro()))->getPosicao());
        }
    }
}