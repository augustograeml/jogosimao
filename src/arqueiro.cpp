#include "../Entidades/Personagens/arqueiro.hpp"

namespace Entidades
{
    namespace Personagens
    {
        Arqueiro::Arqueiro(sf::Vector2f pos, sf::Vector2f vel) : Inimigo(pos, vel), vetor_projeteis(), numero_salvo_arqueiros(0)
        {
            this->setSkin("Design/imagens/zumbi_atirador.png");
            atirando = false;
            direcao = 0;
            recarregar = 0;
            set_forca(5);

            // depois mexer com o setvida desse molecote aqui
        }

        Arqueiro::~Arqueiro()
        {
            pjogador = nullptr;
        }

        void Arqueiro::atualizar()
        {
            corpo.setPosition(corpo.getPosition() + velocidade);
        }

        void Arqueiro::mover()
        {
            if (!nochao)
                velocidade += Vector2f(0, 0.1);
            else
            {
                if (direcao)
                    velocidade = Vector2f(-0.1f, 0.f);
                else
                    velocidade = Vector2f(0.1f, 0.f);
            }
            atualizar();
            nochao = false;
            for(int i = 0; i < vetor_projeteis.size(); i++)
                vetor_projeteis[i].executar();
            if(vetor_projeteis.size() > 50)
            {
                for(int i = 0; i < vetor_projeteis.size()/2; i++)
                    vetor_projeteis.erase(vetor_projeteis.begin() + i);
            }
        }

        void Arqueiro::executar()
        {
            if (vivo)
            {
                mover();
                atirar();
            }
        }

        void Arqueiro::atacar(Entidade *jg)
        {
            jg->set_vida(jg->get_vida() - forca);
        }
        
        void Arqueiro::colidir(Entidade *pE, int a)
        {
            if (a == 1 || a == 3)
            {
                if(a == 1)
                    direcao = 0;
                else
                    direcao = 1;

                atacar(pE);
                mudar_direcao();
            }
            else if (a == 4)
                morrer();
            else
                atacar(pE);
        }

        void Arqueiro::criar_arqueiros(string arquivo)
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
                    case '4':
                        aux = static_cast<Entidade *>(new Arqueiro(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f)));
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

        void Arqueiro::atirar()
        {
            sf::Vector2f z = this->getTamanho() / 2.f;

            if (recarregar == 0)
            {
                Projetil novo_projetil({10, 5}, direcao);
                novo_projetil.setPosicao(sf::Vector2f(this->getPosicao().x + 20.f, this->getPosicao().y + 15.f));
                atirando = false;
                if (!direcao)
                    novo_projetil.setVelocidade(-novo_projetil.getVelocidade());
                vetor_projeteis.push_back(novo_projetil);
                atirando = false;
                recarregar = TEMPO_RECARGA;
            }
            else
            {
                recarregar--;
            }
        }

        void Arqueiro::salvar(std::ostringstream *entrada)
        {
            (*entrada) << "{ \"identidade\": [" << 4 << "] , \"posicao\": [" << corpo.getPosition().x << "," << corpo.getPosition().y << "], \"velocidade\": [" << velocidade.x << "," << velocidade.y << "], \"projeteis\": ["  << endl;

            std::vector<Projetil>::iterator it;
            for(it = vetor_projeteis.begin(); it != vetor_projeteis.end(); it++)
            {
                (*it).salvar(entrada);
                if(it != vetor_projeteis.end() - 1 && (*it).get_vivo() == true)
                {
                    (*entrada << ", ");
                }
            }
            (*entrada) << "]}";

            numero_salvo_arqueiros++;
            //fim do salvamento
        }
    }
}