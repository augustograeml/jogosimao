#include "../Observers/observer_pause.hpp"
#include "../Estados/Menus/pause.hpp"

namespace Observers
{
    Observer_Pause::Observer_Pause() : Observer(), pMenu(nullptr)
    {
        pGer_Eventos->anexar(this);
    }

    Observer_Pause::~Observer_Pause()
    {
        pMenu = nullptr;
    }

    void Observer_Pause::set_menu(Estados::Menus::Pause* pM)
    {
        pMenu = pM;
    }

    void Observer_Pause::atualizar(sf::Keyboard::Key k)
    {
        if(!pMenu)
            return;
        if(pGer_Estados->get_estado_atual() != 5)
            return;

        cout << "estado atual menu jogadores: " << pGer_Estados->get_estado_atual() << endl;
        
        /*if(k == sf::Keyboard::Down || k == sf::Keyboard::Right)
        {
            //fazer o menu ir pra opcao de baixo
            
            pMenu->baixo(3);
        }

        else if(k == sf::Keyboard::Up || k == sf::Keyboard::Left)
        {
            //fazer o menu ir pra opcao de cima
            pMenu->cima();
        }
        else if(k == sf::Keyboard::Enter)
        {
            //fazer o menu selecioar a opcao
            pMenu->selecionar();
        }*/
    }
}