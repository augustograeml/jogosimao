#include "../Estados/Fases/fase.hpp"

#include <fstream>
#include <string>
#include <iostream>

#define ARQUIVO_JOGADOR "jogador.json"
#define ARQUIVO_INIMIGOS "inimigos.json"
#define ESTADO_ATUAL "estado_atual.txt"

using namespace std;

namespace Estados
{
    namespace Fases
    {

        Fase::Fase(int id, bool ja) : jogadores(), obstaculos(), inimigos(),
        Estado(id), ja_criado(ja),
        gC(), buffer(), num_jogadores(1), num_arqueiros(0),
        num_gigante(0), num_obstaculos(0), num_zumbis(0)
        {
            gC.set_inimigos(&inimigos);
            gC.set_jogadores(&jogadores);
            gC.set_obstaculos(&obstaculos);

            if (!ja_criado)
                criar_jogadores();
            else
            {
                carregar_jogadores_salvos();
                carregar_inimigos_salvos();
            }

            relogio.restart();

            for (int i = 0; i < 4; i++)
                numero_entidades_salvamento[i] = 0;
        }

        Fase::~Fase()
        {
            if(pGE->get_estado_atual() == Estado::id)
                salvar();
        }

        const bool Fase::get_jaCriado()
        {
            return ja_criado;
        }

        void Fase::gerenciar_colisoes()
        {
            gC.gerenciar_colisoes();
        }

        void Fase::criar_jogadores()
        {
            if (get_jogador2())
            {
                // bagui pode duplicar aq, cuidado
                Entidades::Personagens::Jogador *jgd1 = new Entidades::Personagens::Jogador({80, 50}, {0, 0}, false);
                Entidades::Personagens::Jogador *jgd2 = new Entidades::Personagens::Jogador({150, 50}, {0, 0}, true);
                jogadores.incluir(static_cast<Entidades::Entidade *>(jgd1));
                jogadores.incluir(static_cast<Entidades::Entidade *>(jgd2));
            }
            else
            {
                Entidades::Personagens::Jogador *jgd1 = new Entidades::Personagens::Jogador({80, 50}, {0, 0}, false);
                jogadores.incluir(static_cast<Entidades::Entidade *>(jgd1));
            }
        }

