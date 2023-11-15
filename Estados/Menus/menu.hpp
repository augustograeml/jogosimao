#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "../../ente.hpp"
#include "../estado.hpp"
#include "texto.hpp"
#include "botao.hpp"
#include "../../Gerenciadores/gerenciador_eventos.hpp"
#include "../../Observers/observer_menu.hpp"
#include "botao.hpp"
#include <list>


namespace Estados
{
    namespace Menus
    {
        class Menu : public Ente, public Estado
        {
            protected:
                int MAX_BOTOES;
                std::vector<Botao*> botoes;
                int indice;
                sf::RectangleShape corpo;
                Texto titulo;
            public:
                Menu(int n_bot = 0, int id = -1, std::string t = "0");
                ~Menu();
                virtual void desenhar();
                void mover_pra_cima();
                void mover_pra_baixo();
                virtual void selecionar() = 0;
                void executar();
                void mudar_nome(std::string n);
        };
    }
}