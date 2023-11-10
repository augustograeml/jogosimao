#include "../Listas/listaEntidades.hpp"

using namespace Entidades;
 
 namespace Listas
 {
    ListaEntidade::ListaEntidade():
    LEs()
    {

    }
    ListaEntidade::~ListaEntidade()
    {

    }
    void ListaEntidade::incluir(Entidade* pE)
    {
        LEs.incluir(pE);
    }
    void ListaEntidade::remover(Entidade* pE)
    {
        LEs.remover(pE);
    }

    const int ListaEntidade::get_tamanho() const
    {
        return LEs.get_tamanho();
    }
    void ListaEntidade::desenhar()
    {
        Lista<Entidade>::Iterador aux = LEs.get_primeiro();
        while (aux != nullptr)
        {
            (*aux)->desenhar();
            aux++;
        }
    }
    void ListaEntidade::executar()
    {
        Lista<Entidade>::Iterador aux = LEs.get_primeiro();
        while (aux != nullptr)
        {
            (*aux)->executar();
            aux++;
        }        
    }
    Lista<Entidade>::Iterador ListaEntidade::get_primeiro()
    {
        return LEs.get_primeiro();
    }
}