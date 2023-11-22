//codigo reaproveitado do Peteco

#pragma once

#include "Gerenciadores/gerenciador_grafico.hpp"

#include <SFML/Graphics.hpp>

class Ente
{
    protected:
        int id;
        static Gerenciadores::Gerenciador_Grafico* pGG;
        sf::RectangleShape corpo;
    public:
        Ente(sf::Vector2f tamanho = sf::Vector2f(20.f, 20.f));
        ~Ente();
        virtual void executar() = 0;
        sf::RectangleShape* get_corpo();
        void desenhar();
};