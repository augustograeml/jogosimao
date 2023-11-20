#pragma once
#include "inimigo.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class Arqueiro : public Inimigo
        {
            private:
            public:
                ~Arqueiro();

                void executar();
                void mover();
                void atualizar();
                void atacar(Entidade* jg);
                void salvar(std::ostringstream* entrada);
        };
    }
}