#ifndef GerArquivos_H
#define GerArquivos_H

#include "GerProcessos.h"
#include <vector>
#include <map>

using namespace std;

class GerArquivos{

    private:
        vector<char> arquivos; //BLOCOS
        map<char, int> indexMap;
        int tamanhoMaximo;

        GerArquivos();

    public:
        static GerArquivos &instance(){
            static GerArquivos instance;
            return instance;
        }

        void setTamanhoMaximo(int tamanho);


        int getTamanhoMaximo();


        bool addArquivo(int processoId, char arquivoId, int tamanhoArquivo);
        bool addArquivo(char arquivoId, int posicaoArquivo, int tamanhoArquivo);
        void remArquivo(int processoId, char arquivoId);

        void imprimeArquivos();
};

#endif // GerArquivos
