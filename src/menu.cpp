#include "../Estados/Menus/menu.hpp"

namespace Estados
{
    namespace Menus
    {
        Menu::Menu(int n_botoes, int id, std::string s) : /*Ente(sf::Vector2f(80.f, 80.f)),*/ Estado(id), MAX_BOTOES(n_botoes),
        botoes(), indice(0), titulo(s)
        {
            for(int i = 0; i < MAX_BOTOES; i++)
            {
                botoes.push_back(new Botao(sf::Vector2f(LARGURA_TELA/2, (i+2)* (20 + TAMANHO_BOTAO_Y))));
            }
            botoes[0]->muda_cor();

            corpo.setSize(sf::Vector2f(800.f, 600.f));
            //aqui ele seta a textura e faz umas paradinhas            
        }

        Menu::~Menu()
        {
            for(int i = 0; i < MAX_BOTOES; i++)
            {
                delete botoes[i];
            }
        }

        void Menu::desenhar()
        {
            for(int i = 0; i < MAX_BOTOES; i++)
            {
                botoes[i]->desenhar();
            }
        }

        void Menu::mover_pra_cima()
        {
            if(indice < MAX_BOTOES - 1)
            {
                botoes[indice]->muda_cor();
                indice--;
                botoes[indice]->muda_cor();
            }
        }

        void Menu::mover_pra_baixo()
        {
            if(indice < MAX_BOTOES - 1)
            {
                botoes[indice]->muda_cor();
                indice++;
                botoes[indice]->muda_cor();
            }
        }

        void Menu::executar()
        {
            desenhar();
        }

        void Menu::mudar_nome(std::string n)
        {
            titulo.set_nome(n);
        }
    }
}