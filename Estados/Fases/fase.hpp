#pragma once
#include "../../Entidades/entidade.hpp"
#include "../../Entidades/Personagens/jogador.hpp"
#include "../../Entidades/Personagens/jogador2.hpp"
#include "../../Entidades/Personagens/inimigo_facil.hpp"
#include "../../Entidades/Personagens/inimigo_dificil.hpp"
#include "../../Listas/listaEntidades.hpp"
#include "../../Entidades/Obstaculos/obstaculo_facil.hpp"
#include "../../Gerenciadores/gerenciador_colisoes.hpp"
#include "../estado.hpp"

namespace Estados
{
    namespace Fases
    {
        class Fase : public Entidades::Entidade, public Estado
        {
            protected:
                Listas::ListaEntidade jogadores;
                Listas::ListaEntidade obstaculos;
                Listas::ListaEntidade inimigos;
                Gerenciadores::Gerenciador_Colisoes gC;

            public:
                Fase(int i = -1);
                ~Fase();

                virtual void executar() = 0;

                void gerenciar_colisoes();
                void criar_inimigos();
                void criar_jogadores();
                void criar_cenario(string caminho);
        };
    }
}