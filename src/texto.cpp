#include "../Estados/Menus/texto.hpp"

namespace Estados
{
    namespace Menus
    {
        Gerenciadores::Gerenciador_Grafico* Texto::pGG(Gerenciadores::Gerenciador_Grafico::get_instancia());

        Texto::Texto(std::string info)
        {
            texto.setString(info);
            texto.setFont(*pGG->get_fonte());
            texto.setCharacterSize(30);
            texto.setOrigin(15.f,15.f);
            texto.setPosition(sf::Vector2f(100.f, 25.f));
            texto.setFillColor(sf::Color:: White);
            texto.setOutlineThickness(5.f);
            texto.setOutlineColor(sf::Color:: Black);
        }

        Texto::~Texto()
        {

        }

        void Texto::set_posicao(sf::Vector2f pos)
        {
            texto.setPosition(pos);
        }

        void Texto::set_tamanho(int t)
        {
            texto.setCharacterSize(t);
        }

        void Texto::set_nome(std::string n)
        {
            texto.setString(n);
        }

        void Texto::desenhar()
        {
            pGG->desenharTexto(&texto);
        }

        void Texto::set_cor(int c)
        {
            if(!c)
                texto.setFillColor(sf::Color(255, 165, 0));
        }

    }
}