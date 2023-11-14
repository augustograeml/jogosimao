#pragma once
#include "botao.hpp"

namespace Estados
{
    namespace Menu
    {
        namespace Botao
        {     
            class Texto
            {
                private:
                    sf::Font fonte;
                    std::string indo;
                    int tamanho_fonte;
                    sf::Text texto;
                    sf::Vector2f tamanho;
                    sf::Color cor_texto;
                    sf::Color cor_borda;
                public:
                    Texto(sf::Font fonte, std::string info, int tam_fonte);
                    virtual ~Texto();
                    sf::Text get_texto();
                    void set_posicao(sf::Vector2f pos);
                    sf::Vector2f get_tamanho();
                    void set_cor(sf::Color cor);            
            };
        }
    }
}