#include "../Estados/Menu/Botao/botao.hpp"

namespace Estados
{
    namespace Menu
    {
        namespace Botao
        {     
            Botao::Botao(std::string informacao, sf::Vector2f pos, sf::Vector2f tam, sf::Color cor_sel)
            {

            }

            Botao::~Botao()
            {

            }

            void Botao::set_selecionado(bool sel)
            {
                selecionado = sel;
            }

            bool Botao::get_selecionado()
            {
                return selecionado;
            }

            void Botao::atualizar_posicao(sf::Vector2f pos)
            {

            }

            sf::Vector2f Botao::get_posicao()
            {
                return caixa_de_texto.getPosition();
            }

            void Botao::atualizar_texto()
            {
                float dt = relogio.getElapsedTime().asSeconds();
                relogio.restart();
                tempo += dt;
                if(selecionado)
                {
                    if(tempo > tempo_trocar_cor)
                    {
                        //if(texto.)
                    }
                }
            }

            void Botao::desenhar()
            {
                atualizar_texto();
                //gerenciador grafico desenha o texto
            }
        }
    }
}