#pragma once

#include "observer.hpp"
#include <map>

namespace Estados
{
    namespace Menus
    {
        class Fim_de_Jogo;
    }
}

namespace Observers
{
    class Observer_Fim_Jogo :public Observer
    {
        private:
            Estados::Menus::Fim_de_Jogo* pFJ;
            std::map<sf::Keyboard::Key, std::string> chaves;
        public:
            Observer_Fim_Jogo();
            ~Observer_Fim_Jogo();

            void atualizar(sf::Keyboard::Key k);
            void set_menu(Estados::Menus::Fim_de_Jogo* p) {pFJ = p;}
    };
}