//codigo reaproveitado do Peteco

#pragma once

#include "observer.hpp"
#include "../Estados/Fases/fase.hpp"

namespace Observers
{
    class Observer_Fase : public Observer
    {
        private:
            Estados::Fases::Fase* fase;
        public:
            Observer_Fase();
            ~Observer_Fase();

            void set_fase(Estados::Fases::Fase* f);
            void tecla_pressionada(const sf::Keyboard::Key tecla);
            void tecla_solta(const sf::Keyboard::Key tecla);
            void notificar_jogador_morreu();
    };
}

