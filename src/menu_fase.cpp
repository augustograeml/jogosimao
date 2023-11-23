#include "../Estados/Menus/menu_fase.hpp"

namespace Estados
{
    namespace Menus
    {

        Menu_Fase::Menu_Fase(int id, bool jog2) : Menu(id)
        {
            if (jog2)
                set_jogador2(true);
            else
                set_jogador2(false);

            inicializa_valores();
        }

        Menu_Fase::~Menu_Fase()
        {
        }

        void Menu_Fase::inicializa_valores()
        {
            selecionado = deselecionado = false;
            imagem->loadFromFile("Design/imagens/menu2fases.png");
            fonte->loadFromFile("Design/fonte/sangue_escorrendo.ttf");

            opcoes = {"Fases", "Fase 1", "Fase 2", "Sair"};
            textos.resize(4);
            coordenadas = {{270, 40}, {360, 604}, {600, 604}, {493, 650}};
            tamanhos = {200, 20, 20, 20};

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

        void Menu_Fase::loop_evento()
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
                        pGE->set_estado_atual(1);

                    else if (pos == 1)
                    {
                        if (get_jogador2())
                        {
                            pGE->set_estado_atual(7);
                            pGE->set_fase(7);
                        }
                        else
                        {
                            pGE->set_estado_atual(6);
                            pGE->set_fase(6);
                        }
                    }

                    else if (pos == 2)
                    {
                        if (get_jogador2())
                        {
                            pGE->set_estado_atual(9);
                            pGE->set_fase(9);
                        }
                        else
                        {
                            pGE->set_estado_atual(8);
                            pGE->set_fase(8);
                        }
                    }
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    pGE->set_estado_atual(1);
            }
        }
    }
}