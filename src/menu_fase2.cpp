#include "../Estados/Menu/menu_fase2.hpp"

namespace Estados
{
    namespace Menus
    {
        Gerenciadores::Gerenciador_Grafico* Menu_Fase2::pGG(Gerenciadores::Gerenciador_Grafico::get_instancia());

        Menu_Fase2::Menu_Fase2(int id) : Estado(id)
        {
            fonte = new sf::Font();
            imagem = new sf::Texture();

            inicializa_valores();
        }

        Menu_Fase2::~Menu_Fase2()
        {
            delete fonte;
            delete imagem;
        }

        void Menu_Fase2::inicializa_valores()
        {
            selecionado = deselecionado = false;
            imagem->loadFromFile("Design/imagens/menu2jogadores.png");
            fonte->loadFromFile("Design/fonte/sangue_escorrendo.ttf");

            opcoes = {"Fase 1", "Fase 2", "Sair"};
            textos.resize(3);
            coordenadas = { {360, 604}, {600, 604}, {493, 650}};
            tamanhos = {20, 20, 20};

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
            textos[0].setOutlineThickness(4);

            pos = 0;
        }

        void Menu_Fase2::mostrar_menu()
        {
            pGG->limpar();
            pGG->desenharTextura(imagem);
            // laco diferentao ne mano pprt
            for (auto t : textos)
                pGG->get_Janela()->draw(t);
            pGG->mostrar();
        }

        void Menu_Fase2::executar()
        {
            mostrar_menu();
            loop_evento();
        }

        void Menu_Fase2::loop_evento()
        {
            sf::Event evento;
            while (pGG->get_Janela()->pollEvent(evento))
            {
                if (evento.type == sf::Event::Closed)
                    pGG->fecharJanela();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !selecionado)
                {
                    if (pos < 2)
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
                    if (pos > 0)
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
                    if (pos > 0)
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
                    if (pos < 2)
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
                    if (pos == 2)
                        pGE->set_estado_atual(2);
                    else if (pos == 0)
                        pGE->set_estado_atual(6);
                    else if (pos == 1)
                        pGE->set_estado_atual(8);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    pGE->set_estado_atual(2);

            }
        }
    }
}