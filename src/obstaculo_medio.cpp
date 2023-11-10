#include "obstaculo_medio.hpp"

Obstaculo_Medio::Obstaculo_Medio(Vector2f pos) : Obstaculo(pos, true), dano(2.0)
{
    this->setSkin("src/imagem/espinho.png");
    this->set_vida(55);
}

Obstaculo_Medio::~Obstaculo_Medio()
{

}

void Obstaculo_Medio::executar()
{

}

void Obstaculo_Medio::mover()
{

}

void Obstaculo_Medio::atualizar()
{

}

