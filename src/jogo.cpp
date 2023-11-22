#include "../jogo.hpp"
#include <iostream>

using namespace std;

Jogo::Jogo():
    pG(Gerenciadores::Gerenciador_Grafico::get_instancia()), pE(Gerenciadores::Gerenciador_Estados::get_instancia()), 
    pEv(Gerenciadores::Gerenciador_Eventos::get_instancia()), obs1(1), obs2(2)
{      
   //setando os ids de cada fase
   Estados::Fases::Fase1* fase1 = new Estados::Fases::Fase1(5);
   Estados::Fases::Fase1* fase12 = new Estados::Fases::Fase1(6);

   Estados::Fases::Fase2* fase2 = new Estados::Fases::Fase2(7);
   Estados::Fases::Fase2* fase22 = new Estados::Fases::Fase2(8);

   menu = new Estados::Menus::Menu(1);
   menu_jogadores = new Estados::Menus::Menu_Jogadores(2);
   menu_fase = new Estados::Menus::Menu_Fase(3);
   menu_fase2 = new Estados::Menus::Menu_Fase2(4);


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
    delete menu_jogadores;
    delete menu_fase;
    delete menu_fase2;
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