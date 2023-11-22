#pragma once
#include "../Gerenciadores/gerenciador_estados.hpp"

namespace Estados
{
    class Estado
    {
        protected:
            int id;
            static Gerenciadores::Gerenciador_Estados* pGE;
        public:
            Estado(int id = -1);
            virtual ~Estado();

            void setID(int num);
            int getID();

            virtual void executar() = 0;
    };
}