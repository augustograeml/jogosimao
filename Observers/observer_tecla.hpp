#pragma once
#include "observer.hpp"

namespace Observers
{
    class Observer_Tecla : public Observer
    {
        private:
            const int numero;
        public:
            Observer_Tecla(int n = 0);
            ~Observer_Tecla();

            void atualizar(sf::Keyboard::Key k);
    };

}