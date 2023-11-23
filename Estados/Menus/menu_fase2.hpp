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
        class Menu_Fase2 : public Menu
        {
            protected:
                bool jog2;
            public:
                Menu_Fase2(int id);
                ~Menu_Fase2();

                void inicializa_valores();
                void loop_evento();
        };
    }
}