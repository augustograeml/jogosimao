#pragma once

#include "lista.hpp"
#include "../Entidades/entidade.hpp"

using namespace Entidades;

 // Coleção
namespace Listas
{
    class ListaEntidade
    {
    private:
        Lista<Entidade> LEs;
    public:
        ListaEntidade();
        ~ListaEntidade();
        void incluir(Entidade* pE);
        void remover(Entidade *pE);
        const int get_tamanho() const;
        // void percorrer();
        void desenhar();
        void executar();
        Lista<Entidade>::Iterador get_primeiro();
    };
}