#pragma once
#include <SFML/Graphics.hpp>
#include "jogador.hpp"
#include "inimigo.hpp"
#include "listaEntidadas.hpp"
#include "fase.hpp"
#include "gerenciador_grafico.hpp"

class Jogo
{
    private:
        Gerenciador_Grafico* pG;
        Jogador* jogador1;
        ListaEntidade* lista;
        Fase* fase1;
        sf::Texture t[27];
        
    public:
        Jogo();
        ~Jogo();

        void Executar();
};