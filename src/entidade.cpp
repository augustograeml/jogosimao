#include "entidade.hpp"

Entidade::Entidade(sf::Vector2f pos):
    corpo(pos)
{
    
}
Entidade::~Entidade()
{

}
void Entidade::setSkin(const std::string filename)
{
    Textura.loadFromFile(filename);
    corpo.setTexture(&Textura);
}
sf::Vector2f Entidade::getPosicao()
{
    return getCorpo().getPosition();
}