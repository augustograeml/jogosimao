#pragma once
#include "entidade.hpp"
#include "jogador.hpp"
#include "inimigo.hpp"
#include "listaEntidadas.hpp"
#include "obstaculo_facil.hpp"
#include "gerenciador_colisoes.hpp"
#include "estado.hpp"

class Fase : public Entidade, public Estado
{
    protected:
        ListaEntidade* lista_entidades;
        ListaEntidade jogadores;
        ListaEntidade obstaculos;
        ListaEntidade inimigos;
        Gerenciador_Colisoes gC;
        Jogador* jogador1;
        Inimigo* inimigo1;
        sf::RenderWindow* window;

    public:
        Fase(int i = -1);
        //Fase(Jogador* j1, Jogador* j2, sf::RenderWindow* w);
        ~Fase();

        virtual void executar() = 0;
        void gerenciar_colisoes();
        void criar_jogadores();
        void criar_inimigos();
        void criar_cenario(string caminho);

        void inicializaELementos(); 
        ListaEntidade* getlistaEntidades() {return lista_entidades;}
};