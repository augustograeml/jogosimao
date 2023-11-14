#include "../Estados/Menu/Botao/texto_animado.hpp"

namespace Estados
{
    namespace Menu
    {
        namespace Botao
        {     
            Texto_Animado::Texto_Animado(sf::Font corF, std::string info, int tam_f) : Texto(corF, info, tam_f)
            {

            }

            Texto_Animado::~Texto_Animado()
            {

            }

            void Texto_Animado::atualizar()
            {

            }

            void Texto_Animado::mudar_clareando()
            {

            }

            bool Texto_Animado::get_clareando()
            {
                return clareando;
            }

            int Texto_Animado::get_tranparente()
            {
                return transparente;
            }

            void Texto_Animado::set_tranparente(int trans)
            {
                transparente = trans;
            }

            void Texto_Animado::resetar()
            {

            }
        }
    }
}