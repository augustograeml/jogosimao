#pragma once
#include <vector>
using namespace std;

class Estado;

class Gerenciador_Estados
{
    private:
        int estadoAtual;
        vector<Estado*> estados;
        //singleton
        static Gerenciador_Estados* instancia;
        Gerenciador_Estados();
    public:
        ~Gerenciador_Estados();

        static Gerenciador_Estados* get_instancia();
        void set_estado_atual(int eA);
        void adicionar_estado(Estado* pE);
        void executar();

};