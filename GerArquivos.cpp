#include "GerArquivos.h"
#include <algorithm>
#include <iostream>

GerArquivos::GerArquivos() {

}

void GerArquivos::addArquivo(int processoId, char arquivoId, int tamanhoArquivo) {
    int contador=0;
    int flag = 0;

    /** DA PRA OTIMIZAR ISSO AQUI, TA BEM FEIO **/

    /** VERIFICA SE TEM ESPAÇO NA MEMÓRIA **/
    if(this->tamanhoOcupado + tamanhoArquivo < this->tamanhoMaximo) {
        /** SE A MEMORIA TIVER VAZIA INSERE NA MEMORIA **/
        if (this->arquivos.empty()) {
            this->arquivos.push_back(arquivoId);
            this->indexMap.insert (pair<char,int> (arquivoId, processoId));
            this->tamanhoOcupado += tamanhoArquivo;
        } else {
            /** PROCURA ESPAÇOS VAZIOS NA MEMÓRIA E INSERE CASO POSSÍVEL **/
            for (int i = 0; i < this->arquivos.size() || flag == 0; i++) {
                if (this->arquivos[i] == '0' && this->arquivos[i]==this->arquivos[i+1] && flag == 0) {
                    contador++;
                    if (contador >= tamanhoArquivo) {
                        for (int j=0; j<tamanhoArquivo; j++) this->arquivos[i - contador] = arquivoId;
                        this->indexMap.insert (pair<char,int> (arquivoId, processoId));
                        this->tamanhoOcupado += tamanhoArquivo;
                        flag = 1; //INSERIU O ARQUIVO
                    }
                } else if (this->arquivos[i] == '0' && tamanhoArquivo == 1){
                    this->arquivos[i] = arquivoId;
                    this->indexMap.insert (pair<char,int> (arquivoId, processoId));
                    this->tamanhoOcupado += tamanhoArquivo;
                    flag = 1; //INSERIU O ARQUIVO
                } else contador = 0;
            }
            /** SE NAO FOR POSSIVEL, VERIFICA SE É POSSIVEL INSERIR NO FINAL DA FILA **/
            if (flag==0 && tamanhoArquivo <= this->arquivos.size()) {
                this->arquivos.push_back(arquivoId);
                this->indexMap.insert (pair<char,int> (arquivoId, processoId));
                this->tamanhoOcupado += tamanhoArquivo;
            } else if (flag==0 ){
                //ESPAÇO INSUFICIENTE!!!
            }
        }
    } else {
        //ESPAÇO INSUFICIENTE!!!
    }
}

void GerArquivos::remArquivo(int processoId, char arquivoId) {

    //** TEM QUE VALIDAR SE O PROCESSO É 0 1 2 ou 3, PEGAR O PROCESSO PELO ID **//

    /** SE AQUELE ARQUIVO EXISTIR NA MEMORIA E TIVER ASSOCIADO AO ID DO PROCESSO QUE CRIOU, CONSEGUE DELETAR**/
    if (this->indexMap.count(arquivoId) > 0 && this->indexMap.at(arquivoId) == processoId)
    {
        replace(this->arquivos.begin(), this->arquivos.end(), arquivoId, '0');
        this->tamanhoOcupado -= this->indexMap.count(arquivoId);
        this->indexMap.erase(arquivoId);
    }
}

void GerArquivos::setTamanhoMaximo(int tamanho) {
    this->tamanhoMaximo = tamanho;
}

void GerArquivos::setTamanhoOcupado(int tamanho) {
    this->tamanhoOcupado = tamanho;
}

int GerArquivos::getTamanhoMaximo() {
    return this->tamanhoMaximo;
}

int GerArquivos::getTamanhoOcupado() {
    return this->tamanhoOcupado;
}

void GerArquivos::imprimeArquivos() {
    for (int i=0; i<this->arquivos.size(); i++)
    {
        cout << this->arquivos[i] << ' ';
    }
}
