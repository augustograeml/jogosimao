#pragma once
#include "lista.hpp"
#include "entidade.hpp"

class ListaEntidade
{
    private:
        Lista<Entidade> LEs;
    public:
        ListaEntidade();
        ~ListaEntidade();
        void incluir(Entidade* pE);
        int getTamanho();
        void desenhar();
        void executar();
        Lista<Entidade>::Iterador getPrimeiro();

};