#include "../Estados/Menu/menu_principal.hpp"


namespace Estados
{
    namespace Menus
    {
        Menu_Principal::Menu_Principal() : Menu(4, 0, "Zombies++"), estagio_atual(1),
        jogador_atual(0), estagio1("Estagio 1"), estagio2("Estagio 2"),
        jogador1("Um jogador"), jogador2("Dois jogadores")
        {
            titulo.set_tamanho(50);
            titulo.set_posicao(sf::Vector2f(50.f, 25.f));
            titulo.set_cor(0);

            estagio1.set_posicao(sf::Vector2f(100.f, 125.f));
            estagio2.set_posicao(sf::Vector2f(100.f, 125.f));

            botoes[0]->set_nome("Continuar");
            botoes[1]->set_nome("Novo Jogo");
            botoes[2]->set_nome("Ranking");
            botoes[3]->set_nome("Sair");

            pObserverMenu = new Observers::Observer_Menu;
            pObserverMenu->set_menu(this);
        }

        Menu_Principal::~Menu_Principal()
        {
            if (pObserverMenu)
            delete pObserverMenu;
        
            pObserverMenu = nullptr;
        }

        void Menu_Principal::selecionar()
        {
            switch(indice)
            {
                case 0:
                    if(estagio_atual == 1)
                    {
                        if(jogador_atual == 0)
                            pGE->set_estado_atual(1);
                        else
                            pGE->set_estado_atual(6);
                    }
                    else
                    {
                        if(estagio_atual == 0)
                            pGE->set_estado_atual(2);
                        else
                            pGE->set_estado_atual(5);
                    }
                    break;

                case 1:
                    if(estagio_atual == 1)
                    {
                        if(jogador_atual == 0)
                            pGE->set_estado_atual(1);
                        else
                            pGE->set_estado_atual(6);
                    }
                    else
                    {
                        if(jogador_atual == 0)
                            pGE->set_estado_atual(2);
                        else
                            pGE->set_estado_atual(5);

                    }
                    break;

                case 2:
                    Estados::Estado::pGE->set_estado_atual(4);
                    break;

                case 3:
                    //gerenciador grafico tem que fechar a janela aqui
                    break;

                default:
                    break;
            }
        }
    }
}