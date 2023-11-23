#include "../Entidades/Obstaculos/caixa.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Caixa::Caixa(sf::Vector2f pos) : Obstaculo(pos, false, false, true, false, false), atrapalha(false)
        {
            int i = rand()%10;
            if(i == 2)
                atrapalha = true;

            //se o jogador pular em cima da caixa e ela for fragil ela quebra

            this->setSkin("Design/imagens/caixa.png");
            this->set_vida(20);
        }

        Caixa::~Caixa()
        {

        }

        void Caixa::executar()
        {
            
        }

        void Caixa::mover()
        {
            
        }

        void Caixa::criar_caixas(string arquivo)
        {
            ifstream caminho(arquivo);

            if (!caminho)
            {
                cout << "Nao foi possivel acessar o arquivo de criacao dos arqueiros";
                exit(1);
            }

            string linha;
            Entidade* aux = nullptr;
            int j, i;

            for(i = 0; getline(caminho, linha); i++)
            {
                j = 0;
                for(char tipo : linha)
                {
                    switch(tipo)
                    {
                        case '8':
                            aux = static_cast<Entidade*>(new Caixa(sf::Vector2f(0.f, 0.f)));
                            if(aux)
                            {
                                //incluir obstaculos na lista
                            }
                            break;

                        default:
                            break;;
                    }
                }
            }
        }

        void Caixa::atualizar()
        {
            
        }
        void Caixa::colidir(Entidade* pE, int a)
        {
            
        }
    }
}