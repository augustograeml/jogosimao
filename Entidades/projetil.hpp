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

        int get_dano(){return dano;}
        void mover(){}
        void atirar();
        void atualizar(){}
        void colidir(Entidade* pE, int a);

        void executar();
    };
}