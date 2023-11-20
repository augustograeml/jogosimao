#pragma once

#include "SFML/Graphics.hpp"
#include "../Gerenciadores/gerenciador_eventos.hpp"
#include "../Gerenciadores/gerenciador_grafico.hpp"
#include "../Gerenciadores/gerenciador_estados.hpp"

namespace Observers
{
    class Observer
    {
        protected:
            static Gerenciadores::Gerenciador_Eventos* pGer_Eventos;
            static Gerenciadores::Gerenciador_Estados* pGer_Estados;
            static Gerenciadores::Gerenciador_Grafico* pGer_Grafico;
        public:
            Observer();
            virtual ~Observer();

            virtual void atualizar(sf::Keyboard::Key k) = 0;
    };

}