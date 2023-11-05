#include "listaEntidadas.hpp"
#include <iostream>

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
        (*aux)->desenhar();
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