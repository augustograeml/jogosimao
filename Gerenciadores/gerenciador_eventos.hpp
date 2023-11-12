#pragma once
#include "gerenciador_grafico.hpp"
#include <SFML/Graphics.hpp>
#include <list>

using namespace sf;
using namespace std;

namespace Observers
{
    class Observer;
}

namespace Gerenciadores
{
    class Gerenciador_Eventos
    {
        private:
            Gerenciador_Grafico* pGrafico;
            static Gerenciador_Eventos* instancia;
            Gerenciador_Eventos();
            Event evento;

            list<Observers::Observer*> lista_observers;
            list<Observers::Observer*>::iterator it;
        public:
            ~Gerenciador_Eventos();
            void executar();
            static Gerenciador_Eventos* get_instancia();

            void anexar(Observers::Observer* obs);
            void remover(Observers::Observer* obs);
            void notificar(sf::Keyboard::Key k);
    };

}