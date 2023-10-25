#pragma once
#include <SFML/Graphics.hpp>
#include "jogador.hpp"
#include "inimigo.hpp"
#include "listaEntidadas.hpp"
#include "fase.hpp"

class Jogo
{
    private:
        sf::RenderWindow window;
        Jogador* jogador1;
        ListaEntidade* lista;
        Fase* fase1;

        
    public:
        Jogo();
        ~Jogo();

        void Executar();
};