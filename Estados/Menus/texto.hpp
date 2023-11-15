#pragma once
#include "botao.hpp"

namespace Estados
{
    namespace Menus
    {
        class Texto
        {
        private:
            sf::Text texto;
            static Gerenciadores::Gerenciador_Grafico* pGG;
        public:
            Texto(std::string n = " ");
            ~Texto();

            void set_posicao(sf::Vector2f pos);
            void set_tamanho(int t);
            void set_nome(std::string n);
            void desenhar();
            void set_cor(int c);            
        };
    }
}