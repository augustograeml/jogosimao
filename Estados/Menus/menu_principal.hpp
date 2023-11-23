#pragma once

#include "menu.hpp"
using namespace std;

namespace Estados
{
    namespace Menus
    {
        class Menu_Principal : public Menu
        {
            private:
                bool jacriado;
            public:
                Menu_Principal(int id);
                ~Menu_Principal();

                void inicializa_valores();
                void loop_evento();
        };
    }
}