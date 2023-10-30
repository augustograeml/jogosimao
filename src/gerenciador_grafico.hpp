#pragma once
#include <SFML/Graphics.hpp>
#include "entidade.hpp"

#define LARGURA_TELA 800.0  
#define ALTURA_TELA 600.0

class Gerenciador_Grafico
{
    private:
        sf::RenderWindow* janela;
        sf::View camera;
        Gerenciador_Grafico();
        static Gerenciador_Grafico* instancia;
    public:
        ~Gerenciador_Grafico();

        void desenharEntidade(Entidade* pE);
        // Propaganda:
        void desenharTextura(sf::Texture* pT);
        const bool get_JanelaAberta() const;
        static Gerenciador_Grafico* get_instancia();
        void mostrar();
        void limpar();
        void fecharJanela();
        void resetarCamera();
        void centralizarCamera(sf::Vector2f p);
        sf::RenderWindow* get_Janela() const;
};
