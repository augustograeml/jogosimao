#pragma once
#include "estado.hpp"

namespace Estados
{
    namespace Menu
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
}