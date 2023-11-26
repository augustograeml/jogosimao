#pragma once

#include <SFML/Graphics.hpp>

#include "Estados/Menus/menu_principal.hpp"
#include "Estados/Menus/ranking.hpp"
#include "Estados/Menus/pause.hpp"
#include "Estados/Menus/menu_fase.hpp"
#include "Estados/Menus/menu_jogadores.hpp"

#include "Estados/Fases/fase1.hpp"
#include "Estados/Fases/fase2.hpp"

#include "Gerenciadores/gerenciador_grafico.hpp"
#include "Gerenciadores/gerenciador_estados.hpp"
#include "Gerenciadores/gerenciador_eventos.hpp"

class Jogo
{
    private:
        Estados::Menus::Pause* pause;
        Estados::Menus::Ranking* ranking;
        Estados::Menus::Menu_Principal* menu_principal;
        Estados::Menus::Menu_Jogadores* menu_jogadores;
        Estados::Menus::Menu_Fase* menu_fase;

        Gerenciadores::Gerenciador_Grafico* pG;
        Gerenciadores::Gerenciador_Estados* pE;
        Gerenciadores::Gerenciador_Eventos* pEv;
    public:
        Jogo();
        ~Jogo();

        void Executar();
        void reseta_fase();
};