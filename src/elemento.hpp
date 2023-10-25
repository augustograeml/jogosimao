#pragma once

template <class TE> class Elemento
{
    private:
        Elemento<TE>* pProximo;
        TE* item;
    public:
        Elemento();
        ~Elemento();

        void setpProximo(Elemento<TE>* p) {this->pProximo = p;}
        void setItem(TE* i) {this->item = i;}
        Elemento<TE>* getpProximo() {return pProximo;}
        TE* getItem() {return item;}
};

template <class TE>
inline Elemento<TE>::Elemento()
{
    pProximo = nullptr;
    item = nullptr;
}

template <class TE>
inline Elemento<TE>::~Elemento()
{
    pProximo = nullptr;
    item = nullptr;
}