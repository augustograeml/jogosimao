#include "../jogo.hpp"
#include <iostream>

using namespace std;

Jogo::Jogo():
    pG(Gerenciadores::Gerenciador_Grafico::get_instancia()), pE(Gerenciadores::Gerenciador_Estados::get_instancia()), 
    pEv(Gerenciadores::Gerenciador_Eventos::get_instancia()), obs1(1), obs2(2)
{      
   Estados::Fases::Fase1* fase1 = new Estados::Fases::Fase1();
   Estados::Fases::Fase2* fase2 = new Estados::Fases::Fase2();

   menu = new Estados::Menu::Menu();
   pE->set_estado_atual(1);
   Executar();  
}
Jogo::~Jogo()
{
    delete pG;
    delete pE;
    delete pEv;
    delete menu;
}

void Jogo::Executar()
{    
    while (pG->get_JanelaAberta())
    {
        menu->executar();
        pG->limpar();
        pEv->executar();
        pE->executar();     //desenha a fase e o jogador 
        pG->mostrar();
    }
}