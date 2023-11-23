//codigo reaproveitado do Peteco

#include "../Observers/observer_fase.hpp"

namespace Observers
{
    Observer_Fase::Observer_Fase() : Observer(), fase(nullptr)
    {

    }

    Observer_Fase::~Observer_Fase()
    {

    }

    void Observer_Fase::tecla_pressionada(const sf::Keyboard::Key tecla)
    {

    }

    void Observer_Fase::set_fase(Estados::Fases::Fase* f)
    {
        this->fase = f;
    }
    
    void Observer_Fase::tecla_solta(const sf::Keyboard::Key tecla)
    {
        if(tecla == sf::Keyboard::Escape || tecla == sf::Keyboard::P)
            pGer_Estados->set_estado_atual(0);
    }

    void Observer_Fase::notificar_jogador_morreu()
    {
        //setar pro estado do game over
        //pGer_Estados->set_estado_atual(10);
    }

}