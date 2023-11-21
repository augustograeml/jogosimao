#include "../Estados/Fases/fase2.hpp"
#include "../Entidades/Personagens/jogador.hpp"

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
        Fase2::Fase2(int id) : Fase(id), musgos(false)
        {
            int i = rand() % 10;
            if (i == 3)
                musgos = true;

            if(id == 7)
                set_num_jogadores(2);


            for(int i = 0; i < 5; i++)
                num_entidades[i] = rand()%3 + 3;
            num_entidades[5] = rand()%3 + 1;

            /*
                0 - zumbi
                1 - arqueiro
                2 - espinhos
                3 - coracoes
                4 - caixas
                5 - gigante
            */
            //set_num_jogadores(2);

            Textura.loadFromFile("Design/imagens/cenario_op22.png");
            shape.setSize(Vector2f(2000.f, 1200.f));
            shape.setTexture(&Textura);
            shape.setPosition(sf::Vector2f(0.f, 0.f));

            criar_cenario(ARQUIVO_CENARIO_2,num_entidades[0],num_entidades[1],num_entidades[2],num_entidades[3],num_entidades[4],num_entidades[5], get_jaCriado());
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
            if (gC.get_sem_inimigos())
            {
                pGG->resetarCamera();
                fim_de_jogo();
                return;
            }

            jogadores.executar();
            inimigos.executar();
            gerenciar_colisoes();

            atualizar();
           
            pGG->desenharFundo(&shape);
            obstaculos.desenhar();
            jogadores.desenhar();
            inimigos.desenhar();
        }

        void Fase2::atualizar()
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