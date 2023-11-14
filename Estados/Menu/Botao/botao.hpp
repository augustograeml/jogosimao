#pragma once

#include <SFML/Graphics.hpp>

namespace Estados
{
    namespace Menu
    {
        namespace Botao
        {     
            class Botao
            {
                protected:
                    sf::RectangleShape caixa_de_texto;
                    sf::Text texto;
                    sf::Vector2f posicao;
                    sf::Vector2f tamanho;
                    bool selecionado;
                    sf::Color cor_selecionada;
                    sf::Clock relogio;
                    float tempo_trocar_cor;
                    float tempo;
                public:
                    Botao(std::string informacao, sf::Vector2f pos, sf::Vector2f tam, sf::Color cor_sel);
                    virtual ~Botao();
                    void desenhar();
                    void atualizar_texto();
                    void set_selecionado(bool sel);
                    bool get_selecionado();
                    void atualizar_posicao(sf::Vector2f pos);
                    sf::Vector2f get_posicao();
            };
        }
    }
}