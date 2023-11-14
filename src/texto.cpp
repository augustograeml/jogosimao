#include "../Estados/Menu/Botao/texto.hpp"

namespace Estados
{
    namespace Menu
    {
        namespace Botao
        {     
            Texto::Texto(sf::Font fon, std::string info, int tamanho_fonte)
            {
                cor_texto = sf::Color::Green;
                cor_borda = sf::Color::Red;
            }

            Texto::~Texto()
            {

            }

            sf::Text Texto::get_texto()
            {
                return texto;
            }

            void Texto::set_posicao(sf::Vector2f pos)
            {
                
            }

            sf::Vector2f Texto::get_tamanho()
            {
                return tamanho;
            }

            void Texto::set_cor(sf::Color cor)
            {
                cor_texto = cor;
            }
        }
    }
}