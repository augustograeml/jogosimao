#include "../Estados/Menus/menu_principal.hpp"

namespace Estados
{
    namespace Menus
    {
        Menu_Principal::Menu_Principal(int id) : Menu(id)
        {
            inicializa_valores();
        }

        Menu_Principal::~Menu_Principal()
        {

        }

        void Menu_Principal::inicializa_valores()
        {
            pos = 0;
            selecionado = deselecionado = false;
            imagem->loadFromFile("Design/imagens/menu_zombies++.jpg");
            fonte->loadFromFile("Design/fonte/sangue_escorrendo.ttf");

            opcoes = {"Zombies++", "Novo Jogo", "Resume", "Ranking", "Sair"};
            textos.resize(5);
            coordenadas = {{130, 40}, {445, 700}, {464, 762}, {460, 823}, {480, 886}};
            tamanhos = {200, 22, 22, 22, 22};

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

        void Menu_Principal::loop_evento()
        {
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
                        textos[pos].setOutlineThickness(4);
                        textos[pos - 1].setOutlineThickness(0);
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

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    if (pos == 4)
                        pGG->fecharJanela();
                    else if (pos == 1)
                        pGE->set_estado_atual(1);
                    else if (pos == 2 && pGE->get_fase() > 5)
                        pGE->set_estado_atual(pGE->get_fase());
                    /*else if (pos == 2)
                        pGE->set_estado_atual(pGE->get_fase());*/
                    else if(pos == 3)
                        pGE->set_estado_atual(4);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    pGG->fecharJanela();

            }
        }
    }
}