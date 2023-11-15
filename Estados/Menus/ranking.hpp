#pragma once

#define RANKING "../ranking.json"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "../../Observers/observer_ranking.hpp"
#include "../../Entidades/entidade.hpp"

#include "menu.hpp"

namespace Estados
{
    namespace Menus
    {
        class Ranking : public Menu
        {
            private:
                Texto primeiro;
                Texto segundo;
                Texto terceiro;
                Observers::Observer_Ranking*  pRObserver;
                bool botoes_ativos;
                std::multimap<int, std::string, std::greater<int>> ranking;
                std::ostringstream buffer;
            public:
                Ranking();
                ~Ranking();
                void selecionar();
                void desenhar();
                void carregar();
                void salvar(std::ostringstream* entrada);
                void adicinar_novo_ranking(int points, std::string name);
        };
    }
}