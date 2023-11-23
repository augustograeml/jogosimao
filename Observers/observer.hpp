//codigo reaproveitado do Monitor Giovane

#pragma once

#include "SFML/Graphics.hpp"
#include "../Gerenciadores/gerenciador_eventos.hpp"
#include "../Gerenciadores/gerenciador_estados.hpp"

namespace Observers
{
    class Observer
    {
        protected:
            static Gerenciadores::Gerenciador_Eventos* pGer_Eventos;
            static Gerenciadores::Gerenciador_Estados* pGer_Estados;
        private:
            bool ativar;
        public:
            Observer();
            virtual ~Observer();

            void mudar_estado_ativar();
            const bool get_ativar() const;
            void remover_observador();

            virtual void tecla_pressionada(const sf::Keyboard::Key tecla) = 0;
            virtual void tecla_solta(const sf::Keyboard::Key tecla) = 0;

            virtual void atualizar(sf::Keyboard::Key k) = 0;
    };

}