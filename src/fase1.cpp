#include "../Estados/Fases/fase1.hpp"
#include "../Entidades/Personagens/jogador.hpp"
#define ARQUIVO_OUTPUT "Design/txts/ranking.txt"
#include <iostream>
#include <math.h>

using namespace std;

namespace Estados
{
    namespace Fases
    {
        Fase1::Fase1(int id) : Fase(id), neve(false)
        {
            identidade = id;
            //geracao aleatoria de instancias de inimigos e obstaculos
            for(int i = 0; i < 6; i++)
                num_entidades[i] = rand()%3 + 3;

            if(id == 7)
                set_num_jogadores(2);

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

            criar_cenario(ARQUIVO_CENARIO_1, num_entidades[0], num_entidades[1], num_entidades[2], num_entidades[3],num_entidades[4], num_entidades[5], get_jaCriado());
        }

        Fase1::~Fase1()
        {
            salvar();
        }

        void Fase1::fim_de_jogo()
        {
            getNome();
            pontuar();
            Entidades::Personagens::Jogador* jog = static_cast<Entidades::Personagens::Jogador*> (*jogadores.get_primeiro());  
            jog->set_nome(playerName);
            jog->salvar_tempo(ARQUIVO_OUTPUT);
            if(num_jogadores == 2)
            {
            Entidades::Personagens::Jogador* jogad22 = static_cast<Entidades::Personagens::Jogador*> (*jogadores.get_primeiro()++);  
            jogad22->set_nome(playerName + "(2)");
            jogad22->salvar_tempo(ARQUIVO_OUTPUT);
            }
            set_pontos(0);
        }

        bool Fase1::get_neve()
        {
            return neve;
        }

        //colocar bool pra executar direitin quando tiver dois jogadores
        void Fase1::executar()
        {
            
            pGG->desenharFundo(&shape);
            obstaculos.desenhar();
            jogadores.desenhar();
            inimigos.desenhar();
            projeteis.desenhar();
            
            //fase 2 pra dois jogadores
            if (gC.get_inimigos_vivos() && identidade == 7)
            {
                pGG->resetarCamera();
                pGE->set_estado_atual(9);
                return;
            }
            //fase 2 pra um jogadores
            else if (gC.get_inimigos_vivos() && identidade == 6)
            {
               
                pGG->resetarCamera();
                pGE->set_estado_atual(8);
                return;
            }
            if(gC.get_jogadores_vivos())
            {
                fim_de_jogo();
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
            if(num_jogadores == 2)
            {
                Entidades::Personagens::Jogador* aux = static_cast<Entidades::Personagens::Jogador*> (*(jogadores.get_primeiro()));
                Entidades::Personagens::Jogador* aux1 = static_cast<Entidades::Personagens::Jogador*> (*(jogadores.get_primeiro()++));
                //if(jogador2)
                if(num_jogadores == 2 && aux->get_vida() && aux1->get_vida())
                    pGG->centralizarCamera(Vector2f((*(jogadores.get_primeiro()))->getPosicao() + (*(jogadores.get_primeiro()++))->getPosicao())/2.f);
                if(aux->get_vida() && !aux1->get_vida())
                    pGG->centralizarCamera((*(jogadores.get_primeiro()))->getPosicao());
                if(!aux->get_vida() && aux1->get_vida())
                    pGG->centralizarCamera((*(jogadores.get_primeiro()++))->getPosicao());
            }
            else
                pGG->centralizarCamera((*(jogadores.get_primeiro()))->getPosicao());  
        }
    }
}