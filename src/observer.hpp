#pragma once

#include "SFML/Graphics.hpp"
#include "gerenciador_eventos.hpp"

class Observer
{
    protected:
        static Gerenciador_Eventos* pGer_Eventos;
    public:
        Observer();
        virtual ~Observer();

        virtual void atualizar(Keyboard::Key k) = 0;
};