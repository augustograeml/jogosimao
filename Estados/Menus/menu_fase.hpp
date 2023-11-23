#pragma once

#include "menu.hpp"
using namespace std;

namespace Estados
{
    namespace Menus
    {
        class Menu_Fase : public Menu
        {
            protected:
                bool jog2;
            public:
                Menu_Fase(int id);
                ~Menu_Fase();

                void inicializa_valores();
                void loop_evento();
        };
    }
}