#pragma once
#include "gerenciador_grafico.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;

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