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
            Listas::ListaEntidade* arqueiros;
            Listas::ListaEntidade* projeteis;

            bool sem_inimigos;
            bool sem_jogadores;
        public:
            Gerenciador_Colisoes();
            ~Gerenciador_Colisoes();

            void set_obstaculos(Listas::ListaEntidade* obs) {if(obs) obstaculos = obs;}
            void set_jogadores(Listas::ListaEntidade* jog) {if(jog) jogadores = jog;}
            void set_inimigos(Listas::ListaEntidade* ini) {if(ini) inimigos = ini;}
            void set_arqueiros(Listas::ListaEntidade* arq) {if(arq) arqueiros = arq;}
            void set_projeteis(Listas::ListaEntidade* proj) {if(proj) projeteis = proj;}

            void colisao_simples();
            int colidiu(Entidades::Entidade* e1, Entidades::Entidade* e2);

            bool get_sem_inimigos();
            bool get_sem_jogadores() {return sem_jogadores;}
    };
}