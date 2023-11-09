#pragma once
#include <SFML/Graphics.hpp>
#include "../Estados/Fases/fase1.hpp"
#include "../Gerenciadores/gerenciador_grafico.hpp"
#include "../Gerenciadores/gerenciador_estados.hpp"
#include "../Gerenciadores/gerenciador_eventos.hpp"
#include "../Observers/observer_tecla.hpp"

using namespace sf;
using namespace Observers;

class Jogo
{
    private:
        Gerenciador_Grafico* pG;
        Gerenciador_Estados* pE;
        Gerenciador_Eventos* pEv;

        Observer_Tecla obs1;
        Observer_Tecla obs2;
    public:
        Jogo();
        ~Jogo();

        void Executar();
};