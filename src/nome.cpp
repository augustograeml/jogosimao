#include "../Estados/Menus/nome.hpp"

namespace Estados
{
    namespace Menus
    {
        Nome::Nome(int id) : Menu(id), num_jog_ranking(4)
        {
            inicializa_valores();
        }

        Nome::~Nome()
        {
            // salvar o nome talvez?
        }

        void Nome::inicializa_valores()
        {
            pos = 0;
            selecionado = deselecionado = false;
            imagem->loadFromFile("Design/imagens/pegar_nome.png");
            fonte->loadFromFile("Design/fonte/fonte_simas.ttf");

            opcoes = {"Digite seu nome: "};
            textos.resize(1);
            coordenadas = {{130, 40}};
            tamanhos = {40};

            for (std::size_t i{}; i < textos.size(); i++)
            {
                textos[i].setFont(*fonte);
                textos[i].setString(opcoes[i]);
                textos[i].setCharacterSize(tamanhos[i]);
                textos[i].setFillColor(sf::Color::White);
                textos[i].setOutlineColor(sf::Color::Black);
                textos[i].setPosition(coordenadas[i]);
            }

            textos[0].setOutlineThickness(8);
        }

        void Nome::selecionar()
        {
            
        }

        void Nome::loop_evento()
        {
            sf::Text teste;
            while (pGG->get_Janela()->pollEvent(evento))
            {
                if (sf::Event::Closed)
                    pGG->fecharJanela();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    nome_jogador += 'a';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
                    nome_jogador += 'b';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
                    nome_jogador += 'c';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    nome_jogador += 'd';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
                    nome_jogador += 'e';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
                    nome_jogador += 'f';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
                    nome_jogador += 'g';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
                    nome_jogador += 'h';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
                    nome_jogador += 'i';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
                    nome_jogador += 'j';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
                    nome_jogador += 'k';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
                    nome_jogador += 'l';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
                    nome_jogador += 'm';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
                    nome_jogador += 'n';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
                    nome_jogador += 'o';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                    nome_jogador += 'p';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                    nome_jogador += 'q';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                    nome_jogador += 'r';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    nome_jogador += 's';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
                    nome_jogador += 't';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
                    nome_jogador += 'u';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
                    nome_jogador += 'v';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    nome_jogador += 'w';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
                    nome_jogador += 'x';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
                    nome_jogador += 'y';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                    nome_jogador += 'z';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                    return;
            }
            pGG->limpar();
            pGG->desenharTexto(&teste);
            // pGG->mostrar();
        }

    }
}