#pragma once

#include "observer.hpp"
#include <iostream>

namespace Observers
{
    class Observer_Ranking: public Observer
    {
    private:
        Estados::Menus::Ranking* pRanking;
    public:
        Observer_Ranking();
        ~Observer_Ranking();
        void atualizar(sf::Keyboard::Key key_code);
        void set_menu(Estados::Menus::Ranking *p) { std::cout << "Observer" << std::endl; pRanking = p; }
    };
}