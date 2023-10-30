#include "entidade.hpp"

Entidade::Entidade():
    corpo(sf::Vector2f(100.f,100.f))
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