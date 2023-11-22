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

    void Estado::setID(int num)
    {
        id = num;
    }

    int Estado::getID()
    {
        return id;
    }

}