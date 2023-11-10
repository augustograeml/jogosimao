#pragma once

#include "../Gerenciadores/gerenciador_grafico.hpp"
#include "../Listas/lista.hpp"
#include "../Listas/listaEntidades.hpp"

#include <SFML/Graphics.hpp>

using namespace Listas;
using namespace Gerenciadores;
using namespace sf;

class Ente
{
    protected:
        int id;
        static Gerenciador_Grafico* pGG;
        RectangleShape corpo;
    public:
        Ente(Vector2f tamanho = Vector2f(20.f, 20.f));
        ~Ente();
        virtual void executar() = 0;
        RectangleShape* get_corpo();
        void desenhar();
};