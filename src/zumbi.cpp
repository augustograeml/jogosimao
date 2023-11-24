#include "../Entidades/Personagens/zumbi.hpp"
#include "../Entidades/Personagens/inimigo.hpp"

namespace Entidades
{
    namespace Personagens
    {
        Zumbi::Zumbi(Vector2f pos, Vector2f vel) : Inimigo(pos, vel)
        {
            this->setSkin("Design/imagens/zumbi_bateu_morreu.png");
            direcao = 1;
            pulo = rand() % 10;
        }

        Zumbi::~Zumbi()
        {
            pjogador = nullptr;
        }

        void Zumbi::atualizar()
        {
            corpo.setPosition(corpo.getPosition() + velocidade);
        }

        void Zumbi::mover()
        {

            if (direcao)
            {
                if (!nochao)
                    velocidade += Vector2f(0, 0.1);
                else
                {
                    velocidade = Vector2f(0.1f, 0.f);
                    if (pulo == 2)
                        velocidade = Vector2f(0.3f, -2.0f);
                    else
                        pulo = rand() % 10;
                }

                nochao = false;
            }
            else
            {
                if (!nochao)
                    velocidade += Vector2f(0, 0.1);
                else
                {
                    velocidade = Vector2f(-0.1f, 0.f);
                    if (pulo == 2)
                        velocidade = Vector2f(-0.3f, -2.0f);
                    else
                        pulo = rand() % 10;
                }

                nochao = false;
            }

            atualizar();
        }

        void Zumbi::executar()
        {
            if (vivo)
                mover();
        }

        void Zumbi::atacar(Entidade *jg)
        {
            jg->set_vida(jg->get_vida() - forca);
        }

        void Zumbi::colidir(Entidade *pE, int a)
        {
            if (a == 1 || a == 3)
            {
                atacar(pE);
                this->mudar_direcao();
            }
            else if (a == 4)
            {
                morrer();
            }
            else
            {
                atacar(pE);
            }
        }

        void Zumbi::criar_zumbis(string arquivo)
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
                    case '3':
                        aux = static_cast<Entidade *>(new Zumbi(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f)));
                        if (aux)
                        {
                            aux->setWindow(pGG->get_Janela());
                            aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                            // incluir inmigos na lista
                        }
                        break;

                    default:
                        break;
                        ;
                    }
                }
            }
        }

        void Zumbi::salvar(std::ostringstream *entrada)
        {
            (*entrada) << "{ \"posicao\": [" << corpo.getPosition().x << "," << corpo.getPosition().y << "], \"velocidade\": [" << velocidade.x << "," << velocidade.y << "] }" << std::endl;
        }
    }
}