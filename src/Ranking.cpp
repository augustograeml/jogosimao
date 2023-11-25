#include "../Estados/Menus/ranking.hpp"
#include <iostream>
#define ARQUIVO_COLOCACAO_1 "Design/imagens/rankingfase1.txt"


namespace Estados
{
    namespace Menus
    {
        Gerenciadores::Gerenciador_Grafico* Ranking::pGG(Gerenciadores::Gerenciador_Grafico::get_instancia());

        Ranking::Ranking(int id) : Estado(id)
        {
            fonte = new sf::Font();
            fonte_nomes = new sf::Font();
            imagem = new sf::Texture();
            
            
            inicializa_valores();
            //CriarTextos();
        }

        Ranking::~Ranking()
        {
            delete fonte;
            delete imagem;
        }

        void Ranking::inicializa_valores()
        {
            selecionado = deselecionado = false;
            imagem->loadFromFile("Design/imagens/rankingzombies++.png");
            fonte->loadFromFile("Design/fonte/sangue_escorrendo.ttf");
            fonte_nomes->loadFromFile("Design/fonte/fonte_simas.ttf");

            opcoes = {"Ranking","Fase 1","1", "2","3","4","Sair"};
            textos.resize(7);
            tamanhos = {170,20, 20, 20, 20, 20, 35};
            coordenadas = { {215, 40}, {215,100}, {100, 380}, {100, 462}, {100, 549}, {100, 635}, {278, 730}};
            

            for (std::size_t i{}; i < textos.size(); i++)
            {
                textos[i].setFont(*fonte);
                textos[i].setString(opcoes[i]);
                textos[i].setCharacterSize(tamanhos[i]);
                textos[i].setFillColor(sf::Color::White);
                textos[i].setOutlineColor(sf::Color::Black);
                textos[i].setPosition(coordenadas[i]);
                
            }

            textos[0].setOutlineThickness(15);
            textos[5].setOutlineThickness(4);

            pos = 5;
        }

        void Ranking::mostrar_menu()
        {
            pGG->limpar();
            pGG->desenharTextura(imagem);
            // laco diferentao ne mano pprt
            //textos[3].setString(opcoes[3] + "   augusto");

            //poolEvent, event.type text entered

            CriarTextos(ARQUIVO_COLOCACAO_1);
            for (auto t : textos)
            {
                 pGG->get_Janela()->draw(t);
            }
               
            pGG->mostrar();
        }

        void Ranking::executar()
        {
            mostrar_menu();
            loop_evento();
        }

        void Ranking::adiciona_pontuacao(std::string s, double time)
        {

        }

        void Ranking::loop_evento()
        {
            sf::Event evento;
            while (pGG->get_Janela()->pollEvent(evento))
            {
                if (evento.type == sf::Event::Closed)
                    pGG->fecharJanela();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                        pGE->set_estado_atual(0);   
            }
        }
        void Ranking::CriarTextos(string caminho)
        {
            ifstream arquivoInput(caminho);
            std::string linha;
            std::string espaco = "  ";
            int i = 2;
            if(!arquivoInput)
            {
                std::cout<< "error ao abrir";
            }
            else
            {
                while(getline(arquivoInput, linha)  && i < 6)
                {
                    textos[i].setString( opcoes[i] + espaco + linha);
                    textos[i].setFont(*fonte_nomes);
                    i++;
                }
                arquivoInput.close();
            }
                

        }  
    }
}