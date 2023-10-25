#include "fase.hpp"

Fase::Fase(Jogador* j1, sf::RenderWindow* w)
{
    this->window = w;
    this->jogador1 = j1;
    lista_entidades = new ListaEntidade();

    inimigo1 = new Inimigo();
    inimigo1->setWindow(window);
    inimigo1->setSkin("src/imagem/luigiDireita.png");

    inicializaELementos();
}

Fase::~Fase()
{
}

void Fase::inicializaELementos()
{
    lista_entidades->lista.incluir(jogador1);
    lista_entidades->lista.incluir(inimigo1);
}