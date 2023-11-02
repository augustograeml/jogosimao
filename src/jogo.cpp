#include "jogo.hpp"

Jogo::Jogo():
    pG(Gerenciador_Grafico::get_instancia())
{   
    jogador1 = new Jogador();
    jogador1->setWindow(pG->get_Janela());
    jogador1->setSkin("src/imagem/parado.png");

    jogador2 = new Jogador();
    jogador2->setWindow(pG->get_Janela());
    jogador2->setSkin("src/imagem/mario.png");

    fase1 = new Fase(jogador1, jogador2, pG->get_Janela());
    lista = fase1->getlistaEntidades();

    imagem_de_fundo.loadFromFile("src/imagem/palmeiras.png");   

    Executar();
}
Jogo::~Jogo()
{

}

void Jogo::Executar()
{    
    while (pG->get_JanelaAberta())
    {
        Event event;
        while (pG->get_Janela()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pG->fecharJanela();
            else if(event.type == Event::KeyPressed)
            {
                if(event.key.code == Keyboard::Escape)
                    pG->fecharJanela();
            }
        }
        
        

        jogador1->mover();
        pG->centralizarCamera(jogador1->getPosicao());
        pG->limpar();

        pG->desenharTextura(&imagem_de_fundo);

        for(int i = 0; i < lista->lista.geTamanho(); i++)
        {
            Entidade* auxiliar = lista->lista.getItem(i);
            auxiliar->draw();
        }
        
        pG->mostrar();
    }
}