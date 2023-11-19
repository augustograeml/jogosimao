#pragma once
#include "../estado.hpp"
#include <SFML/Graphics.hpp>

namespace Estados
{
    namespace Menu
    {
        class Menu : public Estado
        {
            protected:
                int pos;
                //o deselecionar é necessario porque como o loop pra rodar o jogo eh rapido pode acontecer de uma opcao ser selecionada duplicada no menu
                bool selecionar, deselecionar;
                sf::RectangleShape botao;
                sf::Text texto_botao;

            public:
                Menu();
                ~Menu();
                virtual void executar();
        };
    }
}