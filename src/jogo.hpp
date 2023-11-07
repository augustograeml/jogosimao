#pragma once
#include <SFML/Graphics.hpp>
#include "fase1.hpp"
#include "gerenciador_grafico.hpp"
#include "gerenciador_estados.hpp"
#include "gerenciador_eventos.hpp"
#include "observer_tecla.hpp"

using namespace sf;

class Jogo
{
    private:
        Gerenciador_Grafico* pG;
        Gerenciador_Estados* pE;
        Gerenciador_Eventos* pEv;

        Observer_Tecla obs1;
        Observer_Tecla obs2;

        /*Jogador* jogador1;
        Jogador* jogador2;
        ListaEntidade* lista;
        Fase* fase1;
        Texture t[27];
        Texture imagem_de_fundo;*/
        
    public:
        Jogo();
        ~Jogo();

        void Executar();
};