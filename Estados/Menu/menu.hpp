#pragma once
#include "estado.hpp"

namespace Estados
{

class Menu : public Estado
{
    protected:
    public:
        Menu();
        ~Menu();
        virtual void executar();
};

}