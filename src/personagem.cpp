#include "../Entidades/Personagens/personagem.hpp"

namespace Entidades
{
    namespace Personagens
    {
        Personagem::Personagem(sf::Vector2f pos, sf::Vector2f vel, int f) : Entidade(), forca(f)
        {
            corpo.setPosition(pos);
            velocidade = vel;
        }

        Personagem::~Personagem()
        {
            
        }

        void Personagem::set_forca(int forc)
        {
            forca = forc;
        }

        int Personagem::get_forca()
        {
            return forca;
        }
    }
}