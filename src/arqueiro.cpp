#include "../Entidades/Personagens/arqueiro.hpp"

namespace Entidades
{
    namespace Personagens
    {
        Arqueiro::Arqueiro(sf::Vector2f pos, sf::Vector2f vel):
            Inimigo(pos, vel)
        {
            this->setSkin("Design/imagens/zumbi_atirador.png");
            atirando = false;
            direcao = 0;
            recarregar = 0;
            set_forca(5);

            //depois mexer com o setvida desse molecote aqui
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
            
            if(!nochao)
                velocidade += Vector2f(0, 0.1);
            else
            {
                if(direcao)
                velocidade = Vector2f(-0.1f, 0.f);
                else
                velocidade = Vector2f(0.1f, 0.f);
            }

            //if(pjogador->get_pause() == false)
                atualizar();
            //atualizar();
                
            nochao = false;
        }

        void Arqueiro::executar()
        {
            if(vivo)
            {
                mover();
                atirar();
            }
            
        }

        void Arqueiro::atacar(Entidade* jg)
        {
            jg->set_vida(jg->get_vida() - forca);
        }
        void Arqueiro::colidir(Entidade* pE, int a)
        {
            if(a == 1 || a == 3)
            {
                atacar(pE);
                mudar_direcao();
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
        void Arqueiro::atirar()
        {
            sf::Vector2f z = this->getTamanho() / 2.f;

            if(recarregar == 0)
            {
                novo.setPosicao(this->getPosicao() + (z));
                atirando = false;
                if(!direcao)
                novo.setVelocidade(-novo.getVelocidade());
                novo.executar();
                recarregar = TEMPO_RECARGA;
            }
            else
            {
                recarregar--;
                novo.executar();
            }
        }

        void Arqueiro::salvar(std::ostringstream* entrada)
        {
            (*entrada) << "{ \"posicao\": [" << corpo.getPosition().x<<","<<corpo.getPosition().y<<"], \"velocidade\": ["<<velocidade.x<<","<<velocidade.y<<"] }" << std::endl;
        }
    }
}