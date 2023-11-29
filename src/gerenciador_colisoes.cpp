// codigo reaproveitado do Peteco

#include "../Gerenciadores/gerenciador_colisoes.hpp"
#include "../Entidades/Personagens/jogador.hpp"
#include "../Entidades/Personagens/inimigo.hpp"
#include "../Entidades/Personagens/arqueiro.hpp"
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
    Gerenciador_Colisoes::Gerenciador_Colisoes() : jogadores(nullptr),
                                                   obstaculos(nullptr),
                                                   inimigos(nullptr),
                                                   projeteis(nullptr),
                                                   sem_inimigos(false),
                                                   sem_jogadores(false)
    {
    }

    Gerenciador_Colisoes::~Gerenciador_Colisoes()
    {
        jogadores = nullptr;
        obstaculos = nullptr;
        inimigos = nullptr;
        projeteis = nullptr;
    }

    void Gerenciador_Colisoes::colisao_jogadores_obstaculos()
    {
        Listas::Lista<Entidades::Entidade>::Iterador obst;
        Listas::Lista<Entidades::Entidade>::Iterador jog;
        jog.operator=(jogadores->get_primeiro());

        while (jog != nullptr)
        {
            obst.operator=(obstaculos->get_primeiro());
            while (obst != nullptr)
            {
                if ((*obst)->get_vivo())
                {
                    int id_colisao = colidiu(*jog, *obst);
                    if (id_colisao)
                    {
                        (*obst)->colidir(*jog, id_colisao);
                        (*jog)->colidir(*obst, id_colisao);
                    }
                }
                obst.operator++();
            }
            jog.operator++();
        }
    }
    void Gerenciador_Colisoes::colisao_inimigos_obstaculos()
    {
        Listas::Lista<Entidades::Entidade>::Iterador obst;
        Listas::Lista<Entidades::Entidade>::Iterador inim;
        inim.operator=(inimigos->get_primeiro());
        while (inim != nullptr)
        {
            obst.operator=(obstaculos->get_primeiro());
            while (obst != nullptr)
            {
                if ((*obst)->get_vivo())
                    int id_colisao = colidiu(*inim, *obst);

                obst.operator++();
            }
            inim.operator++();
        }
    }

    void Gerenciador_Colisoes::colisao_jogadores_inimigos()
    {
        Listas::Lista<Entidades::Entidade>::Iterador jog;
        jog.operator=(jogadores->get_primeiro());
        Listas::Lista<Entidades::Entidade>::Iterador inim;
        inim.operator=(inimigos->get_primeiro());
        while (jog != nullptr)
        {
            inim.operator=(inimigos->get_primeiro());
            while (inim != nullptr)
            {
                if ((*inim)->get_vivo())
                {
                    int j = colidiu(*jog, *inim);

                    if (j)
                        (*inim)->colidir(*jog, j);
                }
                inim.operator++();
            }
            jog.operator++();
        }
    }
    void Gerenciador_Colisoes::colisao_jogadores_projeteis()
    {
        Listas::Lista<Entidades::Entidade>::Iterador inim;
        inim.operator=(inimigos->get_primeiro());
        Listas::Lista<Entidades::Entidade>::Iterador jog;
        jog.operator=(jogadores->get_primeiro());
        while (inim != nullptr)
        {
            Entidades::Personagens::Inimigo *arqueiro_atira = static_cast<Entidades::Personagens::Inimigo *>(*inim);
            std::vector<Entidades::Projetil> *pVetor = arqueiro_atira->get_projeteis();

            if (pVetor != nullptr)
            {
                jog.operator=(jogadores->get_primeiro());
                while (jog != nullptr)
                {
                    if (pVetor->size() > 0)
                    {
                        for (int i = 0; i < pVetor->size(); i++)
                        {
                            Entidades::Entidade *proj = static_cast<Entidades::Entidade *>(&pVetor->at(i));
                            if (proj->get_vivo())
                            {
                                int j = colidiu(*jog, proj);
                                if (j)
                                {
                                    proj->colidir(*jog, j);
                                    proj->set_vivo(false);
                                }
                            }
                        }
                    }
                    jog.operator++();
                }
            }
            inim.operator++();
        }
    }
    void Gerenciador_Colisoes::colisao_obstaculos_projeteis()
    {
        Listas::Lista<Entidades::Entidade>::Iterador obst;
        obst.operator=(obstaculos->get_primeiro());
        Listas::Lista<Entidades::Entidade>::Iterador inim;
        inim.operator=(inimigos->get_primeiro());
        while (inim != nullptr)
        {
            Entidades::Personagens::Inimigo *arqueiro_atira = static_cast<Entidades::Personagens::Inimigo *>(*inim);
            std::vector<Entidades::Projetil> *pVetor = arqueiro_atira->get_projeteis();

            if (pVetor != nullptr)
            {
                obst.operator=(obstaculos->get_primeiro());
                while (obst != nullptr)
                {
                    if (pVetor->size() > 0)
                    {
                        for (int i = 0; i < pVetor->size(); i++)
                        {
                            Entidades::Entidade *proj = static_cast<Entidades::Entidade *>(&pVetor->at(i));
                            if (proj->get_vivo())
                            {
                                int j = colidiu_projeteis(*obst, proj);
                                if (j != 0)
                                {
                                    proj->colidir(*obst, j);
                                    proj->set_vivo(false);
                                }
                                
                            }
                        }
                    }
                    obst.operator++();
                }
            }

            inim.operator++();
        }
    }

    const bool Gerenciador_Colisoes::get_inimigos_vivos()
    {
        int ini_vivos = 0;
        Listas::Lista<Entidades::Entidade>::Iterador inimg = inimigos->get_primeiro();
        while (inimg != nullptr)
        {
            if ((*inimg)->get_vivo())
                ini_vivos++;
            inimg++;
        }
        if (ini_vivos == 0)
            sem_inimigos = true;

        return sem_inimigos;
    }

    const bool Gerenciador_Colisoes::get_jogadores_vivos()
    {
        int jog_vivos = 0;
        Listas::Lista<Entidades::Entidade>::Iterador joga = jogadores->get_primeiro();
        while (joga != nullptr)
        {
            if ((*joga)->get_vivo())
                jog_vivos++;
            joga++;
        }
        if (jog_vivos == 0)
            sem_jogadores = true;

        return sem_jogadores;
    }

    void Gerenciador_Colisoes::gerenciar_colisoes()
    {
        colisao_jogadores_obstaculos();
        colisao_jogadores_inimigos();
        colisao_inimigos_obstaculos();
        colisao_jogadores_projeteis();
        colisao_obstaculos_projeteis();
        get_inimigos_vivos();
        get_jogadores_vivos();
    }
    int Gerenciador_Colisoes::colidiu_projeteis(Entidades::Entidade *e1, Entidades::Entidade *e2)
    {
        sf::Vector2f pos1 = e1->getPosicao(), pos2 = e2->getPosicao(), tam1 = e1->getTamanho(), tam2 = e2->getTamanho(),
                     d(fabs(pos1.x - pos2.x) - ((tam1.x + tam2.x) / 2.f),
                       fabs(pos1.y - pos2.y) - ((tam1.y + tam2.y) / 2.f));
        if(d.x < 0 && d.y < 0)
        {   
            if (d.x < d.y)
            {
                if (pos1.y <= pos2.y)
                {
                    //e1->setPosicao(sf::Vector2f(e1->getPosicao().x, e2->getPosicao().y - (tam1.y + tam2.y) / 2));
                    e1->set_nochao(true);
                    e1->setVelocidade(sf::Vector2f(e1->getVelocidade().x, -e1->getVelocidade().y * ACL));
                    return 4;
                }
                else
                {
                    //e1->setPosicao(sf::Vector2f(e1->getPosicao().x, e2->getPosicao().y + (tam1.y + tam2.y) / 2));
                    e1->setVelocidade(sf::Vector2f(e1->getVelocidade().x, -e1->getVelocidade().y * ACL));
                    return 2;
                }
            }
            else
            {
                if (pos1.x >= pos2.x)
                {
                    //e1->setPosicao(sf::Vector2f(e2->getPosicao().x + (tam1.x + tam2.x) / 2, e1->getPosicao().y));
                    e1->setVelocidade(sf::Vector2f(-e1->getVelocidade().x * ACL, e1->getVelocidade().y));
                    return 1;
                }
                else
                {
                    //e1->setPosicao(sf::Vector2f(e2->getPosicao().x - (tam1.x + tam2.x) / 2, e1->getPosicao().y));
                    e1->setVelocidade(sf::Vector2f(-e1->getVelocidade().x * ACL, e1->getVelocidade().y));
                    return 3;
                }
            }
        }
        
        return 0;
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
