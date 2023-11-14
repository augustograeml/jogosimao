#pragma once

#include "menu.hpp"
#include "../Fases/fase.hpp"
#include "../../Observers/observer_tecla.hpp"

namespace Estados
{
    namespace Menu
    {
        class Menu_Pausa : public Menu
        {
            private:
                Fases::Fase* fase;
                Observers::Observer_Tecla* observer_menu_pausa;
                sf::RectangleShape fundo_escuro;
                sf::RectangleShape fundo_painel;
            public:
                Menu_Pausa(Fases::Fase* fase);
                ~Menu_Pausa();
                void criar_botoes();
                void atualizar_fundo();
                void atualizar_nome_menu();
                void atualizar_botoes();
                void set_fase(Fases::Fase* f);
                void mudar_estado_observador();
                void executar();
        };
    }
}