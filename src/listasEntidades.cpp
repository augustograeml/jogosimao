#include "../Listas/listaEntidades.hpp"
 
 namespace Listas
 {
    ListaEntidade::ListaEntidade():
    LEs()
    {

    }
    ListaEntidade::~ListaEntidade()
    {

    }
    void ListaEntidade::incluir(Entidades::Entidade* pE)
    {
        LEs.incluir(pE);
    }
    void ListaEntidade::remover(Entidades::Entidade* pE)
    {
        LEs.remover(pE);
    }

    const int ListaEntidade::get_tamanho() const
    {
        return LEs.get_tamanho();
    }
    void ListaEntidade::desenhar()
    {
        Lista<Entidades::Entidade>::Iterador aux = LEs.get_primeiro();
        while (aux != nullptr)
        {
            if((*aux)->get_vivo())
            (*aux)->desenhar();
            aux++;
        }
    }
    void ListaEntidade::executar()
    {
        Lista<Entidades::Entidade>::Iterador aux = LEs.get_primeiro();
        while (aux != nullptr)
        {
            (*aux)->executar();
            aux++;
        }        
    }
    Lista<Entidades::Entidade>::Iterador ListaEntidade::get_primeiro()
    {
        return LEs.get_primeiro();
    }
}