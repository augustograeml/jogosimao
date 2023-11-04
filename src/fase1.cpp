#include "fase1.hpp"

Fase1::Fase1() : Fase(1)
{
    criar_cenario(ARQUIVO_CENARIO_1);
    imagem_fundo->loadFromFile("src/imagem/fundo1.jpg");
}

Fase1::~Fase1()
{

}

void Fase1::executar()
{
    jogadores.executar();
    gerenciar_colisoes();
    pGG->centralizarCamera((*(jogadores.getPrimeiro()))->getPosicao());
    pGG->desenharFundo(imagem_fundo);
    jogadores.desenhar();
    obstaculos.desenhar();
}