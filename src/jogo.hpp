#pragma once
#include <SFML/Graphics.hpp>
#include "jogador.hpp"
#include "inimigo.hpp"
#include "listaEntidadas.hpp"
#include "fase.hpp"
#include "fase1.hpp"
#include "gerenciador_grafico.hpp"
#include "gerenciador_colisoes.hpp"

using namespace sf;

class Jogo
{
    private:
        Gerenciador_Grafico* pG;
        Gerenciador_Estados* pE; 

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