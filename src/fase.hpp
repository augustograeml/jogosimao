#pragma once
#include "entidade.hpp"
#include "jogador.hpp"
#include "jogador2.hpp"
#include "inimigo_facil.hpp"
#include "inimigo_dificil.hpp"
#include "listaEntidades.hpp"
#include "obstaculo_facil.hpp"
#include "obstaculo_medio.hpp"
#include "obstaculo_dificil.hpp"
#include "gerenciador_colisoes.hpp"
#include "estado.hpp"


class Fase : public Entidade, public Estado
{
    protected:
        ListaEntidade jogadores;
        ListaEntidade obstaculos;
        ListaEntidade inimigos;
        Gerenciador_Colisoes gC;

    public:
        Fase(int i = -1);
        ~Fase();

        virtual void executar() = 0;

        void gerenciar_colisoes();
        void criar_inimigos();
        void criar_jogadores();
        void criar_cenario(string caminho);
};