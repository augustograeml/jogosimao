#include "gerenciador_eventos.hpp"
#include "observer.hpp"

Gerenciador_Eventos* Gerenciador_Eventos::instancia(nullptr);

Gerenciador_Eventos::Gerenciador_Eventos() : pGrafico(Gerenciador_Grafico::get_instancia()),
lista_observers(), it()
{

}

Gerenciador_Eventos::~Gerenciador_Eventos()
{
    pGrafico = nullptr;
    for(it = lista_observers.begin(); it != lista_observers.end(); it++)
    {
        delete *it;
    }
    lista_observers.clear();
}

Gerenciador_Eventos* Gerenciador_Eventos::get_instancia()
{
    if(!instancia)
        instancia = new Gerenciador_Eventos();

    return instancia;
}

void Gerenciador_Eventos::executar()
{
    while(pGrafico->get_Janela()->pollEvent(evento))
    {
        switch(evento.type)
        {
             case Event::Closed:
                pGrafico->fecharJanela();
                break;
            case Event::KeyPressed:
                notificar(evento.key.code);
               break;
            default:
                break;   
        }
    }
}

void Gerenciador_Eventos::anexar(Observer* obs)
{
    if(obs)
        lista_observers.push_back(obs);
}

void Gerenciador_Eventos::remover(Observer* obs)
{
    lista_observers.remove(obs);
}

void Gerenciador_Eventos::notificar(Keyboard::Key k)
{
    for(it = lista_observers.begin(); it != lista_observers.end(); it++)
    {
        (*it)->atualizar(k);
    }
}