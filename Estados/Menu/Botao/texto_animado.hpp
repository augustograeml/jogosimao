#pragma once 

#include "texto.hpp"

namespace Estados
{
    namespace Menu
    {
        namespace Botao
        {     
            class Texto_Animado : public Texto
            {
                private:
                    int transparente;
                    bool clareando;
                public:
                    Texto_Animado(sf::Font corF, std::string info, int tam_fonte);
                    ~Texto_Animado();
                    void atualizar();
                    void mudar_clareando();
                    bool get_clareando();
                    void set_tranparente(int trans);
                    int get_tranparente();
                    void resetar();
            };
        }
    }
}