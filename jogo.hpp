#pragma once

#include <SFML/Graphics.hpp>
#include "Estados/Menu/menu.hpp"
#include "Estados/Menu/menu_fase.hpp"
#include "Estados/Menu/menu_fase2.hpp"
#include "Estados/Menu/menu_jogadores.hpp"
#include "Estados/Fases/fase1.hpp"
#include "Estados/Fases/fase2.hpp"
#include "Gerenciadores/gerenciador_grafico.hpp"

#include "Gerenciadores/gerenciador_estados.hpp"
#include "Gerenciadores/gerenciador_eventos.hpp"
#include "Observers/observer_tecla.hpp"

class Jogo
{
    private:

        Estados::Menus::Menu* menu;
        Estados::Menus::Menu_Jogadores* menu_jogadores;
        Estados::Menus::Menu_Fase* menu_fase;
        Estados::Menus::Menu_Fase2* menu_fase2;
        Gerenciadores::Gerenciador_Grafico* pG;
        Gerenciadores::Gerenciador_Estados* pE;
        Gerenciadores::Gerenciador_Eventos* pEv;
        
        Observers::Observer_Tecla obs1;
        Observers::Observer_Tecla obs2;
    public:
        Jogo();
        ~Jogo();

        void Executar();
};