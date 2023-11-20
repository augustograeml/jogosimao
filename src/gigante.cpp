#include "../Entidades/Personagens/gigante.hpp"

namespace Entidades
{
    namespace Personagens
    {
        Gigante::Gigante(sf::Vector2f pos, sf::Vector2f vel) : Inimigo(pos, vel), maldade(false), 
        ja_inc(false)
        {
            int i = rand()%10;
            if(i == 2)
                maldade = true;

            if(maldade)
                set_forca(10);
            else
                set_forca(4);

            this->setSkin("Design/imagens/zumbi_gigante.png");
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
            //velocidade += Vector2f(rand() % 10 - 5, (float) (nochao ? - (rand() % 5) : 0));
            if(maldade && !(ja_inc))
            {
                velocidade.x += 0.2;
                ja_inc = true;
            }
            
            if(!nochao)
                velocidade += Vector2f(0, 0.1);
            else
                velocidade = Vector2f(0.1f, 0.f);
            nochao = false;
            

            atualizar();
        }

        void Gigante::executar()
        {
            //update();
            mover();
        }

        void Gigante::atacar(Entidade* jg)
        {
            jg->set_vida(jg->get_vida() - forca);
        }

        void Gigante::salvar(std::ostringstream* entrada)
        {
            (*entrada) << "{ \"posicao\": [" << corpo.getPosition().x<<","<<corpo.getPosition().y<<"], \"velocidade\": ["<<velocidade.x<<","<<velocidade.y<<"] }" << std::endl;
        }
    }
}