#include "../Estados/estado.hpp"

using namespace Estados;

Gerenciador_Estados* Estado::pGE(Gerenciador_Estados::get_instancia());

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