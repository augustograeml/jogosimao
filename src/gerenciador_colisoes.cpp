#include "../Gerenciadores/gerenciador_colisoes.hpp"
#include "../Entidades/Personagens/jogador.hpp"
#include "../Entidades/Personagens/inimigo.hpp"
#include "../Entidades/Obstaculos/obstaculo.hpp"
#include "../Entidades/Obstaculos/espinho.hpp"
#include "../Entidades/Obstaculos/coracao.hpp"
#include "../Entidades/Obstaculos/caixa.hpp"
#include "../Entidades/Obstaculos/neve.hpp"
#include "../Entidades/Obstaculos/musgo.hpp"
#include <math.h>
#include <iostream>

using namespace std;

#define ACL 0.2

namespace Gerenciadores
{
    Gerenciador_Colisoes::Gerenciador_Colisoes() : jogadores(nullptr), obstaculos(nullptr), inimigos(nullptr),
    sem_inimigos(false)
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
                    Entidades::Personagens::Jogador* jogador = static_cast<Entidades::Personagens::Jogador*> (*(jog));
                    Entidades::Obstaculos::Obstaculo* obstaculo = static_cast<Entidades::Obstaculos::Obstaculo*> (*(obst));
                    if (obstaculo->get_danoso())
                    {
                        Entidades::Obstaculos::Espinho* espinho = static_cast<Entidades::Obstaculos::Espinho*> (obstaculo);
                        espinho->espinhar(jogador);
                    }
                    if (obstaculo->get_curoso())
                    {
                        Entidades::Obstaculos::Coracao* coracao = static_cast<Entidades::Obstaculos::Coracao*> (obstaculo);
                        coracao->curar(jogador);
                        obstaculos->remover((*obst));
                    }
                    if(obstaculo->get_atrapalhante())
                    {
                        Entidades::Obstaculos::Caixa* caixa = static_cast<Entidades::Obstaculos::Caixa*> (obstaculo);
                        //implementar atrapalhar aqui
                    }
                    if(obstaculo->get_escorregadio())
                    {
                        Entidades::Obstaculos::Neve* neve = static_cast<Entidades::Obstaculos::Neve*> (obstaculo);
                        neve->escorregar(jogador);
                    }
                    if(obstaculo->get_gosmento())
                    {
                        Entidades::Obstaculos::Musgo* musgo = static_cast<Entidades::Obstaculos::Musgo*> (obstaculo);
                        musgo->gosmar(jogador);
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
                int a = colidiu(*inim, *obst);
                if (a == 1 || a == 3)
                {
                    Entidades::Personagens::Inimigo* inimigo = static_cast<Entidades::Personagens::Inimigo*> (*(inim));
                    inimigo->mudar_direcao();
                    (*inim)->colidir();
                    (*obst)->colidir();
                }
                else
                {
                     (*inim)->colidir();
                    (*obst)->colidir();
                    
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

                Entidades::Personagens::Jogador* aux = static_cast<Entidades::Personagens::Jogador*> (*(jog));
                Entidades::Personagens::Inimigo* aux2 = static_cast<Entidades::Personagens::Inimigo*> (*(inim));


                if (j == 4)
                {
                    aux2->set_vida(aux2->get_vida() - aux->get_forca());
                    //fazer como o simao quer depois : "ao inves de remover, so passar um bool dizendo que ta morto "
                    aux2->set_vivo(0);
                    inimigos->remover((*inim));
                }
                else if (j)
                {
                    if(aux->get_vida() > 0)
                    {
                        aux->set_vida(aux->get_vida() - aux2->get_forca());
                        (*jog)->colidir();
                        (*inim)->colidir();
                    }
                }
                inim++;
            }
            jog++;
        }

        if(inimigos->get_tamanho() == 1)
            sem_inimigos = true;
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

    bool Gerenciador_Colisoes::get_sem_inimigos()
    {
        return sem_inimigos;
    }

}
