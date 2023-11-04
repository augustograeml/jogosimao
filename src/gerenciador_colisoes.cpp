#include "gerenciador_colisoes.hpp"
#include <math.h>
#include <iostream>

#define ACL 0.2

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
    Lista<Entidade>::Iterador jog = jogadores->getPrimeiro();
    while(jog != nullptr)
    {
        obst = obstaculos->getPrimeiro();
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
    Vector2f pos1 = e1->getPosicao(), pos2 = e2->getPosicao(), tam1 = e1->getTamanho(), tam2 = e2->getTamanho(),
    d(  fabs(pos1.x - pos2.x) - ((tam1.x + tam2.x)/2.f),
        fabs(pos1.y - pos2.y) - ((tam1.y + tam2.y)/2.f)
    );

    if(d.x < d.y)
    {
        if(pos1.y <= pos2.y)
        {
            e1->setPosicao(Vector2f(e1->getPosicao().x, e2->getPosicao().y - (tam1.y + tam2.y) / 2));
            e1->set_nochao(true);
            e1->setVelocidade(Vector2f(e1->getVelocidade().x, -e1->getVelocidade().y * ACL));
            return 4;
        }
        else
        {
            e1->setPosicao(Vector2f(e1->getPosicao().x, e2->getPosicao().y + (tam1.y + tam2.y) / 2));
            e1->setPosicao(Vector2f(e1->getVelocidade().x, -e1->getVelocidade().y * ACL));
            return 2;
        }
    }
    else
    {
        if(pos1.x >= pos2.x)
        {
            e1->setPosicao(Vector2f(e2->getPosicao().x + (tam1.x + tam2.x) / 2, e1->getPosicao().y));
            e1->setVelocidade(Vector2f(-e1->getVelocidade().x * ACL, e1->getVelocidade().y));
            return 1;
        }
        else
        {
            e1->setPosicao(Vector2f(e2->getPosicao().x - (tam1.x + tam2.x) / 2, e1->getPosicao().y));
            e1->setVelocidade(Vector2f(-e1->getVelocidade().x * ACL, e1->getVelocidade().y));
            return 3;
        }
    }
    
    return 0;
}