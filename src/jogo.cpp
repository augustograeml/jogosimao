#include "../jogo.hpp"
#include <iostream>

using namespace std;

Jogo::Jogo():
    pG(Gerenciador_Grafico::get_instancia()), pE(Gerenciador_Estados::get_instancia()), 
    pEv(Gerenciador_Eventos::get_instancia()), obs1(1), obs2(2)
{      
   Estados::Fases::Fase1* fase1 = new Estados::Fases::Fase1();
   Executar();  
}
Jogo::~Jogo()
{
    delete pG;
    delete pE;
    delete pEv;
}

void Jogo::Executar()
{    
    while (pG->get_JanelaAberta())
    {
        pG->limpar();
        pEv->executar();
        pE->executar();     //desenha a fase e o jogador 
        pG->mostrar();
    }
}