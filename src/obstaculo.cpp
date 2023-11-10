#include "../Entidades/Obstaculos/obstaculo.hpp"

using namespace Entidades;
using namespace Obstaculos;

Obstaculo::Obstaculo(Vector2f pos, bool dano) :
Entidade(pos), danoso(dano)
{

}

Obstaculo::~Obstaculo()
{

}