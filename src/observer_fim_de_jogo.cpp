#include "../Observers/observer_fim_de_jogo.hpp"
#include "../Estados/Menu/fim_de_jogo.hpp"

namespace Observers
{
    
    Observer_Fim_Jogo::Observer_Fim_Jogo() : Observer()
    {
        pGer_Eventos->anexar(this);

        chaves[sf::Keyboard::A] = "a";
        chaves [sf::Keyboard::B] = "b";
        chaves [sf::Keyboard::C] = "c"; 
        chaves [sf::Keyboard::D] = "d";
        chaves [sf::Keyboard::E] = "e";
        chaves [sf::Keyboard::F] = "f";
        chaves [sf::Keyboard::G] = 'g';
        chaves [sf::Keyboard::H] = "h";
        chaves [sf::Keyboard::I] = "i";
        chaves [sf::Keyboard::J] = "j";
        chaves [sf::Keyboard::K] = "k";
        chaves [sf::Keyboard::L] = "l";
        chaves [sf::Keyboard::M] = "m";
        chaves [sf::Keyboard::N] = "n";
        chaves [sf::Keyboard::O] = "o";
        chaves [sf::Keyboard::P] = "p";
        chaves [sf::Keyboard::Q] = "q";
        chaves [sf::Keyboard::R] = "r";
        chaves [sf::Keyboard::S] = "s";
        chaves [sf::Keyboard::T] = "t";
        chaves [sf::Keyboard::U] = "u";
        chaves [sf::Keyboard::V] = "v";
        chaves [sf::Keyboard::W] = "w";
        chaves [sf::Keyboard::X] = "x";
        chaves [sf::Keyboard::Y] = "y";
        chaves [sf::Keyboard::Z] = "z";
    }

    Observer_Fim_Jogo::~Observer_Fim_Jogo()
    {
        pGer_Eventos = nullptr;
    }

    void Observer_Fim_Jogo::atualizar(sf::Keyboard::Key k)
    {
        //se nao for fim do jogo ele tem que sair da funcao
        if(!pFJ)
            return;

        if(k == sf::Keyboard::Up)
        {
            pFJ->mover_pra_cima();
        }
        /*if(k == sf::Keyboard::Down)
        {
            //pFJ->mover_pra_baixo();
        }*/

        if(k == sf::Keyboard::Enter)
        {
            pFJ->set_nome_final();
            pFJ->selecionar();
        }


    }
}