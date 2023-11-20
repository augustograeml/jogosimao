#include "../jogo.hpp"
#include <iostream>

using namespace std;

Jogo::Jogo():
    pG(Gerenciadores::Gerenciador_Grafico::get_instancia()), pE(Gerenciadores::Gerenciador_Estados::get_instancia()), 
    pEv(Gerenciadores::Gerenciador_Eventos::get_instancia()), obs1(1), obs2(2)
{      
   Estados::Fases::Fase1* fase1 = new Estados::Fases::Fase1();
   Estados::Fases::Fase2* fase2 = new Estados::Fases::Fase2();

   menu = new Estados::Menu::Menu(1);

   //se descomentar vai ficar com epilepsia so nos botoes, acho que ta rodando a msm coisa so q sem salvar em um dos loops, 
   //ent em um loop ta rodando suave e no outro ta ficando somente o padrao q eh automatico da primeira opcao

   //pE->set_estado_atual(1);
   //menu->executar();
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
        pG->limpar();
        pEv->executar();
        pE->executar();     //desenha a fase e o jogador 
        pG->mostrar();
    }
}