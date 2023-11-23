#include  "../Entidades/projetil.hpp"
#define TAM_BALAX 20
#define TAM_BALAY 5

namespace Entidades
{
    Projetil::Projetil() : Entidade(this->getPosicao())
    {
        corpo.setSize(Vector2f(TAM_BALAX,TAM_BALAY));
        corpo.setFillColor(sf::Color::Red);
        velocidade = (Vector2f(12,0));
        set_vivo(1);
    }

    Projetil::~Projetil()
    {

    }

    void Projetil::executar()
    {
        if(vivo)
        {
            this->desenhar();
            this->atirar();
        }
        
    }
    void Projetil::atirar()
    {   corpo.move(Vector2f(0,0.1f));
        corpo.move(velocidade);
    }
    void Projetil::colidir(Entidade* pE)
    {
        setVelocidade(Vector2f(0,0));
    }
}