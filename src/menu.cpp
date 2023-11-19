#include "../Estados/Menu/menu.hpp"

namespace Estados
{
    namespace Menu
    {
        Menu::Menu() : pGG(Gerenciadores::Gerenciador_Grafico::get_instancia()),
        pEv(Gerenciadores::Gerenciador_Eventos::get_instancia())
        {
            botao = new sf::RectangleShape();
            janela = new sf::RenderWindow();
            fonte = new sf::Font();
            imagem = new sf::Texture();
            bg = new sf::Sprite();
            inicializa_valores();
        }

        Menu::~Menu()
        {
            delete botao;
            delete janela;
            delete fonte;
            delete imagem;
            delete bg;
        }

        void Menu::inicializa_valores()
        {
            janela->create(sf::VideoMode(1024, 1024), "Zombies++", sf::Style::Titlebar | sf::Style::Close);
            //janela->setPosition(sf::Vector2i(0, 0));

            //pGG->get_Janela()->create(sf::VideoMode(1024, 1024), "Zombies++", sf::Style::Titlebar | sf::Style::Close);
            pGG->get_Janela()->setPosition(sf::Vector2i(0, 0));

            pos = 0;
            selecionado = deselecionado = false;
            imagem->loadFromFile("Design/imagens/menu_zombies++.jpeg");
            fonte->loadFromFile("Design/fonte/fontezumbi.ttf");
            //bg->setTexture(*imagem);

            posicao_mouse = {0, 0};
            coordenadas_mouse = {0, 0};
        }

        void Menu::eventos()
        {
            sf::Event evento;
            while(janela->pollEvent(evento))
            {
                if(evento.type == sf::Event::Closed)
                    janela->close();
            }
        }

        void Menu::mostrar_menu()
        {
            /*janela->clear();
            janela->draw(*bg);
            janela->display();*/
            
            pGG->limpar();
            pGG->desenharTextura(imagem);
            pGG->mostrar();
        }

        void Menu::executar()
        {
            while(janela->isOpen())
            {
                pEv->executar();
                //eventos();
                mostrar_menu();
            }
        }
    }
}