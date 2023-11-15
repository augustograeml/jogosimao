#pragma once
#include "observer.hpp"

namespace Estados
{
    namespace Menus
    {
        class Menu_Principal;
    }
}

namespace Observers
{
    class Observer_Menu : public Observer
    {
        private:
            Estados::Menus::Menu_Principal* pMenu;
        public:
            Observer_Menu();
            ~Observer_Menu();
            void atualizar(sf::Keyboard::Key codigo);
            void set_menu(Estados::Menus::Menu_Principal* pM) {pMenu = pM;}
    };
}