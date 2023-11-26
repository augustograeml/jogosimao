//codigo reaproveitado do Peteco6

#pragma once

#include "../../Entidades/entidade.hpp"
#include "../../Entidades/Personagens/jogador.hpp"
#include "../../Entidades/Personagens/zumbi.hpp"
#include "../../Entidades/Personagens/arqueiro.hpp"
#include "../../Entidades/Personagens/gigante.hpp"
#include "../../Listas/listaEntidades.hpp"
#include "../../Entidades/Obstaculos/neve.hpp"
#include "../../Entidades/Obstaculos/musgo.hpp"
#include "../../Entidades/Obstaculos/espinho.hpp"
#include "../../Entidades/Obstaculos/caixa.hpp"
#include "../../Entidades/Obstaculos/coracao.hpp"
#include "../../Gerenciadores/gerenciador_colisoes.hpp"
#include "../../Gerenciadores/gerenciador_estados.hpp"
#include "../../Gerenciadores/gerenciador_eventos.hpp"
#include "../../Gerenciadores/gerenciador_grafico.hpp"
#include "../../Observers/observer_menu_fase.hpp"
#include "../estado.hpp"

#include <iostream>
#include <sstream>
#include <fstream>
#include "json.hpp"

#define ARQUIVO_CENARIO_1 "Design/cenario/cenario_fase1.txt"
#define ARQUIVO_CENARIO_2 "Design/cenario/cenario_fase2.txt"

namespace Estados
{
    namespace Fases
    {
        class Fase : public Ente, public Estado
        {
            protected:
                //static Observers::Observer_Fase observador_fase;

                bool ja_criado;
                bool jogador2;

                sf::Texture Textura;
                sf::RectangleShape shape;
                sf::Vector2f vel;

                Listas::ListaEntidade jogadores;
                Listas::ListaEntidade obstaculos;
                Listas::ListaEntidade inimigos;

                Gerenciadores::Gerenciador_Colisoes gC;
                std::ostringstream buffer;
                int num_obstaculos;
                int numero_entidades_salvamento[4];
                int num_jogadores;
                int num_arqueiros;
                int num_gigante;
                int num_zumbis;
                sf::Clock relogio;

            public:
                Fase(int i = -1, bool ja = false);
                ~Fase();

                void gerenciar_colisoes();
                void set_num_jogadores(int i) {num_jogadores = i; get_jogador2();}
                void criar_jogadores();
                void criar_inimigos(string cenario);
                void criar_cenario(std::string caminho/*, int numero_espinhos, int numero_coracao, int numero_caixas*/);

                void carregar_jogadores_salvos();
                void carregar_inimigos_salvos();

                const bool get_jaCriado();
                const bool get_jogador2();

                virtual void executar() = 0;
                virtual void fim_de_jogo() = 0;
                virtual void atualizar() = 0;

                void set_tempo_jogadores();
                void salvar();
        };
    }
}