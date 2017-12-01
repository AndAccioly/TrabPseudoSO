#ifndef GerArquivos_H
#define GerArquivos_H

#include <vector>
#include <map>

using namespace std;

class GerArquivos{

    private:
        vector<char> arquivos;
        map<char, int> indexMap;
        int tamanhoMaximo;
        int tamanhoOcupado;
        GerArquivos();

    public:
        static GerArquivos &instance(){
            static GerArquivos instance;
            return instance;
        }

        void setTamanhoMaximo(int tamanho);
        void setTamanhoOcupado(int tamanho);

        int getTamanhoMaximo();
        int getTamanhoOcupado();


        void addArquivo(int processoId, char arquivoId, int tamanhoArquivo);
        void remArquivo(int processoId, char arquivoId);

        void imprimeArquivos();
};

#endif // GerArquivos
