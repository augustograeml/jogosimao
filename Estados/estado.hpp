#pragma once
#include "../Gerenciadores/gerenciador_estados.hpp"

using namespace Gerenciadores;

namespace Estados
{
    class Estado
    {
        protected:
            int id;
            static Gerenciadores::Gerenciador_Estados* pGE;
        public:
            Estado(int pos = -1);
            virtual ~Estado();
            int getID();

            virtual void executar() = 0;
    };
}