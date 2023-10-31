#pragma once
#include "listaEntidadas.hpp"
#include "lista.hpp"
#include "entidade.hpp"

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

        int colidiu(Entidade* e1, Entidade* e2);
};