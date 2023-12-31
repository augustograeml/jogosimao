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
            Caixa.setSelected(true);
            Caixa.setFont(*fonte);
            Caixa.setPosition(sf::Vector2f(150,480));

            opcoes = {"Digite seu nome: "," ", "Sair"};
            textos.resize(3);
            coordenadas = {{130, 40},{150,480}, {493, 650}};
            tamanhos = {40,20,20};

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
                if(sf::Event::TextEntered)
                Caixa.typedOn(evento);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !selecionado)
                {
                    if (pos > 1)
                    {
                        pos--;
                        selecionado = true;
                        Caixa.setSelected(true);
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
                        textos[pos + 1].setOutlineThickness(0);
                        selecionado = false;
                    }
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    if (pos == 3)
                        pGE->set_estado_atual(1);
                    else if (pos == 1 && Caixa.getText() != "")
                    {
                       // Caixa.getText();
                    }
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    pGE->set_estado_atual(1);

                
            }
            pGG->limpar();
            Caixa.drawTo(*pGG->get_Janela());
            pGG->mostrar();
        }

    }
}