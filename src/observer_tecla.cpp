#include "../Observers/observer_tecla.hpp"

using namespace Observers;

Observer_Tecla::Observer_Tecla(int n) : Observer(), numero(n)
{

}

Observer_Tecla::~Observer_Tecla()
{

}

void Observer_Tecla::atualizar(Keyboard::Key k)
{

}