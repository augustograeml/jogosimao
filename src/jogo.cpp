
#include "../jogo.hpp"
#include <iostream>

using namespace std;

Jogo::Jogo() : pG(Gerenciadores::Gerenciador_Grafico::get_instancia()), pE(Gerenciadores::Gerenciador_Estados::get_instancia()),
               pEv(Gerenciadores::Gerenciador_Eventos::get_instancia()), obs1(1), obs2(2)
{
    menu_principal = new Estados::Menus::Menu_Principal(0);
    menu_jogadores = new Estados::Menus::Menu_Jogadores(1);
    menu_fase = new Estados::Menus::Menu_Fase(2, false);
    menu_fase = new Estados::Menus::Menu_Fase(3, true);
    ranking = new Estados::Menus::Ranking(4);
    pause = new Estados::Menus::Pause(5);

    Estados::Fases::Fase1 *fase1 = new Estados::Fases::Fase1(6, false);
    Estados::Fases::Fase1 *fase12 = new Estados::Fases::Fase1(7, false);

    Estados::Fases::Fase2 *fase2 = new Estados::Fases::Fase2(8, false);
    Estados::Fases::Fase2 *fase22 = new Estados::Fases::Fase2(9, false);

    Executar();
}
Jogo::~Jogo()
{
    delete pG;
    delete pE;
    delete pEv;
    delete menu_principal;
    delete menu_jogadores;
    delete menu_fase;
}

void Jogo::Executar()
{
    while (pG->get_JanelaAberta())
    {
        pG->limpar();
        pEv->executar();
        pE->executar(); // desenha a fase e o jogador
        if(pE->get_estado_atual() > 5)
            pG->mostrar();
    }
}

void Jogo::reseta_fase()
{
    //pE->
}