#include "personagem.hpp"

Personagem::Personagem() : Entidade(), vidas(1)
{

}

Personagem::~Personagem()
{
    vidas = 0;
}