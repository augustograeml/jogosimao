#include "../Entidades/Obstaculos/coracao.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Coracao::Coracao(sf::Vector2f pos): Obstaculo(pos,false, true, false,false,false), cura(5)
        {
            this->setSkin("Design/imagens/saude.png");
            //this->set_vida(40);
        }

        Coracao::~Coracao()
        {

        }

        void Coracao::executar()
        {
            
        }

        void Coracao::mover()
        {
            
        }

        void Coracao::atualizar()
        {
            
        }

        void Coracao::criar_coracao(string arquivo)
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
                        case '6':
                            aux = static_cast<Entidade*>(new Coracao(sf::Vector2f(0.f, 0.f)));
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

        void Coracao::curar(Entidades::Personagens::Jogador* pJ)
        {
            pJ->set_vida(cura);
        }

        void Coracao::colidir(Entidade* pE)
        {
            
        }
    }
}