#include "jogo.hpp"

Jogo::Jogo():
    window(sf::VideoMode(1000, 1000), "Zombies++")
{
    jogador1 = new Jogador();
    jogador1->setWindow(&window);
    jogador1->setSkin("imagem/mario.png");

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
            else if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
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