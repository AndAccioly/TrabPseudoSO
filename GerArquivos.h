#ifndef GerArquivos_H
#define GerArquivos_H

#include "GerProcessos.h"
#include <vector>
#include <map>

using namespace std;

class GerArquivos{

/*
O gerenciador de arquivos deve permitir que os processos possam criar e deletar arquivos, de acordo com o modelo de alocação determinado.
*/

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
