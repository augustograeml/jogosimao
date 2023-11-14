#include "../Estados/Menu/menu.hpp"

namespace Estados
{
    namespace Menu
    {
        Menu::Menu(sf::Vector2f tam_bot, std::string nome, int tamanho_F)
        {

        }

        Menu::~Menu()
        {

        }

        void Menu::atualizar_posicao_fundo()
        {

        }

        void Menu::adicionar_botao(std::string info, sf::Vector2f pos, sf::Color cor_s)
        {

        }

        void Menu::desenhar()
        {
            std::list<Botao::Botao*>::iterator aux;
            for(aux = lista_botao.begin(); aux != lista_botao.end(); aux++)
            {
                Botao::Botao* botao = *aux;
                botao->desenhar();
                botao = nullptr;
            }
        }

        void Menu::selecionar_de_cima()
        {

        }

        void Menu::selecionar_de_baixo()
        {

        }

        void Menu::evento_mouse(sf::Vector2f pos_MO)
        {

        }

        bool Menu::get_mouse_selecionado()
        {
            return mouse_selecionado;
        }

        void Menu::executar()
        {

        }
    }
}