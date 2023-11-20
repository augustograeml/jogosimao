#include "../Entidades/Personagens/zumbi.hpp"
#include "../Entidades/Personagens/inimigo.hpp"

namespace Entidades
{
    namespace Personagens
    {
        Zumbi::Zumbi(Vector2f pos, Vector2f vel) : Inimigo(pos, vel)
        {
            this->setSkin("Design/imagens/zumbi_bateu_morreu.png");
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
            //velocidade += Vector2f(rand() % 10 - 5, (float) (nochao ? - (rand() % 5) : 0));

            if(!nochao)
                velocidade += Vector2f(0, 0.1f);
            else
                velocidade = Vector2f(0.1f, 0.f);
            nochao = false;
            

            atualizar();
        }

        void Zumbi::executar()
        {
            //update();
            mover();
        }

        void Zumbi::atacar(Entidade* jg)
        {
            jg->set_vida(jg->get_vida() - forca);
        }

        void Zumbi::salvar(std::ostringstream* entrada)
        {
            (*entrada) << "{ \"posicao\": [" << corpo.getPosition().x<<","<<corpo.getPosition().y<<"], \"velocidade\": ["<<velocidade.x<<","<<velocidade.y<<"] }" << std::endl;
        }
    }
}