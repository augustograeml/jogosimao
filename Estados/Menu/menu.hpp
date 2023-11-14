#pragma once
#include "../estado.hpp"
#include "Botao/botao.hpp"
#include <list>


namespace Estados
{
    namespace Menu
    {
        class Menu : public Estado
        {
            protected:
                list<Botao::Botao*> lista_botao;
                list<Botao::Botao*>::iterator it;
                sf::Vector2f tamanho_botao;
                sf::Vector2f tamanho_janela;
                sf::Vector2f posicao_fundo;
                sf::Text titulo;
                bool mouse_selecionado;

            public:
                Menu(sf::Vector2f tam_bot, std::string nome_jogo, int tam_fonte);
                virtual ~Menu();
                void atualizar_posicao_fundo();
                void adicionar_botao(std::string nome, sf::Vector2f posicao, sf::Color cor_selecionada);
                void desenhar();
                void selecionar_de_cima();
                void selecionar_de_baixo();
                void evento_mouse(sf::Vector2f pos_mouse);
                bool get_mouse_selecionado();
                virtual void executar();
        };
    }
}