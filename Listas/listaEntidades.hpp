#pragma once

#include "lista.hpp"
#include "../Entidades/entidade.hpp"

 // Coleção
namespace Listas
{
    class ListaEntidade
    {
        private:
            Lista<Entidades::Entidade> LEs;
        public:
            ListaEntidade();
            ~ListaEntidade();
            void incluir(Entidades::Entidade* pE);
            void remover(Entidades::Entidade *pE);
            const int get_tamanho() const;
            void desenhar();
            void executar();
            Lista<Entidades::Entidade>::Iterador get_primeiro();
        };
}