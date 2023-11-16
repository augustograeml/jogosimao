#include "../Entidades/Personagens/arqueiro.hpp"

namespace Entidades
{
    namespace Personagens
    {
        Arqueiro::Arqueiro(sf::Vector2f pos, sf::Vector2f vel):
            Inimigo(pos, vel)
        {
            this->setSkin("Design/imagens/zumbi_atirador.png");
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
            //velocidade += Vector2f(rand() % 10 - 5, (float) (nochao ? - (rand() % 5) : 0));

            if(!nochao)
                velocidade += Vector2f(0, 0.1);
            else
                velocidade = Vector2f(-0.1f, 0.f);
            nochao = false;
            

            atualizar();
        }

        void Arqueiro::executar()
        {
            mover();
        }

        void Arqueiro::atacar(Entidade* jg)
        {
            jg->set_vida(jg->get_vida() - forca);
        }

        void Arqueiro::salvar(std::ostringstream* entrada)
        {
            (*entrada) << "{ \"posicao\": [" << corpo.getPosition().x<<","<<corpo.getPosition().y<<"], \"velocidade\": ["<<velocidade.x<<","<<velocidade.y<<"] }" << std::endl;
        }
    }
}