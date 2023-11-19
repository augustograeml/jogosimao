#pragma once
#include <SFML/Graphics.hpp>
class Ente;

#define LARGURA_TELA 1024.0  
#define ALTURA_TELA 1024.0

namespace Gerenciadores
{
    class Gerenciador_Grafico
    {
        private:
            sf::RenderWindow* janela;
            sf::View camera;
            //singleton
            Gerenciador_Grafico();
            static Gerenciador_Grafico* instancia;
        public:
            ~Gerenciador_Grafico();

            void desenharEnte(Ente* pE);
            void desenharTextura(sf::Texture* pT);
            void desenharFundo(sf::RectangleShape* pR);
            const bool get_JanelaAberta() const;
            static Gerenciador_Grafico* get_instancia();
            void mostrar();
            void limpar();
            void fecharJanela();
            void resetarCamera();
            void centralizarCamera(sf::Vector2f p );//Entidades:Personagens:Jogador* pJ1, Entidades:Personagens:Jogador* pJ2 );
            sf::RenderWindow* get_Janela() const;
    };

}