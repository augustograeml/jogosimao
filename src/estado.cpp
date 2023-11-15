#include "../Estados/estado.hpp"

namespace Estados
{
    Gerenciadores::Gerenciador_Estados* Estado::pGE(Gerenciadores::Gerenciador_Estados::get_instancia());

    Estado::Estado(int i) :  id(i)
    {
        pGE->adicionar_estado(this);
    }

    Estado::~Estado()
    {

    }

    int Estado::getID()
    {
        return id;
    }

}