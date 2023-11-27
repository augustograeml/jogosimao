#pragma once
#include "inimigo.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class Zumbi : public Inimigo
        {
            private:
                int pulo;
            public:
                Zumbi(Vector2f pos = Vector2f(0.f, 0.f), Vector2f vel = Vector2f(0.f, 0.f));
                ~Zumbi();

                void mover();
                void atualizar();
                void executar();
                void colidir(Entidade* pE, int a);
                void atacar(Entidade* jg);
                std::vector<Projetil>* get_projeteis() {return nullptr;}
                void salvar(std::ostringstream* entrada);
                
        };
    }
}