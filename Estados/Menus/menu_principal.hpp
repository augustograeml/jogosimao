#pragma once

#include "menu.hpp"
#include "../../Observers/observer_menu_principal.hpp"
using namespace std;

namespace Estados
{
    namespace Menus
    {
        class Menu_Principal : public Menu
        {
            private:
                bool jacriado;
                Observers::Observer_Menu_Principal* pObserver;
            public:
                Menu_Principal(int id);
                ~Menu_Principal();

                void inicializa_valores();
                void loop_evento();
                void selecionar();
        };
    }
}