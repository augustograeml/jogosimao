#include "../Estados/Fases/fase2.hpp"

namespace Estados
{
    namespace Fases
    {
        Fase2::Fase2() : Fase(2), musgos(false)
        {
            int i = rand() % 10;
            if(i == 3)
                musgos = true;

            Textura.loadFromFile("Design/imagens/cenario_op1.jpg");
            shape.setSize(Vector2f(950.f, 950.f));
            shape.setTexture(&Textura);
            shape.setPosition(sf::Vector2f(76.f, -10.f));

            criar_cenario(ARQUIVO_CENARIO_2);
        }

        Fase2::~Fase2()
        {

        }

        void Fase2::fim_de_jogo()
        {
            Textura.loadFromFile("Design/imagens/fim_de_jogo1.jpeg");
            shape.setSize(Vector2f(950.f, 950.f));
            shape.setTexture(&Textura);
            shape.setPosition(sf::Vector2f(76.f, -10.f));
            pGG->desenharFundo(&shape);
        }

        void Fase2::executar()
        {

        }

        void Fase2::mover()
        {

        }

        void Fase2::atualizar()
        {

        }

        bool Fase2::get_musgos()
        {
            return musgos;
        }
    }
}