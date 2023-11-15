#include "../Estados/Menus/ranking.hpp"

namespace Estados
{
    namespace Menus
    {
        Ranking::Ranking() : Menu(2, 4, "Ranking"), primeiro("1 nome - tempo"), 
        segundo("2 nome - tempo"), terceiro("3 nome - tempo"),  ranking(),
        buffer()
        {
            titulo.set_tamanho(70);
            titulo.set_posicao(sf::Vector2f(160.f, 80.f));
            titulo.set_cor(0);

            primeiro.set_posicao(sf::Vector2f(110.f, 160.f));
            segundo.set_posicao(sf::Vector2f(110.f, 240.f));
            terceiro.set_posicao(sf::Vector2f(110.f, 320.f));
            
            carregar();
            botoes[0]->set_nome("Menu");
            botoes[0]->set_posicao(sf::Vector2f(400.f, 420.f));

            botoes[1]->set_nome("Quit");
            botoes[1]->set_posicao(sf::Vector2f(400.f, 520.f));

            botoes_ativos = false;
            pRObserver = new Observers::Observer_Ranking();
            pRObserver->set_menu(this);
        }

        Ranking::~Ranking()
        {
            if (pRObserver)
                delete pRObserver;
            
            pRObserver = nullptr;
            //salvar();
        }

        void Ranking::selecionar()
        {
            if (!botoes_ativos)
            {
                botoes_ativos = true;
                return;
            }
            
            if (botoes_ativos)
            {
                switch (indice)
                {
                    case 0:
                        Estados::Estado::pGE->set_estado_atual(0);
                        botoes_ativos = false;
                        break;

                    case 1:
                        pGG->fecharJanela();
                        break;
                }
            }
        }

        void Ranking::desenhar()
        {
            pGG->desenharFundo(&(this->corpo));

            titulo.desenhar();
    
            primeiro.desenhar();
            segundo.desenhar();
            terceiro.desenhar();

            for (int i = 0; i < 2; i++)
            {
                botoes[i]->desenhar();
            }
        }

        void Ranking::adicinar_novo_ranking(int pontos, std::string nome)
        {
            ranking.insert(std::make_pair(pontos, nome));
        
            std::map<int, std::string>::iterator it = ranking.begin();
            for (int i = 0; i < 3 && it != ranking.end(); i++, it++)
            {
                if (i == 0)
                    primeiro.set_nome(it->second + " - " + std::to_string(it->first));
                else if (i == 1)
                    segundo.set_nome(it->second + " - " + std::to_string(it->first));
                else
                    terceiro.set_nome(it->second + " - " + std::to_string(it->first));
            }
        }

        void Ranking::salvar(std::ostringstream* entrada)
        {
            //tentar fazer o ranking sakvar daora legal depois

            std::ofstream arquivo(RANKING);  
            if (!arquivo)
            {
                std::cout << "Problema em salvar o arquivo" << std::endl;
                exit(1);
            }

            /*std::map<int, std::string>::iterator it = ranking.begin();
            for (int i = 0; i < 3 && it != ranking.end(); i++, it++)
            {
                buffer.str("");
                buffer << "[";
                if (it != nullptr)
                {
                    (*it)->salvar(&buffer);
                    it++;
                }
                while (it != nullptr)
                {
                    buffer << ",";
                    (*it)->salvar(&buffer);
                    it++;
                }
                buffer << "]";
            }
            arquivo << buffer.str();
            arquivo.close();*/
        }

        void Ranking::carregar()
        {
            std::ifstream arquivo(RANKING);
            if (!arquivo)
            {
                std::cout<<"Nao foi possivel abrir o arquivo de Ranking"<<std::endl;
                exit(1);
            }     
            int pontos;
            std::string nome;
            for (int i = 0; i < 3; i++)
            {
                arquivo>>nome>>pontos;
                ranking.insert(std::make_pair(pontos, nome));
            }
            arquivo.close(); 

            std::map<int, std::string>::iterator it = ranking.begin();
            for (int i = 0; i < 3 && it != ranking.end(); i++, it++)
            {
                if (i == 0)
                    primeiro.set_nome(it->second + " - " + std::to_string(it->first));
                else if (i == 1)
                    segundo.set_nome(it->second + " - " + std::to_string(it->first));
                else
                    terceiro.set_nome(it->second + " - " + std::to_string(it->first));
            }

        }
    }
}