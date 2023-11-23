#include "../Entidades/Obstaculos/espinho.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Espinho::Espinho(sf::Vector2f pos) : Obstaculo(pos, true, false ,false,false,false), dano(5)
        {
            this->setSkin("Design/imagens/espinho.png");
            this->set_vida(55);
        }

        Espinho::~Espinho()
        {

        }

        void Espinho::executar()
        {

        }

        void Espinho::mover()
        {

        }

        void Espinho::criar_espinhos(string arquivo)
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
                        case '5':
                            aux = static_cast<Entidade*>(new Espinho(sf::Vector2f(0.f, 0.f)));
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

        void Espinho::atualizar()
        {

        }
        void Espinho::espinhar(Entidades::Personagens::Jogador* pJ)
        {
            pJ->set_vida(pJ->get_vida() - get_dano());
        }
        void Espinho::colidir(Entidade* pE, int a)
        {
            Entidades::Personagens::Jogador* aux = static_cast<Entidades::Personagens::Jogador*> (pE);
            espinhar(aux);
        }
    }
}