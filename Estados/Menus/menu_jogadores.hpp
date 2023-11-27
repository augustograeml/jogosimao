#pragma once
#include "menu.hpp"
using namespace std;

namespace Estados
{
    namespace Menus
    {
        class Menu_Jogadores : public Menu
        {
            private:
                bool jog2;
            public:
                Menu_Jogadores(int id);
                ~Menu_Jogadores();

                void inicializa_valores();
                void loop_evento();
        };
    }
}