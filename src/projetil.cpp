//codigo inspirado no da dupla Guilherme e Caique

#include "../Entidades/projetil.hpp"
#include <iostream>

#define TAM_BALAX 20
#define TAM_BALAY 5
#define VELOCIDADE {12, 0}

using namespace std;

namespace Entidades
{
    //caso der errado colocar a contrutora de direcao e velocidade aqui que nem a dupla deles fez
    Projetil::Projetil(sf::Vector2f pos, bool dir) : Entidade(this->getPosicao()), dano(2)
    {
        corpo.setSize(Vector2f(TAM_BALAX, TAM_BALAY));
        corpo.setFillColor(sf::Color::Red);

        direcao = dir;

        velocidade = VELOCIDADE;

        set_vivo(1);
    }

    Projetil::~Projetil()
    {
        
    }

    void Projetil::executar()
    {
        if (vivo)
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
            velocidade = {0, 0};
            corpo.setFillColor(sf::Color::Transparent);
        }
        else
        {
            corpo.move(GRAVIDADE);
            corpo.move(velocidade);
        }
    }

    void Projetil::atirar()
    {
    }

    void Projetil::salvar(std::ostringstream *entrada)
    {
        if(get_vivo())
            (*entrada) << "{ \"posicao\": [" << corpo.getPosition().x << "," << corpo.getPosition().y << "], \"velocidade\": [" << velocidade.x << "," << velocidade.y << "] \"direcao\": [" << direcao << "]}" << std::endl;
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