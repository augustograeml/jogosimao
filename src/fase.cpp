#include "../Estados/Fases/fase.hpp"

#include <fstream>
#include <string>
#include <iostream>

#define ARQUIVO_JOGADOR "jogador.json"
#define ARQUIVO_ZUMBI "zumbi.json"
#define ARQUIVO_GIGANTE "gigante.json"
#define ARQUIVO_ATIRADOR "atirador.json"
#define ARQUIVO_PROJETEIS "projeteis.json"
#define ESTADO_ATUAL "estado_atual.txt"

using namespace std;

namespace Estados
{
    namespace Fases
    {

        Fase::Fase(int id) : jogadores(), obstaculos(), inimigos(), Estado(id),
                             gC(), buffer(), ja_criado(false), num_jogadores(1)
        {
            gC.set_inimigos(&inimigos);
            gC.set_jogadores(&jogadores);
            gC.set_obstaculos(&obstaculos);
            gC.set_zumbis(&zumbis);
            gC.set_atiradores(&atiradores);
            gC.set_gigantes(&gigantes);
            relogio.restart();
        }

        Fase::~Fase()
        {
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

        void Fase::criar_jogadores(bool jog2)
        {
            std::ifstream arquivo(ARQUIVO_JOGADOR);
            if (!arquivo)
            {
                std::cout << "Arquivo não existe" << std::endl;
                exit(2);
            }

            Entidades::Entidade *p;
            Listas::Lista<Entidades::Entidade>::Iterador it = jogadores.get_primeiro();
            while (it != nullptr)
            {
                p = *it;
                jogadores.remover(p);
                it++;
                p = nullptr;
            }

            nlohmann::json json = nlohmann::json::parse(arquivo);

            for (auto it = json.begin(); it != json.end(); ++it)
            {
                //aquei ele roda a quantidade de jogadores que tem no json, por isso ta rolando a mitose
                //vou criar um json especifico pro jogador2, mas acho q isso n eh o mais certo a se fazer
                jogadores.incluir(static_cast<Entidades::Entidade *>(new Entidades::Personagens::Jogador(
                    sf::Vector2f(
                        (float)((*it)["posicao"][0]),
                        (float)((*it)["posicao"][1])),

                    sf::Vector2f(
                        (float)((*it)["velocidade"][0]),
                        (float)((*it)["velocidade"][1])),

                    false)));
            }

            if (jog2)
            {
                for (auto it = json.begin(); it != json.end(); ++it)
                {
                    jogadores.incluir(static_cast<Entidades::Entidade *>(new Entidades::Personagens::Jogador(
                        sf::Vector2f(
                            (float)((*it)["posicao"][0]),
                            (float)((*it)["posicao"][1])),

                        sf::Vector2f(
                            (float)((*it)["velocidade"][0]),
                            (float)((*it)["velocidade"][1])),

                        true)));
                }
            }
        }

        void Fase::criar_inimigos()
        {
            std::ifstream arquivo(ARQUIVO_ZUMBI);
            if (!arquivo)
            {
                std::cout << "Arquivo não existe" << std::endl;
                exit(2);
            }

            Entidades::Entidade *p;
            Listas::Lista<Entidades::Entidade>::Iterador it = zumbis.get_primeiro();
            while (it != nullptr)
            {
                p = *it;
                zumbis.remover(p);
                it++;
                p = nullptr;
            }

            nlohmann::json json = nlohmann::json::parse(arquivo);

            for (auto it = json.begin(); it != json.end(); ++it)
            {
                inimigos.incluir(static_cast<Entidades::Entidade *>(new Entidades::Personagens::Zumbi(
                    sf::Vector2f(
                        (float)((*it)["posicao"][0]),
                        (float)((*it)["posicao"][1])),

                    sf::Vector2f(
                        (float)((*it)["velocidade"][0]),
                        (float)((*it)["velocidade"][1])))));

                zumbis.incluir(static_cast<Entidades::Entidade *>(new Entidades::Personagens::Zumbi(
                    sf::Vector2f(
                        (float)((*it)["posicao"][0]),
                        (float)((*it)["posicao"][1])),

                    sf::Vector2f(
                        (float)((*it)["velocidade"][0]),
                        (float)((*it)["velocidade"][1])))));
            }

            // verificando arquivo salvo dos atiradores
            std::ifstream arq_atiradores(ARQUIVO_ATIRADOR);
            if (!arq_atiradores)
            {
                std::cout << "Arquivo não existe" << std::endl;
                exit(2);
            }

            it = atiradores.get_primeiro();
            while (it != nullptr)
            {
                p = *it;
                atiradores.remover(p);
                it++;
                p = nullptr;
            }

            json = nlohmann::json::parse(arq_atiradores);

            for (auto it = json.begin(); it != json.end(); ++it)
            {
                inimigos.incluir(static_cast<Entidades::Entidade *>(new Entidades::Personagens::Arqueiro(
                    sf::Vector2f(
                        (float)((*it)["posicao"][0]),
                        (float)((*it)["posicao"][1])),

                    sf::Vector2f(
                        (float)((*it)["velocidade"][0]),
                        (float)((*it)["velocidade"][1])))));

                atiradores.incluir(static_cast<Entidades::Entidade *>(new Entidades::Personagens::Arqueiro(
                    sf::Vector2f(
                        (float)((*it)["posicao"][0]),
                        (float)((*it)["posicao"][1])),

                    sf::Vector2f(
                        (float)((*it)["velocidade"][0]),
                        (float)((*it)["velocidade"][1])))));
            }

            // verificando arquivo salvo dos gigantes
            std::ifstream arq_gigantes(ARQUIVO_GIGANTE);
            if (!arq_gigantes)
            {
                std::cout << "Arquivo não existe" << std::endl;
                exit(2);
            }

            it = gigantes.get_primeiro();
            while (it != nullptr)
            {
                p = *it;
                gigantes.remover(p);
                it++;
                p = nullptr;
            }

            json = nlohmann::json::parse(arq_gigantes);

            for (auto it = json.begin(); it != json.end(); ++it)
            {
                inimigos.incluir(static_cast<Entidades::Entidade *>(new Entidades::Personagens::Gigante(
                    sf::Vector2f(
                        (float)((*it)["posicao"][0]),
                        (float)((*it)["posicao"][1])),

                    sf::Vector2f(
                        (float)((*it)["velocidade"][0]),
                        (float)((*it)["velocidade"][1])))));

                gigantes.incluir(static_cast<Entidades::Entidade *>(new Entidades::Personagens::Gigante(
                    sf::Vector2f(
                        (float)((*it)["posicao"][0]),
                        (float)((*it)["posicao"][1])),

                    sf::Vector2f(
                        (float)((*it)["velocidade"][0]),
                        (float)((*it)["velocidade"][1])))));
            }
        }

        void Fase::criar_cenario(string caminho, int n1, int n2, int n3, int n4, int n5, int n6, bool ja_criado)
        {
            int count5 = 0;

            int cont[6];
            for (int i = 0; i < 7; i++)
                cont[i] = 0;

            if (!ja_criado)
            {
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
                        case '1':
                            // dados do arquivo json serao importante nesse caso aqui
                            if (jogadores.get_primeiro() == nullptr)
                            {
                                aux = static_cast<Entidades::Entidade *>(new Entidades::Personagens::Jogador(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), false));
                                if (aux)
                                {
                                    aux->setWindow(pGG->get_Janela());
                                    aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                                    jogadores.incluir(aux);
                                }
                            }
                            break;

                        case '2':
                            // dados do arquivo json serao importante nesse caso aqui
                            if (num_jogadores == 2)
                            {
                                aux = static_cast<Entidades::Entidade *>(new Entidades::Personagens::Jogador(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), true));
                                if (aux)
                                {
                                    aux->setWindow(pGG->get_Janela());
                                    aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                                    jogadores.incluir(aux);
                                }
                            }
                            break;
                        case '3':
                            // dados do arquivo json serao importante nesse caso aqui
                            if (cont[0] < n1)
                            {
                                aux = static_cast<Entidades::Entidade *>(new Entidades::Personagens::Zumbi(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f)));
                                if (aux)
                                {
                                    aux->setWindow(pGG->get_Janela());
                                    aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                                    inimigos.incluir(aux);
                                    zumbis.incluir(aux);
                                }
                                cont[0]++;
                            }
                            break;
                        case '4':
                            // dados do arquivo json serao importante nesse caso aqui
                            if (cont[1] < n2)
                            {
                                aux = static_cast<Entidades::Entidade *>(new Entidades::Personagens::Arqueiro(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f)));
                                if (aux)
                                {
                                    aux->setWindow(pGG->get_Janela());
                                    aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                                    inimigos.incluir(aux);
                                    // atiradores.incluir(aux);
                                }
                                cont[1]++;
                            }
                            break;

