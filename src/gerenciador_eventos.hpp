#pragma once
#include "gerenciador_grafico.hpp"
#include <SFML/Graphics.hpp>
#include <list>

using namespace sf;
using namespace std;

class Observer;

class Gerenciador_Eventos
{
    private:
        Gerenciador_Grafico* pGrafico;
        static Gerenciador_Eventos* instancia;
        Gerenciador_Eventos();
        Event evento;

        list<Observer*> lista_observers;
        list<Observer*>::iterator it;
    public:
        ~Gerenciador_Eventos();
        void executar();
        static Gerenciador_Eventos* get_instancia();

        void anexar(Observer* obs);
        void remover(Observer* obs);
        void notificar(Keyboard::Key k);
        

};