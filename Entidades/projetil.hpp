#pragma once
#include "entidade.hpp"

namespace Entidades
{
    class Projetil : public Entidade
    {
        private:
            int dano;

        public:
         Projetil(sf::Vector2f tam);
         ~Projetil();

        void salvar(std::ostringstream* entrada){}

        int get_dano(){return dano;}
        void mover();
        void danar(Entidade* pE);
        void atualizar();
        void colidir(Entidade* pE, int a);

        void executar();
    };
}