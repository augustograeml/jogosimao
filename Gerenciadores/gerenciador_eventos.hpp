//codigo reaproveitado do Peteco

#pragma once
#include "gerenciador_grafico.hpp"
#include <SFML/Graphics.hpp>
#include <list>

using namespace sf;
using namespace std;

namespace Gerenciadores
{
    class Gerenciador_Eventos
    {
        private:
            Gerenciador_Grafico* pGrafico;
            static Gerenciador_Eventos* instancia;
            Gerenciador_Eventos();
            Event evento;
        public:
            ~Gerenciador_Eventos();
            void executar();
            static Gerenciador_Eventos* get_instancia();
    };

}