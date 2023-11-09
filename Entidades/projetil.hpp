#pragma once
#include "entidade.hpp"

namespace Entidades
{

    class Projetil : public Entidade
    {
        private:
        public:
         Projetil();
         ~Projetil();
          void executar();
    };

}