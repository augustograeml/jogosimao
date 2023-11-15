#include "../Observers/observer_ranking.hpp"
#include "../Estados/Menus/ranking.hpp"

namespace Observers
{
    Observer_Ranking::Observer_Ranking() : Observer()
    {
        pGer_Eventos->anexar(this);
    }

    Observer_Ranking::~Observer_Ranking()
    {
        pRanking = nullptr;
    }

    void Observer_Ranking::atualizar(sf::Keyboard::Key k)
    {
        if (!pRanking)
            return;
            
        if (k == sf::Keyboard::Up)
            pRanking->mover_pra_cima();
        if (k == sf::Keyboard::Down)
            pRanking->mover_pra_baixo();
        if (k == sf::Keyboard::Enter)
            pRanking->selecionar();
    }
}