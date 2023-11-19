#pragma once
#include "../estado.hpp"
#include "../../Gerenciadores/gerenciador_grafico.hpp"
#include <SFML/Graphics.hpp>

namespace Estados
{
    namespace Menu
    {
        class Menu : public Estado
        {
            protected:
                Gerenciadores::Gerenciador_Grafico* pGG;
                int pos;
                //o deselecionar é necessario porque como o loop pra rodar o jogo eh rapido pode acontecer de uma opcao ser selecionada duplicada no menu
                bool selecionado, deselecionado;

                sf::RectangleShape* botao;
                sf::Font* fonte;
                sf::Texture* imagem;

                sf::Vector2i posicao_mouse;
                sf::Vector2f coordenadas_mouse;
                
                vector<string> opcoes;
                vector<sf::Vector2f> coordenadas;
                vector<sf::Text> textos;
                //tamanhos para fonte pq cada palavra tem um tamanho de fonte diferente
                vector<size_t> tamanhos;
            public:
                Menu();
                ~Menu();


                void inicializa_valores();
                void loop_evento();
                void mostrar_menu();
                void executar();
        };
    }
}