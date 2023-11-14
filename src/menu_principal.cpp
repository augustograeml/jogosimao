#include "../Estados/Menu/menu_principal.hpp"
#define TAMANHO_BOTAO_X 60.f
#define TAMANHO_BOTAO_Y 200.f

namespace Estados
{
    namespace Menu
    {
        Menu_Principal::Menu_Principal() : Menu(sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), "ZOMBIES++", 180), sair(false)
        {
            //titulo.setPosition(sf::Vector2f(tamanho_janela.x / 2.0f)
            //titulo.setColor(sf::Color::Green);
            criar_fundo();
            criar_botoes();
        }

        Menu_Principal::~Menu_Principal()
        {

        }

        void Menu_Principal::criar_fundo()
        {
            
        }

        void Menu_Principal::criar_botoes()
        {
            float posicao_botao_x = tamanho_janela.x / 2.0f - tamanho_botao.x / 2.0f;
            adicionar_botao("Novo Jogo", sf::Vector2f(posicao_botao_x, tamanho_janela.y / 2.0f), sf::Color::White);
            adicionar_botao("Carregar Jogo", sf::Vector2f(posicao_botao_x, tamanho_janela.y / 2.0f + tamanho_botao.y * 1.2f), sf::Color::White);
            adicionar_botao("Colocacao", sf::Vector2f(posicao_botao_x, tamanho_janela.y / 2.0f + tamanho_botao.y * 2.4f), sf::Color::White);
            adicionar_botao("Opcao", sf::Vector2f(posicao_botao_x, tamanho_janela.y / 2.0f + tamanho_botao.y * 3.6f), sf::Color::White);
            adicionar_botao("Sair", sf::Vector2f(posicao_botao_x, tamanho_janela.y / 2.0f + tamanho_botao.y * 4.8f), sf::Color::White);
            it = lista_botao.begin();
            (*it)->set_selecionado(true);
        }

        void Menu_Principal::set_sair(bool s)
        {
            sair = s;
        }

        bool Menu_Principal::get_sair()
        {
            return sair;
        }

        void Menu_Principal::mudar_estado_observador()
        {

        }

        void Menu_Principal::executar()
        {
            posicao_fundo = sf::Vector2f(posicao_fundo.x + 0.05f, posicao_fundo.y);
            //atualiar camera do gerenciador grafico
            //executar no fundo, la ele
            //resetar janela

            desenhar();
            //chamar o desenha elemento do gerenciador grafico
        }
    }
}