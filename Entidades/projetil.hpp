#pragma once
#include "entidade.hpp"

namespace Entidades
{
    class Projetil : public Entidade
    {
        private:
            int dano;

        public:
         Projetil(sf::Vector2f pos = sf::Vector2f(0.f,0.f));
         ~Projetil();

        void salvar(std::ostringstream* entrada){}

        void mover();
        void atualizar() ;
        void colidir();

        void executar();
    };
}