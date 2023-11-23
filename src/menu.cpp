//codigo reaproveitado do Canal Terminal Root

#include "../Estados/Menus/menu.hpp"
#include <iostream>

namespace Estados
{
    namespace Menus
    {
        Gerenciadores::Gerenciador_Grafico* Menu::pGG(Gerenciadores::Gerenciador_Grafico::get_instancia());
        
        Menu::Menu(int id) : Estado(id)
        {
            fonte = new sf::Font();
            imagem = new sf::Texture();
        }

        Menu::~Menu()
        {
            delete fonte;
            delete imagem;
        }

        void Menu::mostrar_menu()
        {
            pGG->limpar();
            pGG->desenharTextura(imagem);
            // laco diferentao ne mano pprt
            for (auto t : textos)
                pGG->get_Janela()->draw(t);
            pGG->mostrar();
        }

        void Menu::executar()
        {
            mostrar_menu();
            loop_evento();
        }

        
        
    }
}