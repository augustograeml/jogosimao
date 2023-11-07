#include "observer.hpp"

Gerenciador_Eventos* Observer::pGer_Eventos(Gerenciador_Eventos::get_instancia());


Observer::Observer()
{
    pGer_Eventos->anexar(this);
}

Observer::~Observer()
{
    pGer_Eventos->remover(this);
}