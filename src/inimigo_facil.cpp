#include "inimigo_facil.hpp"
#include "inimigo.hpp"

Inimigo_Facil::Inimigo_Facil() : Inimigo(), vidas(1), velocidade(0.05), forca(10)
{

}

Inimigo_Facil::~Inimigo_Facil()
{
    pjogador = nullptr;
}

void Inimigo_Facil::atacar()
{

}

void Inimigo_Facil::executar()
{
    while(vidas)
    {
        atacar();
    }

}