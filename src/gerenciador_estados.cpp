//codigo reaproveitado do Peteco

#include "../Gerenciadores/gerenciador_estados.hpp"
#include "../Estados/estado.hpp"

namespace Gerenciadores
{
    Gerenciador_Estados* Gerenciador_Estados::instancia = nullptr;

    Gerenciador_Estados::Gerenciador_Estados() : estadoAtual(0)
    {
        //colocar o numero de estados que voce possui
        estados.resize(10);
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

    void Gerenciador_Estados::deleta_estados(int i)
    {
        delete estados[i];
    }

    void Gerenciador_Estados::set_fase(int f)
    {
        fase = f;
    }
    
    int Gerenciador_Estados::get_estado_atual()
    {
        return estadoAtual;
    }

    int Gerenciador_Estados::get_fase()
    {
        return fase;
    }

    void Gerenciador_Estados::adicionar_estado(Estados::Estado* pE)
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