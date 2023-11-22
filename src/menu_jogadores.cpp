#include "../Estados/Menus/menu_jogadores.hpp"

namespace Estados
{
    namespace Menus
    {
        Gerenciadores::Gerenciador_Grafico* Menu_Jogadores::pGG(Gerenciadores::Gerenciador_Grafico::get_instancia());

        Menu_Jogadores::Menu_Jogadores(int id) : Estado(id)
        {
            fonte = new sf::Font();
            imagem = new sf::Texture();

            inicializa_valores();
        }

        Menu_Jogadores::~Menu_Jogadores()
        {
            delete fonte;
            delete imagem;
        }

        const bool Menu_Jogadores::get_jogador2()
        {
            return jogador2;
        }

        void Menu_Jogadores::inicializa_valores()
        {
            selecionado = deselecionado = jogador2 = false;
            imagem->loadFromFile("Design/imagens/menu2jogadoers(2).png");
            fonte->loadFromFile("Design/fonte/sangue_escorrendo.ttf");

            opcoes = {"Players","Um jogador", "Dois Jogadores", "Sair"};
            textos.resize(4);
            coordenadas = {{250,40}, {335, 604}, {564, 604}, {493, 650}};
            tamanhos = {150,20, 20, 20};

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

        void Menu_Jogadores::mostrar_menu()
        {
            pGG->limpar();
            pGG->desenharTextura(imagem);
            // laco diferentao ne mano pprt
            for (auto t : textos)
                pGG->get_Janela()->draw(t);
            pGG->mostrar();
        }

        void Menu_Jogadores::executar()
        {
            mostrar_menu();
            loop_evento();
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
                        pGE->set_estado_atual(1);
                    else if (pos == 1)
                        pGE->set_estado_atual(3);
                    else if (pos == 2)
                        pGE->set_estado_atual(4);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    pGE->set_estado_atual(1);
            }
        }
    }
}