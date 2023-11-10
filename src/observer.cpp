#include "../Observers/observer.hpp"

namespace Observers
{
    Gerenciador_Eventos* Observers::Observer::pGer_Eventos(Gerenciador_Eventos::get_instancia());

    Observers::Observer::Observer()
    {
        pGer_Eventos->anexar(this);
    }

    Observers::Observer::~Observer()
    {
        pGer_Eventos->remover(this);
    }
}