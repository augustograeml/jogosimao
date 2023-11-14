#pragma once
#include "entidade.hpp"

namespace Entidades
{
    class Projetil : public Entidade
    {
        private:
            int dano;

        public:
         Projetil();
         ~Projetil();

        void salvar(std::ostringstream* entrada){}

        void mover(){}
        void atualizar(){}
        void colidir(){}

        void executar();
    };
}