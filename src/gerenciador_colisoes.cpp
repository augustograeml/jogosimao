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
    Lista<Entidade>::Iterador jog = jogadores->lista.getPrimeiro();
    while(jog != nullptr)
    {
        obst = obstaculos->lista.getPrimeiro();
        while (obst != nullptr)
        {
            if(colidiu(*jog, *obst))
            {
                (*jog)->colidir();
                (*obst)->colidir();
            }
        }
        
    }
}

int Gerenciador_Colisoes::colidiu(Entidade* e1, Entidade* e2)
{
    return 0;
}