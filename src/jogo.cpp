#include "jogo.hpp"

Jogo::Jogo():
    pG(Gerenciador_Grafico::get_instancia())
{
    jogador1 = new Jogador();
    jogador1->setWindow(pG->get_Janela());
    jogador1->setSkin("src/imagem/parado.png");

    fase1 = new Fase(jogador1, pG->get_Janela());
    lista = fase1->getlistaEntidades();

    t[0].loadFromFile("src/imagem/op1.png");
    t[1].loadFromFile("src/imagem/op2.png");
    t[2].loadFromFile("src/imagem/op3.png");
    t[3].loadFromFile("src/imagem/op4.png");
    t[4].loadFromFile("src/imagem/op5.png");
    t[5].loadFromFile("src/imagem/op6.png");
    t[6].loadFromFile("src/imagem/op7.png");
    t[7].loadFromFile("src/imagem/op8.png");
    t[8].loadFromFile("src/imagem/op9.png");
    t[9].loadFromFile("src/imagem/op10.png");
    t[10].loadFromFile("src/imagem/op11.png");
    t[11].loadFromFile("src/imagem/op12.png");
    t[12].loadFromFile("src/imagem/op13.png");
    t[13].loadFromFile("src/imagem/op14.png");
    t[14].loadFromFile("src/imagem/op15.png");
    t[15].loadFromFile("src/imagem/op16.png");
    t[16].loadFromFile("src/imagem/op17.png");
    t[17].loadFromFile("src/imagem/op18.png");
    t[18].loadFromFile("src/imagem/op19.png");
    t[19].loadFromFile("src/imagem/op20.png");
    t[20].loadFromFile("src/imagem/op21.png");
    t[21].loadFromFile("src/imagem/op22.png");
    t[22].loadFromFile("src/imagem/op23.png");
    t[23].loadFromFile("src/imagem/op24.png");
    t[24].loadFromFile("src/imagem/op25.png");
    t[25].loadFromFile("src/imagem/op26.png");
    t[26].loadFromFile("src/imagem/op27.png");

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