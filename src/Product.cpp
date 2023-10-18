#include "Product.hpp"
#include <iostream>

using namespace std;

string Product::getName()
{
    return this->name;
}

double Product::getPreco()
{
    return this->preco;
}

void Product::printDetails()
{
    cout << "Nome: " << this->name << " Preco: " << this->preco << '\n';
}