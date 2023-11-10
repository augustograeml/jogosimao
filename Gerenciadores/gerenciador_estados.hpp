#pragma once
#include <vector>

using namespace std;

namespace Estados
{
    class Estado;
}

/*
Estados:
0 - Menu
1 - Fase 1
2 - Fase 2
*/

namespace Gerenciadores
{
    class Gerenciador_Estados
    {
        private:
            int estadoAtual;
            vector<Estados::Estado*> estados;
            static Gerenciador_Estados* instancia;
            Gerenciador_Estados();
        public:
            ~Gerenciador_Estados();

            static Gerenciador_Estados* get_instancia();
            void set_estado_atual(int eA);
            void adicionar_estado(Estados::Estado* pE);
            void executar();

    };

}