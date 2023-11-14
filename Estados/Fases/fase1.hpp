#pragma once
#include "fase.hpp"
#define ARQUIVO_CENARIO_1 "Design/Fase1/Cenario/cenario1.txt"

namespace Estados
{
    namespace Fases
    {
        class Fase1 : public Fase
        {
            private:
                sf::Texture Textura;
                sf::RectangleShape shape;
            public:
                Fase1();
                ~Fase1();
                
                void executar();
                void mover();
                void atualizar();
        };
    }
}