                        case '5':
                            if (cont[2] < n3)
                            {
                                aux = static_cast<Entidades::Entidade *>(new Entidades::Obstaculos::Espinho(Vector2f(j * TAM, i * TAM)));
                                if (aux)
                                    obstaculos.incluir(aux);
                                cont[2]++;
                            }
                            break;
                        case '6':
                            if (cont[3] < n4)
                            {
                                aux = static_cast<Entidades::Entidade *>(new Entidades::Obstaculos::Coracao(Vector2f(j * TAM, i * TAM)));
                                if (aux)
                                    obstaculos.incluir(aux);
                                cont[3]++;
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
                            if (cont[4] < n5)
                            {
                                if (aux)
                                    obstaculos.incluir(aux);
                                cont[4]++;
                            }
                            break;
                        case '9':
                            // if vet < n6
                            aux = static_cast<Entidades::Entidade *>(new Entidades::Personagens::Gigante(sf::Vector2f(sf::Vector2f(0.f, 0.f)), sf::Vector2f(0.f, 0.f)));
                            if (cont[5] < n6)
                            {
                                if (aux)
                                {
                                    aux->setWindow(pGG->get_Janela());
                                    aux->setPosicao(sf::Vector2f(j * TAM, i * TAM));
                                    inimigos.incluir(aux);
                                    gigantes.incluir(aux);
                                }
                                cont[5]++;
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

                ja_criado = true;
            }
        }

