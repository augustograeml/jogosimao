#pragma once

#include <SFML/Graphics.hpp>
#include "Estados/Fases/fase1.hpp"
#include "Gerenciadores/gerenciador_grafico.hpp"

#include "Estados/Menus/menu_principal.hpp"
#include "Estados/Menus/fim_de_jogo.hpp"
#include "Estados/Menus/ranking.hpp"

#include "Gerenciadores/gerenciador_estados.hpp"
#include "Gerenciadores/gerenciador_eventos.hpp"
#include "Observers/observer_tecla.hpp"

class Jogo
{
    private:
        Gerenciadores::Gerenciador_Grafico* pG;
        Gerenciadores::Gerenciador_Estados* pE;
        Gerenciadores::Gerenciador_Eventos* pEv;

        Estados::Menus::Menu_Principal menu;
        Estados::Menus::Fim_de_Jogo fim;
        Estados::Menus::Ranking ranking;

        Observers::Observer_Tecla obs1;
        Observers::Observer_Tecla obs2;
    public:
        Jogo();
        ~Jogo();

        void Executar();
};