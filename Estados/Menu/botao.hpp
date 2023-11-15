#pragma once

#include <SFML/Graphics.hpp>
#include "../Gerenciadores/gerenciador_grafico.hpp"

#define TAMANHO_BOTAO_X 60.f
#define TAMANHO_BOTAO_Y 200.f

namespace Estados
{
    namespace Menus
    {
        class Botao
        {
            private:
                //peteco tec_prog
                sf::Text texto;
                sf::RectangleShape corpo;
                static Gerenciadores::Gerenciador_Grafico* pGG;
            public:
                Botao(sf::Vector2f posicao = sf::Vector2f(0.f, 0.f));
                ~Botao();
                void desenhar();
                void muda_cor();
                void set_nome(std::string nome);
                bool set_position(sf::Vector2f posicao);
        };
    }
}