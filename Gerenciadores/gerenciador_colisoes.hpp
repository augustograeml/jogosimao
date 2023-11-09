#pragma once
#include "../Listas/listaEntidades.hpp"
#include "../Listas/lista.hpp"
#include "../Entidades/entidade.hpp"

namespace Gerenciadores
{

class Gerenciador_Colisoes
{
    private:
        ListaEntidade* obstaculos;
        ListaEntidade* jogadores;
        ListaEntidade* inimigos;
    public:
        Gerenciador_Colisoes();
        ~Gerenciador_Colisoes();

        void set_obstaculos(ListaEntidade* obs) {if(obs) obstaculos = obs;}
        void set_jogadores(ListaEntidade* jog) {if(jog) jogadores = jog;}
        void set_inimigos(ListaEntidade* ini) {if(ini) inimigos = ini;}

        void colisao_simples();

        int colidiu(Entidades::Entidade* e1, Entidades::Entidade* e2);
};

}