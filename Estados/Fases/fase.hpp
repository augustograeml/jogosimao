#pragma once
#include "../../Entidades/entidade.hpp"
#include "../../Entidades/Personagens/jogador.hpp"
#include "../../Entidades/Personagens/zumbi.hpp"
#include "../../Entidades/Personagens/arqueiro.hpp"
#include "../../Listas/listaEntidades.hpp"
#include "../../Entidades/Obstaculos/neve.hpp"
#include "../../Entidades/Obstaculos/musgo.hpp"
#include "../../Entidades/Obstaculos/espinho.hpp"
#include "../../Entidades/Obstaculos/coracao.hpp"
#include "../../Gerenciadores/gerenciador_colisoes.hpp"
#include "../estado.hpp"

#include <iostream>
#include <sstream>
#include <fstream>
#include "json.hpp"

#define ARQUIVO_CENARIO_1 "Design/Fase1/Cenario/cenario1.txt"
#define ARQUIVO_CENARIO_2 "Design/Fase2/Cenario/cenario2.txt"

namespace Estados
{
    namespace Fases
    {
        class Fase : public Ente, public Estado
        {
            protected:
                sf::Texture Textura;
                sf::RectangleShape shape;
                sf::Vector2f vel;

                Listas::ListaEntidade jogadores;
                Listas::ListaEntidade obstaculos;
                Listas::ListaEntidade inimigos;
                Gerenciadores::Gerenciador_Colisoes gC;
                std::ostringstream buffer;

               

            public:
                Fase(int i = -1);
                ~Fase();

                void gerenciar_colisoes();
                void criar_jogadores(bool jog2);
                void criar_inimigos();
                void criar_cenario(std::string caminho, int n1, int n2, int n3, int n4, int n5);

                virtual void executar() = 0;
                virtual void fim_de_jogo() = 0;
                virtual void mover() = 0;
                virtual void atualizar() = 0;

                void salvar();
        };
    }
}