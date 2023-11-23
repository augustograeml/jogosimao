//codigo reaproveitado do Canal Terminal Root

#include "../Estados/Menus/menu.hpp"
#include <iostream>

namespace Estados
{
    namespace Menus
    {
        Gerenciadores::Gerenciador_Grafico* Menu::pGG(Gerenciadores::Gerenciador_Grafico::get_instancia());
        
        Menu::Menu(int id) : Estado(id), inicio(true)
        {
            fonte = new sf::Font();
            imagem = new sf::Texture();

            inicializa_valores();
        }

        Menu::~Menu()
        {
            delete fonte;
            delete imagem;
        }

        void Menu::inicializa_valores()
        {
            pos = 0;
            selecionado = deselecionado = false;
            imagem->loadFromFile("Design/imagens/menu_zombies++.jpg");
            fonte->loadFromFile("Design/fonte/sangue_escorrendo.ttf");

            opcoes = {"Zombies++", "Novo Jogo", "Resume", "Ranking", "Sair", "Um Jogador", "Dois Jogadores", "Fase 1", "Fase 2"};
            textos.resize(9);
            coordenadas = {{130, 40}, {445, 700}, {464, 762}, {460, 823}, {480, 886}, {520, 670}, {515, 695}, {560, 630}, {560, 650}};
            tamanhos = {200, 22, 22, 22, 22, 22, 22, 22, 22};

            for (std::size_t i{}; i < textos.size(); i++)
            {
                textos[i].setFont(*fonte);
                textos[i].setString(opcoes[i]);
                textos[i].setCharacterSize(tamanhos[i]);
                textos[i].setFillColor(sf::Color::White);
                textos[i].setOutlineColor(sf::Color::Black);
                textos[i].setPosition(coordenadas[i]);
            }

            textos[0].setFillColor(sf::Color::White);
            textos[0].setOutlineThickness(20);

            textos[1].setOutlineThickness(4);
            pos = 1;

            copia.resize(5);
            for (std::size_t i{}; i < copia.size(); i++)
            {
                copia[i].setFont(*fonte);
                copia[i].setString(opcoes[i]);
                copia[i].setCharacterSize(tamanhos[i]);
                copia[i].setFillColor(sf::Color::White);
                copia[i].setOutlineColor(sf::Color::Black);
                copia[i].setPosition(coordenadas[i]);
            }

            copia[0].setFillColor(sf::Color::White);
            copia[0].setOutlineThickness(20);

            copia[1].setOutlineThickness(4);
            pos = 1;

            textos[5].setOutlineThickness(4);
        }

        void Menu::mostrar_menu()
        {
            pGG->limpar();
            pGG->desenharTextura(imagem);
            // laco diferentao ne mano pprt
            for (auto t : copia)
                pGG->get_Janela()->draw(t);
            pGG->mostrar();
        }

        void Menu::executar()
        {
            mostrar_menu();
            loop_evento();
        }

        void Menu::loop_evento()
        {
            sf::Event evento;
            while (pGG->get_Janela()->pollEvent(evento))
            {
                if (evento.type == sf::Event::Closed)
                    pGG->fecharJanela();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !selecionado)
                {
                    if (pos < 4)
                    {
                        pos++;
                        selecionado = true;
                        copia[pos].setOutlineThickness(4);
                        copia[pos - 1].setOutlineThickness(0);
                        selecionado = false;
                    }
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !selecionado)
                {
                    if (pos > 1)
                    {
                        pos--;
                        selecionado = true;
                        copia[pos].setOutlineThickness(4);
                        copia[pos + 1].setOutlineThickness(0);
                        selecionado = false;
                    }
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    if (pos == 4)
                        pGG->fecharJanela();
                    else if (pos == 1)
                        pGE->set_estado_atual(2);
                    /*else if (pos == 2)
                        pGE->set_estado_atual(pGE->get_fase());*/
                    else if(pos == 3)
                        pGE->set_estado_atual(9);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    pGG->fecharJanela();

            }
        }
    }
}