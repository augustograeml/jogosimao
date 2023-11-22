//codigo reaproveitado do peteco

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
1 - Fase 1, um jogador
2 - Fase 1, dois jogadores
3 - Fase 2, um jogador
4 - Fase 2, dois jogadores
5 - ranking
6 - Sair
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
            int get_estado_atual();
            void adicionar_estado(Estados::Estado* pE);
            void executar();

    };

}