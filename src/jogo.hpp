#pragma once
#include <SFML/Graphics.hpp>
#include "fase1.hpp"
#include "gerenciador_grafico.hpp"
#include "gerenciador_colisoes.hpp"
#include "gerenciador_eventos.hpp"

using namespace sf;

class Jogo
{
    private:
        Gerenciador_Grafico* pG;
        Gerenciador_Estados* pE;
        Gerenciador_Eventos* pEv;

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