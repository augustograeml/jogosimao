#include "gerenciador_colisoes.hpp"

Gerenciador_Colisoes::Gerenciador_Colisoes() : jogadores(nullptr), obstaculos(nullptr), inimigos(nullptr)
{
    
}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
    jogadores = nullptr;
    obstaculos = nullptr;
    inimigos = nullptr;
}

void Gerenciador_Colisoes::colisao_simples()
{
    Lista<Entidade>::Iterador obst;
    //Lista<Entidade>::Iterador jog = jogadores->;
}

int Gerenciador_Colisoes::colidiu(Entidade* e1, Entidade* e2)
{
    return 0;
}