#include "inimigo_facil.hpp"
#include "inimigo.hpp"

Inimigo_Facil::Inimigo_Facil(Vector2f pos, Vector2f vel) : Inimigo(pos, vel), vidas(1), forca(10)
{
    this->setSkin("src/imagem/zumbi_bateu_morreu.png");
}

Inimigo_Facil::~Inimigo_Facil()
{
    pjogador = nullptr;
}

void Inimigo_Facil::atualizar()
{
    corpo.setPosition(corpo.getPosition() + velocidade);
}

void Inimigo_Facil::mover()
{
    velocidade += Vector2f(rand() % 10 - 5, (float) (nochao ? - (rand() % 5) : 0));

    if(!nochao)
        velocidade += Vector2f(0, 0.1);
    else
        velocidade = Vector2f(velocidade.x, 0.f);
    nochao = false;
    

    atualizar();
}

void Inimigo_Facil::executar()
{
    //update();
    mover();
}

void Inimigo_Facil::atacar(Entidade* jg)
{
    jg->set_vida(jg->get_vida() - forca);
}
