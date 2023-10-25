#pragma once
#include "jogador.hpp"
#include "inimigo.hpp"
#include "listaEntidadas.hpp"
#include <SFML/Graphics.hpp>

class Fase
{
    private:
        ListaEntidade* lista_entidades;
        Jogador* jogador1;
        Inimigo* inimigo1;
        sf::RenderWindow* window;

    public:
        Fase(Jogador* j1, sf::RenderWindow* w);
        ~Fase();

        void inicializaELementos(); 
        ListaEntidade* getlistaEntidades() {return lista_entidades;}
};