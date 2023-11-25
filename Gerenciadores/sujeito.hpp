#pragma once 
#include <list>
#include "gerenciador_grafico.hpp"

namespace Observers
{
    class Observer;
}

namespace Gerenciadores
{
    class Sujeito
    {
        protected:
            std::list<Observers::Observer*> lista_observers;
            std::list<Observers::Observer*>::iterator it;
        public:
            Sujeito();
            virtual ~Sujeito();
            virtual void anexar(Observers::Observer* pObserver);
            virtual void remover(Observers::Observer* pObserver);
            virtual void notificar(sf::Keyboard::Key k);
    };
}