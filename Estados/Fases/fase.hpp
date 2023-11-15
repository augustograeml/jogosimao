#pragma once
#include "../../Entidades/entidade.hpp"
#include "../../Entidades/Personagens/jogador.hpp"
#include "../../Entidades/Personagens/zumbi.hpp"
#include "../../Entidades/Personagens/arqueiro.hpp"
#include "../../Listas/listaEntidades.hpp"
#include "../../Entidades/Obstaculos/obstaculo_facil.hpp"
#include "../../Entidades/Obstaculos/espinho.hpp"
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

namespace Estados
{
    namespace Fases
    {
        class Fase : public Ente, public Estado
        {
            protected:
                Listas::ListaEntidade jogadores;
                Listas::ListaEntidade obstaculos;
                Listas::ListaEntidade inimigos;
                Gerenciadores::Gerenciador_Colisoes gC;
                std::ostringstream buffer;

            public:
                Fase(int i = -1);
                ~Fase();

                virtual void executar() = 0;

                void gerenciar_colisoes();
                
                void criar_jogadores(bool jog2);
                void criar_inimigos();
                void criar_cenario(std::string caminho);

                void salvar();
        };
    }
}