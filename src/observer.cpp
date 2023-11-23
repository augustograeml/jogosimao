//codigo reaproveitado do Peteco

#include "../Observers/observer.hpp"

namespace Observers
{
    Gerenciadores::Gerenciador_Eventos* Observers::Observer::pGer_Eventos(Gerenciadores::Gerenciador_Eventos::get_instancia());
    Gerenciadores::Gerenciador_Estados* Observers::Observer::pGer_Estados(Gerenciadores::Gerenciador_Estados::get_instancia());

    Observer::Observer()
    {
        pGer_Eventos->anexar(this);
    }

    Observer::~Observer()
    {
        pGer_Eventos->remover(this);
    }

    void Observer::mudar_estado_ativar()
    {
        ativar = !ativar;
    }

    const bool Observer::get_ativar() const
    {
        return ativar;
    }

    void Observer::remover_observador()
    {

    }


}