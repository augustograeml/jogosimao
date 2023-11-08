#pragma once
#include "fase.hpp"
#define ARQUIVO_CENARIO_1 "src/cenario1.txt"

class Fase1 : public Fase
{
    private:
        sf::Texture* imagem_fundo;
        Sprite sprite;
    public:
        Fase1();
        ~Fase1();
        void executar();
        void mover();
        void atualizar();
};