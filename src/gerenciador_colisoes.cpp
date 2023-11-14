#include "../Gerenciadores/gerenciador_colisoes.hpp"
#include <math.h>
#include <iostream>

using namespace std;

#define ACL 0.2

namespace Gerenciadores
{
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
        Listas::Lista<Entidades::Entidade>::Iterador obst;
        Listas::Lista<Entidades::Entidade>::Iterador jog = jogadores->get_primeiro();

        while (jog != nullptr)
        {
            obst = obstaculos->get_primeiro();
            while (obst != nullptr)
            {

                if (colidiu(*jog, *obst))
                {
                    if ((*obst)->get_vida() == 55)
                    {
                        (*jog)->set_vida((*jog)->get_vida() - 1);
                        /*(*jog)->colidir();
                        (*obst)->colidir();*/
                    }
                    if ((*obst)->get_vida() == 40)
                    {
                        (*jog)->set_vida(5);
                        obstaculos->remover((*obst));
                        /*(*jog)->colidir();
                        (*obst)->colidir();*/
                    }
                }
                obst++;
            }
            jog++;
        }
        Listas::Lista<Entidades::Entidade>::Iterador inim = inimigos->get_primeiro();
        while (inim != nullptr)
        {
            obst = obstaculos->get_primeiro();
            while (obst != nullptr)
            {
                if (colidiu(*inim, *obst))
                {
                    /*(*inim)->colidir();
                    (*obst)->colidir();*/
                }
                obst++;
            }
            inim++;
        }

        jog = jogadores->get_primeiro();

        while (jog != nullptr)
        {
            inim = inimigos->get_primeiro();
            while (inim != nullptr)
            {
                int j = colidiu(*jog, *inim);


                if (j == 4)
                {
                    std::cout << "entrou" << endl;
                    (*inim)->set_vida(0);
                    inimigos->remover((*inim));
                }
                else if (j == 2)
                {
                    std::cout << "entrou no segnudo" << endl;
                    (*jog)->set_vida((*jog)->get_vida() - 1);
                }
                else if (j)
                {
                    std::cout << "entrou no terceiro" << endl;
                    (*jog)->set_vida((*jog)->get_vida() - 1);
                    /*(*jog)->colidir();
                    (*inim)->colidir();*/
                }
                inim++;
            }
            jog++;
        }
    }

    int Gerenciador_Colisoes::colidiu(Entidades::Entidade *e1, Entidades::Entidade *e2)
    {
        sf::Vector2f pos1 = e1->getPosicao(), pos2 = e2->getPosicao(), tam1 = e1->getTamanho(), tam2 = e2->getTamanho(),
                 d(fabs(pos1.x - pos2.x) - ((tam1.x + tam2.x) / 2.f),
                   fabs(pos1.y - pos2.y) - ((tam1.y + tam2.y) / 2.f));

        if (d.x < 0 && d.y < 0)
        {
            if (d.x < d.y)
            {
                if (pos1.y <= pos2.y)
                {
                    e1->setPosicao(sf::Vector2f(e1->getPosicao().x, e2->getPosicao().y - (tam1.y + tam2.y) / 2));
                    e1->set_nochao(true);
                    e1->setVelocidade(sf::Vector2f(e1->getVelocidade().x, -e1->getVelocidade().y * ACL));
                    return 4;
                }
                else
                {
                    e1->setPosicao(sf::Vector2f(e1->getPosicao().x, e2->getPosicao().y + (tam1.y + tam2.y) / 2));
                    e1->setVelocidade(sf::Vector2f(e1->getVelocidade().x, -e1->getVelocidade().y * ACL));
                    return 2;
                }
            }
            else
            {
                if (pos1.x >= pos2.x)
                {
                    e1->setPosicao(sf::Vector2f(e2->getPosicao().x + (tam1.x + tam2.x) / 2, e1->getPosicao().y));
                    e1->setVelocidade(sf::Vector2f(-e1->getVelocidade().x * ACL, e1->getVelocidade().y));
                    return 1;
                }
                else
                {
                    e1->setPosicao(sf::Vector2f(e2->getPosicao().x - (tam1.x + tam2.x) / 2, e1->getPosicao().y));
                    e1->setVelocidade(sf::Vector2f(-e1->getVelocidade().x * ACL, e1->getVelocidade().y));
                    return 3;
                }
            }
        }
        return 0;
    }

}
