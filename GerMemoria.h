#ifndef GERMEMORIA_H
#define GERMEMORIA_H

#include <vector>

using namespace std;

class GerMemoria{

    private:
        vector<int> memTempoReal;
        vector<int> memUsuario;
        int tamTempoReal;
        int tamUsuario;
        GerMemoria();

    public:
        // static GerMemoria * instance() {
        //     if (!gerMem)
        //     {
        //         gerMem = new GerMemoria;
        //         gerMem->setTamTempoReal(64);
        //         gerMem->setTamUsuario(960);
        //     }
        //     return gerMem;
        // };
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
