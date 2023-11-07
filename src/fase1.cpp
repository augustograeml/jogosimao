#include "fase1.hpp"
#include <iostream>

using namespace std;

Fase1::Fase1() : Fase(1)
{
    criar_cenario(ARQUIVO_CENARIO_1);
    //imagem_fundo->loadFromFile("src/imagem/fundo1.jpg");
    //sprite.setTexture(*imagem_fundo);
    //sprite.setPosition(sf::Vector2f(0,0));
    //sprite.setScale(2,2);
}

Fase1::~Fase1()
{

} 

void Fase1::executar()
{
    gerenciar_colisoes();
    jogadores.executar();
    inimigos.executar();
    pGG->centralizarCamera((*(jogadores.get_primeiro()))->getPosicao());
    //pGG->desenharFundo(&sprite);
    obstaculos.desenhar();
    inimigos.desenhar();
    jogadores.desenhar();
}