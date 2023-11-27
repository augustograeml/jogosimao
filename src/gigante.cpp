#include "../Entidades/Personagens/gigante.hpp"

namespace Entidades
{
    namespace Personagens
    {
        Gigante::Gigante(sf::Vector2f pos, sf::Vector2f vel) : Inimigo(pos, vel),
                                                               ja_inc(false)
        {
            int i = rand() % 10;
            if (i == 2)
                maldade = true;

            if (maldade)
                set_forca(10);
            else
                set_forca(4);

            this->setSkin("Design/imagens/zumbi_gigante.png");
            this->set_vida(100);
            set_pontos_cedidos(20);
        }

        Gigante::~Gigante()
        {
        }

        void Gigante::atualizar()
        {
            corpo.setPosition(corpo.getPosition() + velocidade);
        }

        void Gigante::mover()
        {
            // velocidade += Vector2f(rand() % 10 - 5, (float) (nochao ? - (rand() % 5) : 0));
            if (maldade && !(ja_inc))
            {
                velocidade.x += 0.2;
                ja_inc = true;
            }
            if (vida > 0)
            {
                if (!nochao)
                    velocidade += Vector2f(0, 0.1);
                else
                {
                    if (direcao)
                        velocidade = Vector2f(0.1f, 0.f);
                    else
                        velocidade = Vector2f(-0.1f, 0.f);
                }

                nochao = false;
                atualizar();
            }
            else
                morrer();
        }

        void Gigante::executar()
        {
            if (vivo)
                mover();
        }
        void Gigante::colidir(Entidade *pE, int a)
        {
            if (a == 1 || a == 3)
            {
                mudar_direcao();
                atacar(pE);
            }
            else if (a == 4)
            {
                this->set_vida(this->get_vida() - 10);
            }
            else
            {
                atacar(pE);
            }
        }

        void Gigante::criar_gigante(string arquivo)
        {
            ifstream caminho(arquivo);

            if (!caminho)
            {
                cout << "Nao foi possivel acessar o arquivo de criacao dos arqueiros";
                exit(1);
            }

            string linha;
            Entidade *aux = nullptr;
            int j, i;

            for (i = 0; getline(caminho, linha); i++)
            {
                j = 0;
                for (char tipo : linha)
                {
                    switch (tipo)
                    {
                    case '9':
                        aux = static_cast<Entidade *>(new Gigante(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f)));
                        if (aux)
                        {
                            aux->setWindow(pGG->get_Janela());
                            aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                            // incluir inmigos na lista
                        }
                        break;

                    default:
                        break;
                    }
                }
            }
        }

        void Gigante::atacar(Entidade *jg)
        {
            jg->set_vida(jg->get_vida() - forca);
        }

        void Gigante::salvar(std::ostringstream *entrada)
        {
            (*entrada) << "{ \"posicao\": [" << corpo.getPosition().x << "," << corpo.getPosition().y << "], \"velocidade\": [" << velocidade.x << "," << velocidade.y << "] }" << std::endl;
        }
    }
}