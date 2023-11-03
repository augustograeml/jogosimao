#include "fase.hpp"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

Fase::Fase(int pos) : jogadores(), obstaculos(), inimigos(), Estado(pos)
{
    gC.set_inimigos(&inimigos);
    gC.set_jogadores(&jogadores);
    gC.set_obstaculos(&obstaculos);
    
    criar_jogadores();
    
    
    //this->window = w;
    //this->jogador1 = j1;
    lista_entidades = new ListaEntidade();

    inimigo1 = new Inimigo();
    //inimigo1->setWindow(w);
    inimigo1->setSkin("src/imagem/luigiDireita.png");

    inicializaELementos();
}

Fase::~Fase()
{

}

void Fase::gerenciar_colisoes()
{
    gC.colisao_simples();
}

void Fase::criar_jogadores()
{
    //jogadores.incluir(static_cast<Entidade*>(Jogador()));
}

void Fase::criar_inimigos()
{

}

void Fase::criar_cenario(string caminho)
{
    ifstream arquivo(caminho);
    if(!arquivo)
    {
        cout << "Nao foi possivel acessar o arquivo de cenario" << endl;
        exit(1);
    }

    string linha;

    Entidade* aux = nullptr;

    int j = 0, i;
    for(i = 0; getline(arquivo, linha); i++)
    {
        j = 0;
        for(char tipo : linha)
        {
            switch(tipo)
            {
                case '0':
                    aux = static_cast<Entidade*> (new Obstaculo_Facil(Vector2f(j * TAM, i * TAM)));
                    if(aux)
                        obstaculos.incluir(aux);
                    break;

                //colocar depois um case pra setar a posicao dos jogadores e um pra setar a posicao dos inimigos
                default:
                    break;
            }
            j++;
        }
    }
    arquivo.close();
}



void Fase::inicializaELementos()
{
    lista_entidades->incluir(jogador1);
    lista_entidades->incluir(inimigo1);
}