        void Fase::criar_inimigos(string cenario)
        {
            std::ifstream arquivo(cenario);
            if (!arquivo)
            {
                std::cout << "Arquivo não existe" << std::endl;
                exit(2);
            }

            int num[2], cont[2] = {0, 0};
            for(int i = 0; i < 2; i++)
            {
                num[i] = (int)rand() % 3 + 3;
            }

            string linha;
            Entidades::Entidade *aux = nullptr;
            int j = 0, i;
            for (i = 0; getline(arquivo, linha); i++)
            {
                j = 0;
                for (char tipo : linha)
                {
                    switch (tipo)
                    {
                    case '3':
                        // dados do arquivo json serao importante nesse caso aqui
                        /*if (contador_inimigos[0] < numero_inimigos[0])
                        {*/
                            aux = static_cast<Entidades::Entidade *>(new Entidades::Personagens::Zumbi(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f)));
                            if (aux)
                            {
                                aux->setWindow(pGG->get_Janela());
                                aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                                inimigos.incluir(aux);
                            }
                            //contador_inimigos[0]++;
                            num_zumbis++;
                       // }
                        break;
                    case '4':
                        // dados do arquivo json serao importante nesse caso aqui
                        /*if (contador_inimigos[1] < numero_inimigos[1])
                        {*/
                            aux = static_cast<Entidades::Entidade *>(new Entidades::Personagens::Arqueiro(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f)));
                            if (aux)
                            {
                                aux->setWindow(pGG->get_Janela());
                                aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                                inimigos.incluir(aux);
                            }
                            //contador_inimigos[1]++;
                            num_arqueiros++;
                        //}
                        break;
                    case '9':
                        // if vet < n6
                        aux = static_cast<Entidades::Entidade *>(new Entidades::Personagens::Gigante(sf::Vector2f(sf::Vector2f(0.f, 0.f)), sf::Vector2f(0.f, 0.f)));
                        /*if (contador_inimigos[2] < numero_inimigos[2])
                        {*/
                            if (aux)
                            {
                                aux->setWindow(pGG->get_Janela());
                                aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                                inimigos.incluir(aux);
                            }
                            //contador_inimigos[2]++;
                            num_gigante++;
                        //}
                        break;

                    // colocar depois um case pra setar a posicao dos jogadores e um pra setar a posicao dos inimigos
                    default:
                        break;
                    }
                    j++;
                }
            }
            arquivo.close();
        }

        void Fase::carregar_jogadores_salvos()
        {
            std::ifstream arquivo(ARQUIVO_JOGADOR);
            if (!arquivo)
            {
                std::cout << "Arquivo não existe" << std::endl;
                exit(2);
            }

            nlohmann::json json = nlohmann::json::parse(arquivo);

            auto jogadores_json = json["jogadores"];

            auto jogador = jogadores_json[0];

            float posx = jogador["posicao"][0];
            float posy = jogador["posicao"][1];
            float velx = jogador["velocidade"][0];
            float vely = jogador["velocidade"][1];

            if (get_jogador2())
            {
                auto jogador = jogadores_json[1];

                float posicao_x = jogador["posicao"][0];
                float posicao_y = jogador["posicao"][1];
                float velocidade_x = jogador["velocidade"][0];
                float velocidade_y = jogador["velocidade"][1];

                // ve se nao vai duplicar aqui
                Entidades::Personagens::Jogador *jgd2 = new Entidades::Personagens::Jogador(sf::Vector2f(posicao_x, posicao_y),
                                                                                            sf::Vector2f(velocidade_x, velocidade_y),
                                                                                            true);

                jogadores.incluir(static_cast<Entidades::Entidade *>(jgd2));
            }
        }

        void Fase::carregar_inimigos_salvos()
        {
            std::ifstream arquivo(ARQUIVO_INIMIGOS);
            if (!arquivo)
            {
                std::cout << "Arquivo não existe" << std::endl;
                exit(2);
            }

            nlohmann::json json = nlohmann::json::parse(arquivo);

            num_arqueiros = json["numero_atiradores"];
            num_zumbis = json["numero_zumbis"];
            num_gigante = json["numero_gigantes"];

            // zumbi = 5, atirador = 4, gigante = 9

            auto membros = json["membros"];
            for (int i = 0; i < membros.size(); i++)
            {
                int identificador = membros[i]["identidade"];

                float posx = membros[i]["posicao"][0];
                float posy = membros[i]["posicao"][1];
                float velx = membros[i]["velocidade"][0];
                float vely = membros[i]["velocidade"][1];

                sf::Vector2f pos = sf::Vector2f(posx, posy);
                sf::Vector2f vel = sf::Vector2f(velx, vely);

                if (identificador == 5)
                {
                    inimigos.incluir(static_cast<Entidades::Entidade *>(new Entidades::Personagens::Zumbi(pos, vel)));
                }
                else if (identificador == 4)
                {
                    Entidades::Personagens::Arqueiro *arq = new Entidades::Personagens::Arqueiro(pos, vel);
                    std::vector<Entidades::Projetil> *pVetor_projeteis = arq->get_projeteis();

                    auto projeteis = membros[i]["projeteis"];

                    for (int j = 0; i < projeteis.size(); i++)
                    {
                        float posx_proj = projeteis[j]["posicao"][0];
                        float posy_proj = projeteis[j]["posicao"][1];
                        bool dir = projeteis[j]["direcao"];

                        sf::Vector2f pos_proj = sf::Vector2f(posx_proj, posy_proj);

                        Entidades::Projetil *proj = new Entidades::Projetil(pos_proj, dir);
                        pVetor_projeteis->push_back(*proj);
                    }
                    inimigos.incluir(static_cast<Entidades::Entidade *>(arq));
                }
                else if (identificador == 9)
                {
                    Entidades::Personagens::Gigante *gig = new Entidades::Personagens::Gigante(pos, vel);
                }
            }
        }

        void Fase::criar_cenario(string caminho/*, int numero_espinhos, int numero_coracao, int numero_caixas*/)
        {
            int cont[3];
            for (int i = 0; i < 3; i++)
                cont[i] = 0;

            ifstream arquivo(caminho);
            if (!arquivo)
            {
                cout << "Nao foi possivel acessar o arquivo de cenario" << endl;
                exit(1);
            }

            std::string linha;

            Entidades::Entidade *aux = nullptr;
            int j = 0, i;
            for (i = 0; getline(arquivo, linha); i++)
            {
                j = 0;
                for (char tipo : linha)
                {
                    switch (tipo)
                    {
                    case '0':
                        aux = static_cast<Entidades::Entidade *>(new Entidades::Obstaculos::Neve(sf::Vector2f(j * TAM, i * TAM)));
                        if (aux)
                            obstaculos.incluir(aux);
                        break;

                    case '5':
                        //if (cont[0] < numero_espinhos)
                        {
                            aux = static_cast<Entidades::Entidade *>(new Entidades::Obstaculos::Espinho(Vector2f(j * TAM, i * TAM)));
                            if (aux)
                                obstaculos.incluir(aux);
                           // cont[0]++;
                        }
                        break;
                    case '6':
                        //if (cont[1] < numero_coracao)
                        {
                            aux = static_cast<Entidades::Entidade *>(new Entidades::Obstaculos::Coracao(Vector2f(j * TAM, i * TAM)));
                            if (aux)
                                obstaculos.incluir(aux);
                          //  cont[1]++;
                        }
                        break;

                    case '7':
                        aux = static_cast<Entidades::Entidade *>(new Entidades::Obstaculos::Musgo(Vector2f(j * TAM, i * TAM)));
                        if (aux)
                            obstaculos.incluir(aux);
                        break;

                    case '8':
                        // if vet < n5
                        aux = static_cast<Entidades::Entidade *>(new Entidades::Obstaculos::Caixa(Vector2f(j * TAM, i * TAM)));
                        //if (cont[2] < numero_caixas)
                        {
                            if (aux)
                                obstaculos.incluir(aux);
                          //  cont[2]++;
                        }
                        break;

                    // colocar depois um case pra setar a posicao dos jogadores e um pra setar a posicao dos inimigos
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
            // salvando os jogadores
            std::ofstream arquivo(ARQUIVO_JOGADOR);
            if (!arquivo)
            {
                std::cout << "Arquivo não existe" << std::endl;
                exit(1);
            }

            arquivo << "";

            Listas::Lista<Entidades::Entidade>::Iterador j = jogadores.get_primeiro();

            buffer.str("");
            buffer << "{ \"jogo\": \"jogo\" ,\"fase\": 1, ";

            if (pGE->get_estado_atual() == 6 || pGE->get_estado_atual() == 7)
                buffer << " 1, ";

            else if (pGE->get_estado_atual() == 8 || pGE->get_estado_atual() == 9)
                buffer << " 2, ";

            if (get_jogador2())
                buffer << "\"numero_jogadores\": 1, \"jogadores\": [";
            else
                buffer << "\"numero_jogadores\": 2, \"jogadores\": [";

            if (j != nullptr)
            {
                ((*j))->salvar(&buffer);
                j++;
            }
            while (j != nullptr)
            {
                buffer << ",";
                ((*j))->salvar(&buffer);
                j++;
            }
            buffer << "]}";
            arquivo << buffer.str();
            arquivo.close();

            // Salvando Inimigos
            std::ofstream arquivo_inimigo(ARQUIVO_INIMIGOS);
            if (!arquivo_inimigo)
            {
                std::cout << "Problema em salvar o arquivo dos inimigos" << std::endl;
                exit(1);
            }

            Listas::Lista<Entidades::Entidade>::Iterador ini = inimigos.get_primeiro();
            buffer.str("");
            buffer << "{ \"numero_zumbis\": " << num_zumbis << ", \"numero_atiradores\": " << num_arqueiros << ", \"numero_gigantes\": " << num_gigante << ", \"membros\": [ " << endl;
            if (ini != nullptr)
            {
                (*ini)->salvar(&buffer);
                ini++;
            }
            while (ini != nullptr)
            {
                buffer << ",";
                (*ini)->salvar(&buffer);
                ini++;
            }
            buffer << "]}";
            arquivo_inimigo << buffer.str();
            arquivo_inimigo.close();

            // nas ferias fazer um json pra cada tipo de inimigo pra ficar menos "feio"
        }

        const bool Fase::get_jogador2()
        {
            if (num_jogadores > 1)
                jogador2 = true;
            else
                jogador2 = false;

            return jogador2;
        }

        void Fase::set_tempo_jogadores()
        {
            if (num_jogadores == 2)
            {
                Entidades::Personagens::Jogador *jogad2 = static_cast<Entidades::Personagens::Jogador *>(*jogadores.get_primeiro()++);
                jogad2->set_tempo(relogio.getElapsedTime().asSeconds());
            }
            Entidades::Personagens::Jogador *jogad = static_cast<Entidades::Personagens::Jogador *>(*jogadores.get_primeiro());
            jogad->set_tempo(jogad->get_tempo() + relogio.getElapsedTime().asSeconds());
        }

    }
}