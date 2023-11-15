#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>

#include "menu.hpp"
#include "ranking.hpp"
#include "../../Observers/observer_fim_de_jogo.hpp"
#include "ranking.hpp"

//#include "../entities/Hud.h"

namespace Estados
{
    namespace Menus
    {
        class Fim_de_Jogo : public Menu
        {
            private:
                std::string nome_string;
                std::string str_pontos;

                Texto nome;
                Texto instrucoes;

                Observers::Observer_Fim_Jogo* pFJObserver;

                bool botoes_ativos;
                bool nomes_ativo;
                bool nome_final;

                Ranking* ranking;
            public:
                Fim_de_Jogo(Ranking* rk);
                ~Fim_de_Jogo();

                void desenhar();
                void adicionar_nome(std::string n);
                void set_nome_final();
                void set_pontos(int p);
                std::string get_nome_string();
                void nome_ativo();
                void selecionar();
                void salvar();
                void desenhar_botao();
                void resetar();
        };
    }
}