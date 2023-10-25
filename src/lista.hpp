#pragma once
#include "elemento.hpp"

template <class TL> class Lista
{
    private:
        Elemento<TL>* pPrimero;
        Elemento<TL>* pUltimo;
        int tamanho;

    public:
        Lista();
        ~Lista();

        int geTamanho() {return tamanho;}

        TL* getItem(int posicao) 
        {
            Elemento<TL>* auxiliar = pPrimero;
            int i;

            if(posicao == 0)
                return auxiliar->getItem();
            
            for(i = 0; i < posicao; i++)
                auxiliar = auxiliar->getpProximo();
            
            return auxiliar->getItem();
        }

        void incluir(TL* elemento)
        {
            if(pPrimero == nullptr)
            {
                pPrimero = new Elemento<TL>;
                pPrimero->setItem(elemento);
                pUltimo = pPrimero;
            }
            else
            {
                Elemento<TL>* auxiliar = new Elemento<TL>;
                auxiliar->setItem(elemento);
                pUltimo->setpProximo(auxiliar);
                pUltimo =  auxiliar;
            }

            tamanho++;
        }

        void apaga(TL* elemento)
        {
            Elemento<TL>* auxiliar = pPrimero;
            Elemento<TL>* auxiliar_anterior = nullptr;

            while(auxiliar->getItem() != elemento)
            {
                auxiliar_anterior = auxiliar;
                auxiliar = auxiliar->getpProximo();
            }

            if(auxiliar ==  pPrimero)
            {
                pPrimero = auxiliar->getpProximo();
            }
            else if(auxiliar == pUltimo)
            {
                auxiliar_anterior->setpProximo(nullptr);
                pUltimo = auxiliar_anterior;
            }
            else
            {
                auxiliar_anterior->setpProximo(auxiliar->getpProximo());
            }

            delete auxiliar;
            tamanho--;
        }
};

template<class TL>
inline Lista <TL>::Lista()
{
    pPrimero = nullptr;
    pUltimo = nullptr;
    tamanho = 0;
}

template<class TL>
inline Lista <TL>::~Lista()
{
    
}