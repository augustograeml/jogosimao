#include "entidade.hpp"

Entidade::Entidade(Vector2f pos):
    Ente(Vector2f(TAM, TAM)), posicao(pos), nochao(false), velocidade(0.f, 0.f)
{
    corpo.setPosition(posicao);
}

Entidade::~Entidade()
{

}

void Entidade::colidir()
{

}

void Entidade::setPosicao(Vector2f p)
{
    corpo.setPosition(p);
}


void Entidade::setSkin(const std::string filename)
{
    Textura.loadFromFile(filename);
    corpo.setTexture(&Textura);
}