#include "../Entidades/Obstaculos/neve.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Neve::Neve(Vector2f pos): Obstaculo(pos, false), escorrega(false)
        {
            this->setSkin("Design/imagens/plataforma.png");
            this->set_vida(1);
        }

        Neve::~Neve()
        {

        }

        void Neve::executar()
        {
            
        }

        void Neve::mover()
        {
            
        }

        void Neve::atualizar()
        {
            
        }
    }
}