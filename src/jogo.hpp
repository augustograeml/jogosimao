#pragma once
#include <SFML/Graphics.hpp>
#include "fase1.hpp"
#include "gerenciador_grafico.hpp"
#include "gerenciador_estados.hpp"
#include "gerenciador_eventos.hpp"
#include "observer_tecla.hpp"

using namespace sf;

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