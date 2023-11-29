#include "../Estados/Menus/ranking.hpp"
#include <iostream>
#define ARQUIVO_COLOCACAO "Design/txts/ranking.txt"


namespace Estados
{
    namespace Menus
    {
        Ranking::Ranking(int id) : Menu(id)
        {
            fonte_nomes = new sf::Font();
            
            inicializa_valores();
        }

        Ranking::~Ranking()
        {
            delete fonte_nomes;
        }

        void Ranking::inicializa_valores()
        {
            selecionado = deselecionado = false;
            imagem->loadFromFile("Design/imagens/rankingzombies++.png");
            fonte->loadFromFile("Design/fonte/sangue_escorrendo.ttf");
            fonte_nomes->loadFromFile("Design/fonte/fonte_simas.ttf");

            opcoes = {"Ranking","1", "2","3","4","Sair"};
            textos.resize(6);
            tamanhos = {170, 20, 20, 20, 20, 35};
            coordenadas = { {215, 40}, {100, 380}, {100, 462}, {100, 549}, {100, 635}, {278, 730}};
            

            for (std::size_t i{}; i < textos.size(); i++)
            {
                textos[i].setFont(*fonte);
                textos[i].setString(opcoes[i]);
                textos[i].setCharacterSize(tamanhos[i]);
                textos[i].setFillColor(sf::Color::White);
                textos[i].setOutlineColor(sf::Color::Black);
                textos[i].setOutlineThickness(4);
                textos[i].setPosition(coordenadas[i]);
            }

            textos[0].setOutlineThickness(15);
            textos[5].setOutlineThickness(4);

            pos = 5;
        }

        void Ranking::mostrar_menu_ranking()
        {
            pGG->limpar();
            pGG->desenharTextura(imagem);
            CriarTextos(ARQUIVO_COLOCACAO);
            for (auto t : textos)
            {
                 pGG->get_Janela()->draw(t);
            }
               
            pGG->mostrar();
        }

        void Ranking::executar()
        {
            mostrar_menu_ranking();
            loop_evento();
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
            int i = 1;
            if(!arquivoInput)
            {
                std::cout<< "error ao abrir";
            }
            else
            {
                while(getline(arquivoInput, linha)  && i < 5)
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