#include "../Estados/Menu/menu.hpp"
#include "../jogo.hpp"
#include <iostream>

namespace Estados
{
    namespace Menu
    {
        Menu::Menu(int id) : pGG(Gerenciadores::Gerenciador_Grafico::get_instancia()), Estado(id)
        {
            botao = new sf::RectangleShape();
            fonte = new sf::Font();
            imagem = new sf::Texture();
            //jogo = new Jogo();

            inicializa_valores();
        }

        Menu::~Menu()
        {
            delete botao;
            delete fonte;
            delete imagem;
            //delete jogo;
        }

        void Menu::inicializa_valores()
        {
            pos = 0;
            selecionado = deselecionado = false;
            imagem->loadFromFile("Design/imagens/menu_zombies++.jpg");
            fonte->loadFromFile("Design/fonte/sangue_escorrendo.ttf");

            posicao_mouse = {0, 0};
            coordenadas_mouse = {0, 0};

            opcoes = {"Zombies++", "Novo Jogo", "Resume", "Ranking", "Sair"};
            textos.resize(5);
            coordenadas = {{130, 40}, {445, 700}, {464, 762}, {460, 823}, {480, 886}};
            tamanhos = {200, 22, 22, 22, 22}; 

            for(std::size_t i{}; i < textos.size(); ++i)
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

            //botao pro mouse pra entrar no jogo
            botao->setSize(sf::Vector2f(151, 35));
            botao->setPosition(445, 700);
            botao->setFillColor(sf::Color::Red);
        }

        void Menu::mostrar_menu()
        {            
            pGG->limpar();
            pGG->desenharTextura(imagem);
            //laco diferentao ne mano pprt
            for(auto t : textos)
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
            while(pGG->get_Janela()->pollEvent(evento))
            {
                //mostrar_menu();
                if(evento.type == sf::Event::Closed)
                    pGG->fecharJanela();

                /*se der ruim colocar a posicao do mouse na janela
                posicao_mouse = sf::Mouse::getPosition(pGG->get_janela()); */
                posicao_mouse = sf::Mouse::getPosition();
                coordenadas_mouse = pGG->get_Janela()->mapPixelToCoords(posicao_mouse);

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !selecionado)
                {
                    if(pos < 4)
                    {
                        pos++;
                        selecionado = true;
                        textos[pos].setOutlineThickness(4);
                        textos[pos - 1].setOutlineThickness(0);
                        selecionado = false;
                        deselecionado = false;
                    }
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !selecionado)
                {
                    if(pos > 1)
                    {
                        pos--;
                        selecionado = true;
                        textos[pos].setOutlineThickness(4);
                        textos[pos + 1].setOutlineThickness(0);
                        selecionado = false;
                        deselecionado = false;
                    }
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !deselecionado)
                {
                    deselecionado = true;
                    if(pos == 4)
                        pGG->fecharJanela();
                    else if(pos == 1)
                    {
                        pGE->set_estado_atual(2);
                        std::cout << std::endl <<  "O COXA NAO CAI" ;//executar de jogo
                        return;
                    }
                       
                }
                
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    if(botao->getGlobalBounds().contains(coordenadas_mouse))
                    {
                        //jogo->Executar();
                    }
                }
                
            }
        }
    }
}