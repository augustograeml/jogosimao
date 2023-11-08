#pragma once
#include <vector>
using namespace std;

class Estado;

/*
Estados:
0 - Menu
1 - Fase 1
2 - Fase 2
*/

class Gerenciador_Estados
{
    private:
        int estadoAtual;
        vector<Estado*> estados;
        static Gerenciador_Estados* instancia;
        Gerenciador_Estados();
    public:
        ~Gerenciador_Estados();

        static Gerenciador_Estados* get_instancia();
        void set_estado_atual(int eA);
        void adicionar_estado(Estado* pE);
        void executar();

};