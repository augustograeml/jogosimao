#include "jogo.hpp"

Jogo::Jogo():
    pG(Gerenciador_Grafico::get_instancia())
{
    jogador1 = new Jogador();
    jogador1->setWindow(pG->get_Janela());
    jogador1->setSkin("src/imagem/parado.png");

    fase1 = new Fase(jogador1, pG->get_Janela());
    lista = fase1->getlistaEntidades();

    Executar();
}
Jogo::~Jogo()
{

}

void Jogo::Executar()
{
    while (pG->get_JanelaAberta())
    {
        sf::Event event;
        while (pG->get_Janela()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pG->fecharJanela();
            else if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                    pG->fecharJanela();
            }
        }
        
        jogador1->mover();
        pG->centralizarCamera(jogador1->getPosicao());
        pG->limpar();

        for(int i = 0; i < lista->lista.geTamanho(); i++)
        {
            Entidade* auxiliar = lista->lista.getItem(i);
            auxiliar->draw();
        }
        //inimigo1.draw();
        pG->mostrar();
    }
}