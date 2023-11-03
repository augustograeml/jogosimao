#include "ente.hpp"

Gerenciador_Grafico* Ente::pGG(Gerenciador_Grafico::get_instancia());

Ente::Ente(Vector2f tam) : id(0), corpo(tam)
{

}

Ente::~Ente()
{

}

RectangleShape* Ente::get_corpo()
{
    return &corpo;
}

void Ente::desenhar()
{
    pGG->desenharEnte(this);
}

