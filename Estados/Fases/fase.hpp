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
#include "../estado.hpp"

#include <iostream>
#include <sstream>
#include <fstream>
#include "json.hpp"

#define ARQUIVO_CENARIO_1 "Design/txts/cenario_fase1.txt"
#define ARQUIVO_CENARIO_2 "Design/txts/cenario_fase2.txt"

namespace Estados
{
    namespace Fases
    {
        class Fase : public Ente, public Estado
        {
            protected:
                bool ja_criado;
                static int pontos;
                sf::Font* fonte;
                sf::Texture* textura_getNome;

                sf::Texture Textura;
                sf::RectangleShape shape;
                sf::Vector2f vel;

                Listas::ListaEntidade jogadores;
                Listas::ListaEntidade obstaculos;
                Listas::ListaEntidade inimigos;
                Listas::ListaEntidade projeteis;

                Gerenciadores::Gerenciador_Colisoes gC;
                std::ostringstream buffer;
                int num_entidades[6];
                int num_jogadores;
                std::string playerName;

            public:
                Fase(int i = -1);
                ~Fase();

                void gerenciar_colisoes();
                void set_num_jogadores(int i) {num_jogadores = i;}
                void criar_jogadores(bool jog2);
                void criar_inimigos();
                void criar_cenario(std::string caminho, int n1, int n2, int n3, int n4, int n5, int n6, bool ja_criado);

                void getNome();
                void pontuar();
                //void salvar_pontuacao(std::string caminho);
                void set_pontos(int a)  {pontos = a;}
                int get_pontos() {return pontos;}
                const bool get_jaCriado();
                const bool get_jogador2();

                virtual void executar() = 0;
                virtual void fim_de_jogo() = 0;
                virtual void atualizar() = 0;

                //void set_tempo_jogadores();
                Listas::ListaEntidade* get_jogadores() {return &jogadores;} 
                void salvar();
        };
    }
}