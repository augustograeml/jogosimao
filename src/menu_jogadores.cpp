#include "../Estados/Menus/menu_jogadores.hpp"

namespace Estados
{
    namespace Menus
    {

        Menu_Jogadores::Menu_Jogadores(int id) : Menu(id)
        {
            inicializa_valores();
        }

        Menu_Jogadores::~Menu_Jogadores()
        {
        }

        const bool Menu_Jogadores::get_jogador2()
        {
            return jogador2;
        }

        void Menu_Jogadores::inicializa_valores()
        {
            selecionado = deselecionado = jogador2 = false;
            imagem->loadFromFile("Design/imagens/menu2jogadores.png");
            fonte->loadFromFile("Design/fonte/sangue_escorrendo.ttf");

            opcoes = {"Players", "Um jogador", "Dois Jogadores", "Sair"};
            textos.resize(4);
            coordenadas = {{250, 40}, {335, 604}, {564, 604}, {493, 650}};
            tamanhos = {150, 20, 20, 20};

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
        }

        void Menu_Jogadores::loop_evento()
        {
            sf::Event evento;
            while (pGG->get_Janela()->pollEvent(evento))
            {
                if (evento.type == sf::Event::Closed)
                    pGG->fecharJanela();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !selecionado)
                {
                    if (pos < 3)
                    {
                        pos++;
                        selecionado = true;
                        textos[pos].setOutlineThickness(4);
                        textos[pos - 1].setOutlineThickness(0);
                        selecionado = false;
                    }
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !selecionado)
                {
                    if (pos > 1)
                    {
                        pos--;
                        selecionado = true;
                        textos[pos].setOutlineThickness(4);
                        textos[pos + 1].setOutlineThickness(0);
                        selecionado = false;
                    }
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !selecionado)
                {
                    if (pos > 1)
                    {
                        pos--;
                        selecionado = true;
                        textos[pos].setOutlineThickness(4);
                        textos[pos + 1].setOutlineThickness(0);
                        selecionado = false;
                    }
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !selecionado)
                {
                    if (pos < 3)
                    {
                        pos++;
                        selecionado = true;
                        textos[pos].setOutlineThickness(4);
                        textos[pos - 1].setOutlineThickness(0);
                        selecionado = false;
                    }
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    if (pos == 3)
                        pGE->set_estado_atual(0);
                    else if (pos == 1)
                        pGE->set_estado_atual(2);
                    else if (pos == 2)
                        pGE->set_estado_atual(3);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    pGE->set_estado_atual(0);
            }
        }
    }
}