#include "../Entidades/projetil.hpp"
#define TAM_BALAX 20
#define TAM_BALAY 5

namespace Entidades
{
    Projetil::Projetil(sf::Vector2f tam) : Entidade(this->getPosicao()), dano(2)
    {
        corpo.setSize(Vector2f(TAM_BALAX, TAM_BALAY));
        corpo.setFillColor(sf::Color::Red);
        velocidade = (Vector2f(12, 0));
        set_vivo(1);
    }

    Projetil::~Projetil()
    {
    }

    void Projetil::executar()
    {
        if (get_vivo())
        {
            this->desenhar();
            this->mover();
        }
    }

    void Projetil::atualizar()
    {
        corpo.setPosition(corpo.getPosition() + velocidade);
    }

    void Projetil::mover()
    {
            if (nochao)
            {
                set_vida(0);
                set_vivo(0);
                velocidade = {0, 0};
                corpo.setFillColor(sf::Color::Transparent);
            }
            else
            {
                corpo.move(GRAVIDADE);
                corpo.move(velocidade);
            }

        // atualizar();
    }

    void Projetil::atirar()
    {
    }

    void Projetil::danar(Entidade *pE)
    {
        if (pE)
            pE->set_vida(pE->get_vida() - dano);
    }

    void Projetil::colidir(Entidade *pE, int a)
    {

        // eu nao to atribuindo nenhum projetil a lista
        if (a != 0)
        {
            danar(pE);
            setVelocidade(Vector2f(0.f, 0.f));
        }

        executar();
    }
}