#include "../Observers/observer.hpp"

namespace Observers
{
    Gerenciadores::Gerenciador_Eventos* Observers::Observer::pGer_Eventos(Gerenciadores::Gerenciador_Eventos::get_instancia());
    Gerenciadores::Gerenciador_Grafico* Observers::Observer::pGer_Grafico(Gerenciadores::Gerenciador_Grafico::get_instancia());
    Gerenciadores::Gerenciador_Estados* Observers::Observer::pGer_Estados(Gerenciadores::Gerenciador_Estados::get_instancia());

    Observers::Observer::Observer()
    {
        pGer_Eventos->anexar(this);
    }

    Observers::Observer::~Observer()
    {
        pGer_Eventos->remover(this);
    }
}