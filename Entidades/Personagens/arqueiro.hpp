#pragma once
#include "inimigo.hpp"
#include "../projetil.hpp"
#define TEMPO_RECARGA 100

namespace Entidades
{
    namespace Personagens
    {
        class Arqueiro : public Inimigo
        {
            private:
            Projetil novo;
            int recarregar;
            bool atirando;

            public:
                Arqueiro(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f));
                ~Arqueiro();

                void executar();
                void mover();
                void atualizar();
                void atirar();
                Projetil* get_projetil() {return &novo;}
                void atacar(Entidade* jg);
                void salvar(std::ostringstream* entrada);
        };
    }
}