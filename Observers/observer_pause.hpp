#pragma once
#include "observer.hpp"

namespace Estados
{
    namespace Menus
    {
        class Pause;
    }
}

namespace Observers
{
    class Observer_Pause : public Observer
    {
        private:
            Estados::Menus::Pause* pMenu;
        public:
            Observer_Pause();
            ~Observer_Pause();

            
    };
}