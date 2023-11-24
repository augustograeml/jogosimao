//codigo reaproveitado do Peteco

#pragma once
#include "../Listas/listaEntidades.hpp"
#include "../Entidades/entidade.hpp"
#include <iostream>
using namespace std;

namespace Gerenciadores
{
    class Gerenciador_Colisoes
    {
        private:
            Listas::ListaEntidade* obstaculos;
            Listas::ListaEntidade* jogadores;
            Listas::ListaEntidade* inimigos;
            Listas::ListaEntidade* projeteis;

            bool sem_inimigos;
            bool sem_jogadores;
        public:
            Gerenciador_Colisoes();
            ~Gerenciador_Colisoes();

            void set_obstaculos(Listas::ListaEntidade* obs) {if(obs) obstaculos = obs;}
            void set_jogadores(Listas::ListaEntidade* jog) {if(jog) jogadores = jog;}
            void set_inimigos(Listas::ListaEntidade* ini) {if(ini) inimigos = ini;}
            void set_projeteis(Listas::ListaEntidade* proj) {if(proj) projeteis = proj;}

            void colisao_jogadores_obstaculos();
            void colisao_jogadores_inimigos();
            void colisao_inimigos_obstaculos();
            void colisao_jogadores_projeteis();
            void colisao_obstaculos_projeteis();
            void gerenciar_colisoes();
            int colidiu(Entidades::Entidade* e1, Entidades::Entidade* e2);

            const bool get_inimigos_vivos();
            const bool get_jogadores_vivos();
    };
}