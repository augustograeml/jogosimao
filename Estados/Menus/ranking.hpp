#pragma once

#include "../../Gerenciadores/gerenciador_grafico.hpp"
#include "menu.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>

using namespace std;

namespace Estados
{
     namespace Menus
    {
        class Ranking: public Menu
        {
            private:
                sf::Font* fonte_nomes;               
            public:
                Ranking(int id);
                ~Ranking();

                void inicializa_valores();
                void loop_evento();
                void mostrar_menu_ranking();
                void executar();
                void CriarTextos(string caminho);
        
        };
    }
}
   
    