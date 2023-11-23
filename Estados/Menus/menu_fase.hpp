#pragma once

#include "menu.hpp"
using namespace std;

namespace Estados
{
    namespace Menus
    {
        class Menu_Fase : public Menu
        {
            private:
            public:
                Menu_Fase(int id, bool jog2);
                ~Menu_Fase();

                void inicializa_valores();
                void loop_evento();
        };
    }
}