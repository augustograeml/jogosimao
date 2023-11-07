#include "inimigo_dificil.hpp"


Inimigo_Dificil::Inimigo_Dificil(Vector2f pos, Vector2f vel):
    Inimigo(pos, vel), vidas(3), velocidade(0.1), forca(25)
{
    
}

Inimigo_Dificil::~Inimigo_Dificil()
{
    pjogador = nullptr;
}