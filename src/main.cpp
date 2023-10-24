#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Mario x Luigi");
    sf::RectangleShape shape(sf::Vector2f(100.f,100.f));
    sf::RectangleShape shape2(sf::Vector2f(100.f,100.f));
    sf::Texture texturaPersonagem;
    sf::Texture texturaPersonagem2;
    texturaPersonagem.loadFromFile("imagem/mario.png");
    texturaPersonagem2.loadFromFile("imagem/luigiDireita.png");
    shape.setTexture(&texturaPersonagem);
    shape2.setTexture(&texturaPersonagem2);

    return 0;
}