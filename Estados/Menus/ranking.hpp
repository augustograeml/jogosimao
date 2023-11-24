#pragma once
#include "../estado.hpp"
#include <fstream>
#include "../../Gerenciadores/gerenciador_grafico.hpp"
#include <SFML/Graphics.hpp>
using namespace std;

namespace Estados
{
     namespace Menus
    {
        class Ranking: public Estado
        {
            protected:
                static Gerenciadores::Gerenciador_Grafico* pGG;
                int pos;
                //o deselecionar é necessario porque como o loop pra rodar o jogo eh rapido pode acontecer de uma opcao ser selecionada duplicada no menu
                bool selecionado, deselecionado, jog2;

                sf::Font* fonte;
                sf::Font* fonte_nomes;
                sf::Texture* imagem;
                
                vector<string> opcoes;
                vector<sf::Vector2f> coordenadas;
                vector<sf::Text> textos;
                vector<size_t> tamanhos;

                
            public:
                Ranking(int id);
                ~Ranking();

                void inicializa_valores();
                void adiciona_pontuacao(std::string s, double time);
                void loop_evento();
                void mostrar_menu();
                void executar();
                void CriarTextos(string caminho);
        
        };
    }
}
   
    