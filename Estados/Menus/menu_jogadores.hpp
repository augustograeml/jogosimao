#pragma once
#include "../estado.hpp"
#include "menu.hpp"
#include "../../Gerenciadores/gerenciador_grafico.hpp"
#include <SFML/Graphics.hpp>
using namespace std;

namespace Estados
{
    namespace Menus
    {
        class Menu_Jogadores : public Menu
        {
            private:
                bool jogador2;
            public:
                Menu_Jogadores(int id);
                ~Menu_Jogadores();

                const bool get_jogador2();

                void inicializa_valores();
                void loop_evento();
        };
    }
}