#pragma once

#include <iostream>

using namespace std;

class Product
{
private:
    string name;
    double preco;
public:

    Product(string name, double preco) : name(name), preco(preco) {};
    string getName();
    double getPreco();
    void printDetails();
    
};