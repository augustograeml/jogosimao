#include "jogo.hpp"
#include <iostream>

using namespace std;

Jogo::Jogo():
    pG(Gerenciador_Grafico::get_instancia()), pE(Gerenciador_Estados::get_instancia()), pEv(Gerenciador_Eventos::get_instancia())
{   
    
   
   Fase1* fase1 = new Fase1();
   fase1->setWindow(pG->get_Janela());

    /*jogador1 = new Jogador();
    jogador1->setWindow(pG->get_Janela());
    jogador1->setSkin("src/imagem/parado.png");

    jogador2 = new Jogador();
    jogador2->setWindow(pG->get_Janela());
    jogador2->setSkin("src/imagem/mario.png");

    //fase1 = new Fase(jogador1, jogador2, pG->get_Janela());
    lista = fase1->getlistaEntidades();

    imagem_de_fundo.loadFromFile("src/imagem/palmeiras.png");   */

    Executar();
}
Jogo::~Jogo()
{
    delete pG;
    delete pE;
    delete pEv;
}

void Jogo::Executar()
{    
    

    while (pG->get_JanelaAberta())
    {
       
        //maracutaia do indio juca
        //fase1->executar();
        pG->limpar();
        pEv->executar();
        pE->executar();     //desenha a fase e o jogador 
        pG->mostrar();
             
        
        /*Event event;
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
        
        pG->mostrar();*/
    }
}