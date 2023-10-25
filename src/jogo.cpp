#include "jogo.hpp"

Jogo::Jogo():
    window(sf::VideoMode(800, 800), "Mario x Luigi")
{
    jogador1 = new Jogador();
    jogador1->setWindow(&window);
    jogador1->setSkin("src/imagem/mario.png");

    fase1 = new Fase(jogador1, &window);
    lista = fase1->getlistaEntidades();

    

    Executar();
}
Jogo::~Jogo()
{

}

void Jogo::Executar()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        jogador1->mover();
        window.clear();

        for(int i = 0; i < lista->lista.geTamanho(); i++)
        {
            Entidade* auxiliar = lista->lista.getItem(i);
            auxiliar->draw();
        }
        //inimigo1.draw();
        window.display();
    }
}