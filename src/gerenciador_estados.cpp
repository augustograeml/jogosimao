#include "../Gerenciadores/gerenciador_estados.hpp"
#include "../Estados/estado.hpp"

using namespace Estados;

namespace Gerenciadores
{
    Gerenciador_Estados* Gerenciador_Estados::instancia = nullptr;

    Gerenciador_Estados::Gerenciador_Estados() : estadoAtual(1)
    {
        //colocar o numero de estados que voce possui
        estados.resize(3);
    }

    Gerenciador_Estados::~Gerenciador_Estados()
    {
        int i;
        for(i = 0; i < estados.size(); i++)
            delete estados[i];
    }

    Gerenciador_Estados* Gerenciador_Estados::get_instancia()
    {
        if(!instancia)
            instancia = new Gerenciador_Estados;

        return instancia;
    }

    void Gerenciador_Estados::set_estado_atual(int eA)
    {
        estadoAtual = eA;
    }

    void Gerenciador_Estados::adicionar_estado(Estado* pE)
    {
        if(pE)
        {
            if(!estados.at(pE->getID()))
                estados.at(pE->getID()) = pE;
            else
            {
                delete estados.at(pE->getID());
                estados.at(pE->getID()) = pE;
            }
        }
    }

    void Gerenciador_Estados::executar()
    {
        estados[estadoAtual]->executar();
    }

}