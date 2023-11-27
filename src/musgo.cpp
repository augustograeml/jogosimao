#include "../Entidades/Obstaculos/musgo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Musgo::Musgo(sf::Vector2f pos) : Obstaculo(pos), gosmento(true)
        {
            this->setSkin("Design/imagens/bloco_musgo.jpeg");
            gosmento = rand()%2;
        }

        Musgo::~Musgo()
        {

        }

        void Musgo::mover()
        {

        }

        void Musgo::executar()
        {

        }

        void Musgo::atualizar()
        {

        } 
        void Musgo::gosmar(Entidades::Personagens::Jogador* pJ)
        {
            if(get_gosmento())
            {
                pJ->setVelocidade(Vector2f((pJ->getVelocidade().x / get_intensidade())*1.1 , pJ->getVelocidade().y));
            }
        }
        void Musgo::colidir(Entidade* pE,  int a)
        {
            Entidades::Personagens::Jogador* aux = static_cast<Entidades::Personagens::Jogador*> (pE);
            gosmar(aux);
        }
    }
}