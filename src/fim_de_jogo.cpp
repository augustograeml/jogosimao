#include "../Estados/Menu/fim_de_jogo.hpp"

namespace Estados
{
    namespace Menus
    {
        Fim_de_Jogo::Fim_de_Jogo(Ranking* rk) : Menu(2, 3, "Voce Perdeu Boboca"),
        instrucoes("Aperte Tab e escreva o seu nome"), ranking(rk),
        str_pontos(" - pontos:"), botoes_ativos(false), nome_final(false), nomes_ativo(false)
        {
            instrucoes.set_tamanho(20);
            //tamanho usado abaixo eh oq o mano usou no dele, nao necessariamente significa qe vais e adequar ao nosso
            instrucoes.set_posicao(sf::Vector2f(100.f, 180.f));
            titulo.set_tamanho(65);
            titulo.set_posicao(sf::Vector2f(120.f, 80.f));
            nome_string = "";
            //mexer no observer
        }

        Fim_de_Jogo::~Fim_de_Jogo()
        {
            //mexer com o gerenciador de observer do menu
        }

        void Fim_de_Jogo::desenhar()
        {
            //pGG->
        }
    }
}