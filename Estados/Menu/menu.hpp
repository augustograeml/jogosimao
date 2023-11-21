#pragma once
#include "../estado.hpp"
#include "../../Gerenciadores/gerenciador_grafico.hpp"
#include "botao.hpp"
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
                bool selecionado, deselecionado, inicio;

                sf::RectangleShape* botao;
                sf::Font* fonte;
                sf::Texture* imagem;

                //Jogo* jogo;

                sf::Vector2i posicao_mouse;
                sf::Vector2f coordenadas_mouse;
                
                vector<string> opcoes;
                vector<sf::Vector2f> coordenadas;
                vector<sf::Text> textos;
                vector<sf::Text> copia;
                //tamanhos para fonte pq cada palavra tem um tamanho de fonte diferente
                vector<size_t> tamanhos; 
            public:
                Menu(int id);
                ~Menu();

                //vai ser chamado pra quando for escolher um ou dois jogadores no menu
                void selecionar_modo();
                void selecionar_fase();

                void inicializa_valores();
                void loop_evento();
                void mostrar_menu();
                void executar();
        };
    }
}