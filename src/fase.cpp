#include "../Estados/Fases/fase.hpp"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;
using namespace Obstaculos;
using namespace Personagens;
using namespace Estados;
using namespace Fases;

Fase::Fase(int pos) : jogadores(), obstaculos(), inimigos(), Estado(pos),
gC()
{
    gC.set_inimigos(&inimigos);
    gC.set_jogadores(&jogadores);
    gC.set_obstaculos(&obstaculos);
    
    //criar_jogadores();
    //criar_inimigos();
    //criar_cenario("src/cenario1.txt");
}

Fase::~Fase()
{
    //aqui pelo que eu entendi vai chamar o metodo salvar pra quando for rolar aquele teste do simao da gente sair do jogo e entrar denovo quando um projetil tiver vindo em direcao da gente tlg?
    //salvar();

}

void Fase::gerenciar_colisoes()
{
    gC.colisao_simples();
}

void Fase::criar_jogadores()
{
    //vai rolar uma parada muito louca nesse arquivo aqui quando voce for implementar o json slk
    jogadores.incluir(static_cast<Entidade*>(new Jogador(Vector2f(0.f, 0.f), Vector2f(0.f, 0.f))));
}

void Fase::criar_inimigos()
{   
    //vai rolar uma parada muito louca aqui tbm
    inimigos.incluir(static_cast<Entidade*>(new Inimigo_Facil(Vector2f(0.f, 0.f), Vector2f(0.f, 0.f))));
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
                    {
                        obstaculos.incluir(aux);
                    }
                    break;
                case '1':
                    //dados do arquivo json serao importante nesse caso aqui
                    aux = static_cast<Entidade*> (new Jogador(Vector2f(0.f, 0.f), Vector2f(0.f, 0.f)));
                    if(aux)
                    {
                        aux->setWindow(pGG->get_Janela());
                        aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                        jogadores.incluir(aux);
                    }
                    break;
                    
                case '2':
                //dados do arquivo json serao importante nesse caso aqui
                    aux = static_cast<Entidade*> (new Jogador2(Vector2f(0.f, 0.f), Vector2f(0.f, 0.f)));
                    if(aux)
                    {
                        aux->setWindow(pGG->get_Janela());
                        aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                        jogadores.incluir(aux);
                    }
                    break;
                case '3':
                //dados do arquivo json serao importante nesse caso aqui
                    aux = static_cast<Entidade*> (new Inimigo_Facil(Vector2f(0.f, 0.f), Vector2f(0.f, 0.f)));
                    if(aux)
                    {
                        aux->setWindow(pGG->get_Janela());
                        aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                        inimigos.incluir(aux);
                    }
                    break;
                case '4':
                //dados do arquivo json serao importante nesse caso aqui
                    aux = static_cast<Entidade*> (new Inimigo_Dificil(Vector2f(0.f, 0.f), Vector2f(0.f, 0.f)));
                    if(aux)
                    {
                        aux->setWindow(pGG->get_Janela());
                        aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                        inimigos.incluir(aux);
                    }
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
