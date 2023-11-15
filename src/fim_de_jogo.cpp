#include "../Estados/Menus/fim_de_jogo.hpp"

namespace Estados
{
    namespace Menus
    {
        //depois colocar uma mensagem normal, tipo: Fim de Jogo (algo do tipo)
        Fim_de_Jogo::Fim_de_Jogo(Ranking* rk) : Menu(2, 3, "Voce Perdeu Boboca"),
        instrucoes("Aperte Tab e escreva o seu nome"), ranking(rk),
        str_pontos(" - pontos:"), botoes_ativos(false), nome_final(false), nomes_ativo(false)
        {
            instrucoes.set_tamanho(20);
            //tamanho usado abaixo eh oq o mano usou no dele, nao necessariamente significa qe vais e adequar ao nosso
            instrucoes.set_posicao(sf::Vector2f(100.f, 180.f));
            titulo.set_tamanho(65);
            titulo.set_posicao(sf::Vector2f(120.f, 80.f));
            titulo.set_cor(0);
            nome_string = "";

            pFJObserver = new Observers::Observer_Fim_Jogo;
            pFJObserver->set_menu(this);
        }

        Fim_de_Jogo::~Fim_de_Jogo()
        {
            if (pFJObserver)
                delete pFJObserver;
            
            pFJObserver = nullptr;
        }

        void Fim_de_Jogo::desenhar()
        {
            
        }

        void Fim_de_Jogo::adicionar_nome(std::string n)
        {
            if(nomes_ativo)
                nome_string.append(n);
        }

        void Fim_de_Jogo::set_nome_final()
        {
            if(nome_final)
                return;
            if(nome_string.size() == 0)
                return;
            
            //dar o numero de pontos aqui em baixo
            //str_pontos = std::to_string()
            //ranking->adicionar_novo_ranking(get_pontos(), nome_string)

            nome.set_posicao(sf::Vector2f(60.f, 450.f));
            botoes_ativos = false;
            nome_final = false;
        }

        std::string Fim_de_Jogo::get_nome_string()
        {
            return nome_string;
        }

        void Fim_de_Jogo::set_pontos(int p)
        {
            str_pontos.append(std::to_string(p));
        }

        void Fim_de_Jogo::nome_ativo()
        {
            if(!nomes_ativo)
                nomes_ativo = true;
        }

        void Fim_de_Jogo::desenhar_botao()
        {
            botoes[0]->set_nome("Menu");
            botoes[1]->set_nome("Sair");

            for(int i = 0; i < 2; i++)
            {
                botoes[i]->desenhar();
            }
        }

        void Fim_de_Jogo::selecionar()
        {
            if(!botoes_ativos)
            {
                botoes_ativos = true;
                return;
            }

            if(botoes_ativos)
            {
                switch(indice)
                {
                    case 0:
                        botoes_ativos = false;
                        Estados::Estado::pGE->set_estado_atual(0);
                        break;

                    case 1:
                        //fechar janela pelo ponteiro do gerenciador grafico aqui
                        break;
                    
                    default:
                        break;
                }
            }
        }

        void Fim_de_Jogo::resetar()
        {
            botoes_ativos = false;
            nome_final = false;
            nomes_ativo = false;
            titulo.set_nome("Voce Perdeu Boboca");
            nome.set_nome(" ");
            nome_string = "";
        }

        void Fim_de_Jogo::salvar()
        {
            
        }
    }
}