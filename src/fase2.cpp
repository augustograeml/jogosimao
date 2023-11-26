#include "../Estados/Fases/fase2.hpp"
#include "../Entidades/Personagens/jogador.hpp"
#define ARQUIVO_OUTPUT_FASE_2 "Design/imagens/rankingfase2.txt"

namespace Entidades
{
    namespace Personagens
    {
        class Jogador;
    }
}

namespace Estados
{
    namespace Fases
    {
        Fase2::Fase2(int id, bool ja) : Fase(id, ja), musgos(false)
        {
            if (id == 9)
            {
                set_num_jogadores(2);
                jogador2 = false;
            }

            /*for (int i = 0; i < 3; i++)
                num_obstaculos[i] = rand() % 3 + 3;*/

            /*
                0 - zumbi
                1 - arqueiro
                2 - espinhos
                3 - coracoes
                4 - caixas
                5 - gigante
            */
            // set_num_jogadores(2);

            Textura.loadFromFile("Design/imagens/cenario_op22.png");
            shape.setSize(Vector2f(2000.f, 1200.f));
            shape.setTexture(&Textura);
            shape.setScale(Vector2f(1.2f, 1.0f));
            shape.setPosition(sf::Vector2f(0.f, 0.f));

            criar_cenario(ARQUIVO_CENARIO_2/*, num_obstaculos[0], num_obstaculos[1], num_obstaculos[2]*/);
            if (!ja_criado)
                criar_inimigos(ARQUIVO_CENARIO_2);
        }

        Fase2::~Fase2()
        {
        }

        void Fase2::fim_de_jogo()
        {
            set_tempo_jogadores();
            Textura.loadFromFile("Design/imagens/fim_de_jogo3.jpeg");
            shape.setSize(Vector2f(950.f, 950.f));
            shape.setTexture(&Textura);
            shape.setPosition(sf::Vector2f(76.f, -10.f));
            pGG->desenharFundo(&shape);
             Entidades::Personagens::Jogador* jog = static_cast<Entidades::Personagens::Jogador*> (*jogadores.get_primeiro());  
            jog->salvar_tempo(ARQUIVO_OUTPUT_FASE_2);
            if(num_jogadores == 2)
            {
            Entidades::Personagens::Jogador* jogad22 = static_cast<Entidades::Personagens::Jogador*> (*jogadores.get_primeiro()++);  
            jogad22->salvar_tempo(ARQUIVO_OUTPUT_FASE_2);
            }
        }

        void Fase2::executar()
        {
            if (gC.get_inimigos_vivos())
            {
                pGG->limpar();
                pGG->resetarCamera();
                // ranking, acho que se pa esse fim_de_jogo é meio inutil
                // fim_de_jogo();
                return;
            }

            if (gC.get_jogadores_vivos())
            {
                pGG->limpar();
                pGG->resetarCamera();
                pGE->set_estado_atual(0);
                return;
            }

            pGE->get_fase();

            pGG->desenharFundo(&shape);
            jogadores.executar();
            inimigos.executar();
            gerenciar_colisoes();

            atualizar();

            obstaculos.desenhar();
            jogadores.desenhar();
            inimigos.desenhar();
        }

        void Fase2::atualizar()
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

        bool Fase2::get_musgos()
        {
            return musgos;
        }
    }
}