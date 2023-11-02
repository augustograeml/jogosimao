#pragma once
#include "gerenciador_estados.hpp"


class Estado
{
    protected:
        int id;
        static Gerenciador_Estados* pGE;
    public:
        Estado(int pos = -1);
        virtual ~Estado();
        int getID();

        virtual void executar() = 0;

};