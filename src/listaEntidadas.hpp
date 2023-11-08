#pragma once

#include "lista.hpp"
#include "entidade.hpp"

 // Coleção
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