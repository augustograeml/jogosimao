#pragma once
#include "menu.hpp"

namespace Estados
{
    namespace Menus
    {
        class Menu_Jogadores : public Estado
        {
            private:

                Gerenciadores::Gerenciador_Grafico* pGG;
                int pos;
                //o deselecionar é necessario porque como o loop pra rodar o jogo eh rapido pode acontecer de uma opcao ser selecionada duplicada no menu

                sf::RectangleShape* botao;
                sf::Font* fonte;
                sf::Texture* imagem;
                
                vector<string> opcoes;
                vector<sf::Vector2f> coordenadas;
                vector<sf::Text> textos;
                vector<sf::Text> copia;
                //tamanhos para fonte pq cada palavra tem um tamanho de fonte diferente
                vector<size_t> tamanhos;
            public:
                Menu_Jogadores(int id);
                ~Menu_Jogadores();

                void inicializa_valores();
                void loop_evento();
                void mostrar_menu();
                void executar();
        };
    }
}