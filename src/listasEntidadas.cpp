#include "listaEntidadas.hpp"

ListaEntidade::ListaEntidade() : LEs()
{

}

ListaEntidade::~ListaEntidade()
{

}

void ListaEntidade::incluir(Entidade* pE)
{
    if(pE)
        LEs.incluir(pE);
}

int ListaEntidade::getTamanho()
{
    return LEs.geTamanho();
}

void ListaEntidade::desenhar()
{
    Lista<Entidade>::Iterador aux = LEs.getPrimeiro();
    while(aux != nullptr)
    {
        (*aux)->draw();
        aux.operator++();
    }
}

void ListaEntidade::executar()
{
    Lista<Entidade>::Iterador aux = LEs.getPrimeiro();
    while(aux != nullptr)
    {
        (*aux)->executar();
        aux.operator++();
    }
}

Lista<Entidade>::Iterador ListaEntidade::getPrimeiro()
{
    return LEs.getPrimeiro();
}