        void Fase::fim_de_jogo()
        {
        }

        void Fase::salvar()
        {
            // Salvando Jogadores:
            std::ofstream arquivo(ARQUIVO_JOGADOR /*, std::ios::out | std::ios::trunc*/);
            if (!arquivo)
            {
                std::cout << "Problema em salvar o arquivo arquivo jogador" << std::endl;
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
            if(j != nullptr)
            {
                buffer << ",";
                (*j)->salvar(&buffer);
            }
            buffer << "]";

            arquivo << buffer.str();
            arquivo.close();

            // Salvando zumbis:
            std::ofstream arquivo_zumbis(ARQUIVO_ZUMBI);
            if (!arquivo_zumbis)
            {
                std::cout << "Problema em salvar o arquivo dos inimigos" << std::endl;
                exit(1);
            }

            Listas::Lista<Entidades::Entidade>::Iterador zomb = zumbis.get_primeiro();
            buffer.str("");
            buffer << "[";
            if (zomb != nullptr)
            {
                (*zomb)->salvar(&buffer);
                zomb++;
            }
            while (zomb != nullptr)
            {
                buffer << ",";
                (*zomb)->salvar(&buffer);
                zomb++;
            }
            buffer << "]";

            arquivo_zumbis << buffer.str();
            arquivo_zumbis.close();

            // Salvando atiradores:
            std::ofstream arquivo_atiradores(ARQUIVO_ATIRADOR);
            if (!arquivo_atiradores)
            {
                std::cout << "Problema em salvar o arquivo dos inimigos" << std::endl;
                exit(1);
            }

            Listas::Lista<Entidades::Entidade>::Iterador atir = atiradores.get_primeiro();
            arquivo_atiradores.clear();
            buffer.str("");
            buffer << "[";
            if (atir != nullptr)
            {
                (*atir)->salvar(&buffer);
                atir++;
            }
            while (atir != nullptr)
            {
                buffer << ",";
                (*atir)->salvar(&buffer);
                atir++;
            }
            buffer << "]";

            arquivo_atiradores << buffer.str();
            arquivo_atiradores.close();

            // Salvando gigantes:
            std::ofstream arquivo_gigantes(ARQUIVO_GIGANTE);
            if (!arquivo_gigantes)
            {
                std::cout << "Problema em salvar o arquivo dos inimigos" << std::endl;
                exit(1);
            }

            Listas::Lista<Entidades::Entidade>::Iterador gig = gigantes.get_primeiro();
            arquivo_gigantes.clear();
            buffer.str("");
            buffer << "[";
            if (gig != nullptr)
            {
                (*gig)->salvar(&buffer);
                gig++;
            }
            while (gig != nullptr)
            {
                buffer << ",";
                (*gig)->salvar(&buffer);
                gig++;
            }
            buffer << "]";

            arquivo_gigantes << buffer.str();
            arquivo_gigantes.close();

            std::ofstream estado(ESTADO_ATUAL);
            if (!estado)
            {
                std::cout << "Problema em salvar o arquivo de estado atual" << std::endl;
                exit(1);
            }
            estado.clear();
            cout << "estado atual: " << pGE->get_fase() << endl;
            estado << pGE->get_fase();
            estado.close();

            // Salvando Projeteis
            // se descomentar isso aqui vai dar ruim, porjeteis nao tao salvando
            /*std::ofstream arquivo_projeteis(ARQUIVO_PROJETEIS);
            if (!arquivo_projeteis)
            {
                std::cout << "Problema em salvar o arquivo de projeteis" << std::endl;
                exit(1);
            }

            Entidades::Personagens::Inimigo *arqueiro_atira = static_cast<Entidades::Personagens::Inimigo *>(*i);
            std::vector<Entidades::Projetil> *pVetor = arqueiro_atira->get_projeteis();
            if (pVetor != nullptr)
            {
                buffer.str("");
                buffer << "[";
                if (pVetor->size() > 0)
                {

                    Entidades::Entidade *proj = static_cast<Entidades::Entidade *>(&pVetor->at(0));
                    if(proj[0].get_vivo())
                        proj[0].salvar(&buffer);
                    for (int j = 1; j < pVetor->size(); j++)
                    {
                        proj = static_cast<Entidades::Entidade *>(&pVetor->at(j));
                        if (proj[j].get_vivo())
                        {
                            buffer << ",";
                            proj[j].salvar(&buffer);
                        }
                    }
                }
                buffer << "]";
            }*/
        }

        const bool Fase::get_jogador2()
        {
            if (num_jogadores > 1)
                return true;
            else
                return false;
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