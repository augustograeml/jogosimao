#include "jogo.hpp"

Jogo::Jogo():
    window(sf::VideoMode(800, 800), "Mario x Luigi")
{
    jogador1.setWindow(&window);
    jogador1.setSkin("imagem/mario.png");
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
        
        jogador1.mover();
        window.clear();
        jogador1.draw();
        window.display();
    }
}