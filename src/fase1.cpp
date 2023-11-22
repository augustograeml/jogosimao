#include "../Estados/Fases/fase1.hpp"
#include "../Entidades/Personagens/jogador.hpp"
#include <iostream>
#include <math.h>

using namespace std;

namespace Estados
{
    namespace Fases
    {
        Fase1::Fase1(int id) : Fase(id), neve(false)
        {
            //geracao aleatoria de instancias de inimigos e obstaculos
            for(int i = 0; i < 6; i++)
                num_entidades[i] = rand()%3 + 3;

            if(id == 6)
                set_num_jogadores(2);

            /*
                0 - zumbi
                1 - arqueiro
                2 - espinhos
                3 - coracoes
                4 - caixas
                5 - gigante
            */

            std::cout << "numero de zumbis: " << num_entidades[0] << std::endl;
            std::cout << "numero de arqueiros: " << num_entidades[1] << std::endl;
            std::cout << "numero de espinhos: " << num_entidades[2] << std::endl;
            std::cout << "numero de coracoes: " << num_entidades[3] << std::endl;
            std::cout << "numero de caixas: " << num_entidades[4] << std::endl;
            std::cout << "numero de gigantes: " << num_entidades[5] << std::endl;

            Textura.loadFromFile("Design/imagens/cenario_op11.png");
            shape.setSize(Vector2f(2000.f, 1200.f));
            shape.setTexture(&Textura);
            shape.setPosition(sf::Vector2f(0.f, 0.f));

            criar_cenario(ARQUIVO_CENARIO_1, num_entidades[0], num_entidades[1], num_entidades[2], num_entidades[3],num_entidades[4], num_entidades[5], get_jaCriado());

            //a gente na teoria salva aqui
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
            
            //std::cout<<" Executadno fase 1";
            if (gC.get_sem_inimigos())
            {
                //fim_de_jogo();
                pGG->resetarCamera();
                pGE->set_estado_atual(7);
                return;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                jogadores.get_primeiro().operator*()->set_pausado(false);
            }
            if(jogadores.get_primeiro().operator*()->get_pause())
                return;
                

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

        void Fase1::pausar()
        {
        }

        void Fase1::menu()
        {
        }
    }
}