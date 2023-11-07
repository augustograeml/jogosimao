#pragma once
#include "observer.hpp"

class Observer_Tecla : public Observer
{
    private:
        const int numero;
    public:
        Observer_Tecla(int n = 0);
        ~Observer_Tecla();

        void atualizar(Keyboard::Key k);
};