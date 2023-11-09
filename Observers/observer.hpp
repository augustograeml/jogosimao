#pragma once

#include "SFML/Graphics.hpp"
#include "../Gerenciadores/gerenciador_eventos.hpp"

using namespace Gerenciadores;

namespace Observers
{

class Observer
{
    protected:
        static Gerenciador_Eventos* pGer_Eventos;
    public:
        Observer();
        virtual ~Observer();

        virtual void atualizar(Keyboard::Key k) = 0;
};

}