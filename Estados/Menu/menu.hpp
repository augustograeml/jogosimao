#pragma once
#include "../Estados/estado.hpp"

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