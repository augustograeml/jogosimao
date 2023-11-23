#include "../Estados/Menus/ranking.hpp"

namespace Estados
{
    namespace Menus
    {
        Gerenciadores::Gerenciador_Grafico* Ranking::pGG(Gerenciadores::Gerenciador_Grafico::get_instancia());

        Ranking::Ranking(int id) : Estado(id)
        {
            fonte = new sf::Font();
            imagem = new sf::Texture();

            inicializa_valores();
        }

        Ranking::~Ranking()
        {
            delete fonte;
            delete imagem;
        }

        void Ranking::inicializa_valores()
        {
            selecionado = deselecionado = false;
            imagem->loadFromFile("Design/imagens/rankingzombies++.png");
            fonte->loadFromFile("Design/fonte/sangue_escorrendo.ttf");

            opcoes = {"Sair"};
            textos.resize(1);
            coordenadas = {  {493, 650}};
            

            for (std::size_t i{}; i < textos.size(); i++)
            {
                textos[i].setFont(*fonte);
                textos[i].setString(opcoes[i]);
                textos[i].setCharacterSize(20);
                textos[i].setFillColor(sf::Color::White);
                textos[i].setOutlineColor(sf::Color::Black);
                textos[i].setPosition(coordenadas[i]);
            }

            textos[0].setFillColor(sf::Color::White);
            textos[0].setOutlineThickness(20);

            textos[1].setFillColor(sf::Color::White);
            textos[1].setOutlineThickness(4);

            pos = 1;
        }

        void Ranking::mostrar_menu()
        {
            pGG->limpar();
            pGG->desenharTextura(imagem);
            // laco diferentao ne mano pprt
            for (auto t : textos)
                pGG->get_Janela()->draw(t);
            pGG->mostrar();
        }

        void Ranking::executar()
        {
            mostrar_menu();
            loop_evento();
        }

        void Ranking::loop_evento()
        {
            sf::Event evento;
            while (pGG->get_Janela()->pollEvent(evento))
            {
                if (evento.type == sf::Event::Closed)
                    pGG->fecharJanela();

                

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    if (pos == 0)
                        pGE->set_estado_atual(2);
                    
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    pGE->set_estado_atual(2);

            }
        }
    }
}