#pragma once
#include "estado.hpp"

class Menu : public Estado
{
    protected:
    public:
        Menu();
        ~Menu();
        virtual void executar();
};