#include "inimigo_dificil.hpp"


Inimigo_Dificil::Inimigo_Dificil(Vector2f pos, Vector2f vel):
    Inimigo(pos, vel), vidas(3), forca(25)
{
    this->setSkin("src/imagem/zumbi_atirador.png");
}

Inimigo_Dificil::~Inimigo_Dificil()
{
    pjogador = nullptr;
}

void Inimigo_Dificil::atualizar()
{
    corpo.setPosition(corpo.getPosition() + velocidade);
}

void Inimigo_Dificil::mover()
{
    velocidade += Vector2f(rand() % 10 - 5, (float) (nochao ? - (rand() % 5) : 0));

    if(!nochao)
        velocidade += Vector2f(0, 0.1);
    else
        velocidade = Vector2f(velocidade.x, 0.f);
    nochao = false;
    

    atualizar();
}

void Inimigo_Dificil::executar()
{
    mover();
}

void Inimigo_Dificil::atacar()
{
}

