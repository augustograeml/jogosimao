#pragma once 
#include "../../Gerenciadores/gerenciador_grafico.hpp"
#include "../Fases/fase.hpp"
#include "menu.hpp"
#include <SFML/Graphics.hpp>

namespace Estados
{
    namespace Menus
    {
        class Pause : public Menu
        {
            private:
                bool pausado;
            public:
                Pause(int id);
                ~Pause();

                void inicializa_valores();
                void loop_evento();
                void mostrar_menu();
                void executar();
        };
    }
}