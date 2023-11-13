#include "../Estados/Fases/fase.hpp"

#include <fstream>
#include <string>
#include <iostream>

#define ARQUIVO_JOGADOR "jogador.json"
#define ARQUIVO_INIMIGO "inimigo.json"

using namespace std;

namespace Estados
{
    namespace Fases
    {
        Fase::Fase(int pos) : jogadores(), obstaculos(), inimigos(), Estado(pos),
        gC(), buffer()
        {
            gC.set_inimigos(&inimigos);
            gC.set_jogadores(&jogadores);
            gC.set_obstaculos(&obstaculos);

            //se descomentar rola mitose aqui
            /*criar_jogadores();
            criar_inimigos();*/
        }

        Fase::~Fase()
        {
            //aqui pelo que eu entendi vai chamar o metodo salvar pra quando for rolar aquele teste do simao da gente sair do jogo e entrar denovo quando um projetil tiver vindo em direcao da gente tlg?
            salvar();
        }

        void Fase::gerenciar_colisoes()
        {
            gC.colisao_simples();
        }

        void Fase::criar_jogadores()
        {
            std::ifstream arquivo(ARQUIVO_JOGADOR);
            if (!arquivo)
            {
                std::cout << "Arquivo não existe" << std::endl;   
                exit(2);
            }

            nlohmann::json json = nlohmann::json::parse(arquivo);

            for (auto it = json.begin(); it != json.end(); ++it)
            {
                jogadores.incluir(static_cast<Entidades::Entidade*>(new Entidades::Personagens::Jogador(
                    sf::Vector2f(
                        (float) ((*it)["posicao"][0]), 
                        (float) ((*it)["posicao"][1])
                                ),
                    sf::Vector2f(
                        (float) ((*it)["velocidade"][0]),
                        (float) ((*it)["velocidade"][1])
                                )
                    )));
            }
        }

        void Fase::criar_inimigos()
        {   
            std::ifstream arquivo(ARQUIVO_INIMIGO);
            if (!arquivo)
            {
                std::cout << "Arquivo não existe" << std::endl;   
                exit(2);
            }

            nlohmann::json json = nlohmann::json::parse(arquivo);

            for (auto it = json.begin(); it != json.end(); ++it)
            {
                inimigos.incluir(static_cast<Entidades::Entidade*>(new Entidades::Personagens::Inimigo_Facil(
                    sf::Vector2f(
                        (float) ((*it)["posicao"][0]), 
                        (float) ((*it)["posicao"][1])
                                ),
                    sf::Vector2f(
                        (float) ((*it)["velocidade"][0]),
                        (float) ((*it)["velocidade"][1])
                                )
                    )));
            }
        }

        void Fase::criar_cenario(string caminho)
        {
            ifstream arquivo(caminho);
            if(!arquivo)
            {
                cout << "Nao foi possivel acessar o arquivo de cenario" << endl;
                exit(1);
            }

            std::string linha;

            Entidades::Entidade* aux = nullptr;

            int j = 0, i;
            for(i = 0; getline(arquivo, linha); i++)
            {
                j = 0;
                for(char tipo : linha)
                {
                    switch(tipo)
                    {
                        case '0':
                            aux = static_cast<Entidades::Entidade*> (new Entidades::Obstaculos::Obstaculo_Facil(sf::Vector2f(j * TAM, i * TAM)));
                            if(aux)
                            {
                                obstaculos.incluir(aux);
                            }
                            break;
                        case '1':
                            //dados do arquivo json serao importante nesse caso aqui
                            aux = static_cast<Entidades::Entidade*> (new Entidades::Personagens::Jogador(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f)));
                            if(aux)
                            {
                                aux->setWindow(pGG->get_Janela());
                                aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                                jogadores.incluir(aux);
                            }
                            break;
                            
                        case '2':
                        //dados do arquivo json serao importante nesse caso aqui
                            aux = static_cast<Entidades::Entidade*> (new Entidades::Personagens::Jogador2(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f)));
                            if(aux)
                            {
                                aux->setWindow(pGG->get_Janela());
                                aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                                jogadores.incluir(aux);
                            }
                            break;
                        case '3':
                        //dados do arquivo json serao importante nesse caso aqui
                            aux = static_cast<Entidades::Entidade*> (new Entidades::Personagens::Inimigo_Facil(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f)));
                            if(aux)
                            {
                                aux->setWindow(pGG->get_Janela());
                                aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                                inimigos.incluir(aux);
                            }
                            break;
                        case '4':
                        //dados do arquivo json serao importante nesse caso aqui
                            aux = static_cast<Entidades::Entidade*> (new Entidades::Personagens::Inimigo_Dificil(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f)));
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

        void Fase::salvar()
        {
            // Salvando Jogadores:
            std::ofstream arquivo(ARQUIVO_JOGADOR);  
            if (!arquivo)
            {
                std::cout << "Problema em salvar o arquivo" << std::endl;
                exit(1);
            }

            Listas::Lista<Entidades::Entidade>::Iterador j = jogadores.get_primeiro();
            buffer.str("");
            buffer << "[";
            if (j != nullptr)
            {
                (*j)->salvar(&buffer);
                j++;
            }
            while (j != nullptr)
            {
                buffer << ",";
                (*j)->salvar(&buffer);
                j++;
            }
            buffer << "]";

            arquivo << buffer.str();

            arquivo.close();
            // Salvando inimigos: 

            std::ofstream arquivo_inimigo(ARQUIVO_INIMIGO);  
            if (!arquivo_inimigo)
            {
                std::cout << "Problema em salvar o arquivo" << std::endl;
                exit(1);
            }

            Listas::Lista<Entidades::Entidade>::Iterador i = inimigos.get_primeiro();
            buffer.str("");
            buffer << "[";
            if (i != nullptr)
            {
                (*i)->salvar(&buffer);
                i++;
            }
            while (i != nullptr)
            {
                buffer << ",";
                (*i)->salvar(&buffer);
                i++;
            }
            buffer << "]";

            arquivo_inimigo << buffer.str();

            arquivo_inimigo.close();
        }
    }
}