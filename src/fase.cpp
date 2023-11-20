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
        gC(), buffer(), ja_criado(false)
        {
            gC.set_inimigos(&inimigos);
            gC.set_jogadores(&jogadores);
            gC.set_obstaculos(&obstaculos);
        }

        Fase::~Fase()
        {
            salvar();
        }

        bool Fase::get_jaCriado()
        {
            return ja_criado;
        }

        void Fase::gerenciar_colisoes()
        {
            gC.colisao_simples();
        }

        void Fase::criar_jogadores(bool jog2)
        {
            std::ifstream arquivo(ARQUIVO_JOGADOR);
            if (!arquivo)
            {
                std::cout << "Arquivo não existe" << std::endl;   
                exit(2);
            }

            Entidades::Entidade* p;
            Listas::Lista<Entidades::Entidade>::Iterador it = jogadores.get_primeiro();
            while(it != nullptr)
            {
                p = *it;
                jogadores.remover(p);
                it++;
                p = nullptr;
            }
            
            nlohmann::json json = nlohmann::json::parse(arquivo);

            if(!jog2)
            {
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
                                    ), false
                        )));
                }
            }

            else 
            {
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
                                    ), true
                        )));
                }
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

            Entidades::Entidade* p;
            Listas::Lista<Entidades::Entidade>::Iterador it = inimigos.get_primeiro();
            while(it != nullptr)
            {
                p = *it;
                inimigos.remover(p);
                it++;
                p = nullptr;
            }

            nlohmann::json json = nlohmann::json::parse(arquivo);

            for (auto it = json.begin(); it != json.end(); ++it)
            {
                inimigos.incluir(static_cast<Entidades::Entidade*>(new Entidades::Personagens::Zumbi(
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

        void Fase::criar_cenario(string caminho, int n1, int n2, int n3, int n4, int n5, int n6, bool ja_criado)
        {
            int count5 = 0;

            int cont[6];
            for(int i = 0; i < 7; i++)
                cont[i] = 0;

            if(!ja_criado)
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
                                aux = static_cast<Entidades::Entidade*> (new Entidades::Obstaculos::Neve(sf::Vector2f(j * TAM, i * TAM)));
                                if(aux)
                                    obstaculos.incluir(aux);
                                break;
                            case '1':
                                //dados do arquivo json serao importante nesse caso aqui
                                if(jogadores.get_primeiro() == nullptr)
                                {
                                    aux = static_cast<Entidades::Entidade*> (new Entidades::Personagens::Jogador(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), false));
                                    if(aux)
                                    {
                                        aux->setWindow(pGG->get_Janela());
                                        aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                                        jogadores.incluir(aux);
                                    }
                                }
                                break;
                                
                            case '2':
                            //dados do arquivo json serao importante nesse caso aqui
                                aux = static_cast<Entidades::Entidade*> (new Entidades::Personagens::Jogador(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), true));
                                if(aux)
                                {
                                    aux->setWindow(pGG->get_Janela());
                                    aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                                    jogadores.incluir(aux);
                                }
                                break;
                            case '3':
                            //dados do arquivo json serao importante nesse caso aqui
                                if(cont[0] < n1)
                                {
                                    aux = static_cast<Entidades::Entidade*> (new Entidades::Personagens::Zumbi(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f)));
                                    if(aux)
                                    {
                                            aux->setWindow(pGG->get_Janela());
                                            aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                                            inimigos.incluir(aux);
                                    }
                                    cont[0]++;
                                }
                                break;
                            case '4':
                            //dados do arquivo json serao importante nesse caso aqui
                                if(cont[1] < n2)
                                {
                                    aux = static_cast<Entidades::Entidade*> (new Entidades::Personagens::Arqueiro(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f)));
                                    if(aux)
                                    {
                                        aux->setWindow(pGG->get_Janela());
                                        aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                                        inimigos.incluir(aux);
                                    }
                                    cont[1]++;
                                }
                                break;

                            case '5':
                                if(cont[2] < n3)
                                {
                                    aux = static_cast<Entidades::Entidade*> (new Entidades::Obstaculos::Espinho(Vector2f(j * TAM, i * TAM)));
                                    if(aux)
                                        obstaculos.incluir(aux);
                                    cont[2]++;
                                }
                            break;
                            case '6':
                                if(cont[3] < n4)
                                {
                                    aux = static_cast<Entidades::Entidade*> (new Entidades::Obstaculos::Coracao(Vector2f(j * TAM, i * TAM)));
                                    if(aux)
                                        obstaculos.incluir(aux);
                                    cont[3]++;
                                }    
                                break;

                            case '7':
                                aux = static_cast<Entidades::Entidade*> (new Entidades::Obstaculos::Musgo(Vector2f(j * TAM, i * TAM)));
                                if(aux)
                                    obstaculos.incluir(aux);
                                break;

                            case '8':
                                //if vet < n5
                                aux = static_cast<Entidades::Entidade*> (new Entidades::Obstaculos::Caixa(Vector2f(j * TAM, i * TAM)));
                                if(cont[4] < n5)
                                {
                                    if(aux)
                                        obstaculos.incluir(aux);
                                    cont[4]++;
                                }
                                break;
                            case '9':
                            //if vet < n6
                                aux = static_cast<Entidades::Entidade*> (new Entidades::Personagens::Gigante(sf::Vector2f(sf::Vector2f(0.f, 0.f)), sf::Vector2f(0.f, 0.f)));
                                if(cont[5] < n6)
                                {
                                    if(aux)
                                    {
                                        aux->setWindow(pGG->get_Janela());
                                        aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                                        inimigos.incluir(aux);
                                    }
                                    cont[5]++;
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

                ja_criado = true;
            }
        }

        void Fase::fim_de_jogo()
        {
            
        }

        void Fase::salvar()
        {
            // Salvando Jogadores:

            std::ofstream arquivo(ARQUIVO_JOGADOR/*, std::ios::out | std::ios::trunc*/);  
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