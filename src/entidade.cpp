//codigo reaproveitado do Peteco

#include "../Entidades/entidade.hpp"
#include <iostream>

using namespace std;

namespace Entidades
{
    Entidade::Entidade(sf::Vector2f pos):
        Ente(sf::Vector2f(TAM, TAM)), posicao(pos), nochao(false), velocidade(0.f, 0.f), vida(20),
        pausado(false)
    {
        corpo.setPosition(posicao);
    }

    Entidade::~Entidade()
    {

    }

    void Entidade::colidir()
    {
    }

    void Entidade::executar()
    {
        this->mover();
        this->atualizar();
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

}