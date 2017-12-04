#ifndef GERMEMORIA_H
#define GERMEMORIA_H

#include <vector>

using namespace std;

class GerMemoria{

/*
O gerenciador de memória deve garantir que um processo não acesse as regiões de memória de um outro processo.
*/

    private:
        vector<int> memTempoReal;
        vector<int> memUsuario;
        int tamTempoReal;
        int tamUsuario;
        GerMemoria();

    public:

        static GerMemoria& instance(){
            static GerMemoria instance;
            return instance;
        }
        void setTamTempoReal(int tamanho);
        void setTamUsuario(int tamanho);
        int getTamTempoReal();
        int getTamUsuario();
        void addMemTempoReal(int processoId);
        void addMemUsuario(int processoId);
        void remMemTempoReal(int processoId);
        void remMemUsuario(int processoId);

};


#endif // GERMEMORIA
