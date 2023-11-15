#include "../Estados/Menu/botao.hpp"

#define TAM 50.f

namespace Estados
{
    namespace Menus
    {
           
        Botao::Botao(sf::Vector2f pos) : corpo(sf::Vector2f(TAM, TAM)), texto()
        {
            corpo.setOrigin(sf::Vector2f(TAM / 2.f, TAM / 2.f));
            texto.setOrigin(sf::Vector2f(TAM / 2.f - 50.f, TAM / 2.f - 25.f));

            corpo.setFillColor(sf::Color(240,230,140));
            corpo.setOutlineThickness(6);
            corpo.setOutlineColor(sf::Color::Black);

            //texto.setFont(*pGG->get_fonte());
            texto.setFillColor(sf::Color(65, 130, 190));
            texto.setCharacterSize(50);

            corpo.setPosition(pos);
            texto.setPosition(pos);
            texto.setOutlineThickness(3.f);
            texto.setOutlineColor(sf::Color:: Black);
        }

        Botao::~Botao()
        {

        }

        void Botao::desenhar()
        {
            pGG->desenharFundo(&corpo);
            pGG->desenharTexto(&texto);
        }

        void Botao::muda_cor()
        {
            if(corpo.getFillColor() == sf::Color(240, 230, 140))
                corpo.setFillColor(sf::Color(205,92,92));
            else
                corpo.setFillColor(sf::Color(240,230,140));
        }

        void Botao::set_nome(std::string n)
        {
            texto.setString(n);
        }
        
        void Botao::set_posicao(sf::Vector2f pos)
        {
            corpo.setPosition(pos);
            texto.setPosition(pos);
        }
        
    }
}