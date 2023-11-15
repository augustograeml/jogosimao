#include "../Observers/observer_menu.hpp"
#include "../Estados/Menus/menu_principal.hpp"

namespace Observers
{

    Observer_Menu::Observer_Menu() : Observer()
    {
        pGer_Eventos->anexar(this);
    }

    Observer_Menu::~Observer_Menu()
    {
        pMenu = nullptr;
    }

    void Observer_Menu::atualizar(sf::Keyboard::Key k)
    {
        if(!pMenu)
            return;
        
        //aqui ele mexe com os ids das paradas

        if (k == sf::Keyboard::Up)
            pMenu->mover_pra_cima();
        if (k == sf::Keyboard::Down)
            pMenu->mover_pra_baixo();
        if (k == sf::Keyboard::Enter)
            pMenu->selecionar();
        if (k == sf::Keyboard::Right ||k == sf::Keyboard::Left)
            pMenu->mover_horizontalmente(1);
        if (k == sf::Keyboard::LControl||k == sf::Keyboard::RControl)
            pMenu->mover_horizontalmente(2);
    }
}