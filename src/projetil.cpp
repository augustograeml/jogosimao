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
    }

    Projetil::~Projetil()
    {

    }

    void Projetil::executar()
    {
        this->desenhar();
        this->atirar();
    }
    void Projetil::atirar()
    {
        corpo.move(velocidade);
    }
    void Projetil::colidir()
    {
        setVelocidade(Vector2f(0,0));
    }
}