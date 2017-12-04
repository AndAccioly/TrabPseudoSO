#include "GerArquivos.h"
#include <algorithm>
#include <iostream>

/*
O gerenciador de arquivos deve permitir que os processos possam criar e deletar arquivos, de acordo com o modelo de alocação determinado.
*/

GerArquivos::GerArquivos() {

}

bool GerArquivos::addArquivo(char arquivoId, int posicaoArquivo, int tamanhoArquivo) {

    for (int j=posicaoArquivo; j<tamanhoArquivo+posicaoArquivo; j++) this->arquivos[j]=arquivoId;
    // imprimeArquivos();
    return true;
}

bool GerArquivos::addArquivo(int processoId, char arquivoId, int tamanhoArquivo) {
    int contador=1;
    int flag = 0;
    int i;

    /** DA PRA OTIMIZAR ISSO AQUI, TA BEM FEIO **/
    /** PROCURA ESPAÇOS VAZIOS NA MEMÓRIA E INSERE CASO POSSÍVEL **/

    for (i = 0; i < this->arquivos.size() && flag == 0; i++) {

        // cout << "\n TESTE MACACAO! \n";
        if (this->arquivos[i] == '0' && this->arquivos[i]==this->arquivos[i+1]) {
            contador++;
            // cout << "Contador: " << contador << "\n";
            if (contador >= tamanhoArquivo) {

                for (int j=0; j<tamanhoArquivo; j++) this->arquivos[i - contador + 2 + j] = arquivoId;
                this->indexMap.insert (pair<char,int> (arquivoId, processoId));

                flag = 1; //INSERIU O


                // cout << "Aquivo inserido!";
                // imprimeArquivos();
                // cout << "\n\n\n\n\n";
            }
        } else if (this->arquivos[i] == '0' && tamanhoArquivo == 1){
            this->arquivos[i] = arquivoId;
            this->indexMap.insert (pair<char,int> (arquivoId, processoId));

            flag = 1; //INSERIU O ARQUIVO
        } else {
            contador = 1;
        }
    }


    if (flag == 1) return true;
    return false;


    // imprimeArquivos();
}

void GerArquivos::remArquivo(int processoId, char arquivoId) {

    //** TEM QUE VALIDAR SE O PROCESSO É 0 1 2 ou 3, PEGAR O PROCESSO PELO ID **//
    // int prioridadeProcesso = GerProcessos::instance().getPrioridadeProcesso (processoId);
    /** SE AQUELE ARQUIVO EXISTIR NA MEMORIA E TIVER ASSOCIADO AO ID DO PROCESSO QUE CRIOU, CONSEGUE DELETAR**/

    int prioridade = GerProcessos::instance().getPrioridadeProcesso(processoId);
    // cout << "\nPRIORIDADE DA FUNCAO: " << prioridade << ".\n";
    // cout << "\nPRIORIDADE DO PROCESSO É: " << prioridade << ". ID DO PROCESSO É: " << processoId << ".\n";

    if (prioridade == 0) {
        replace(this->arquivos.begin(), this->arquivos.end(), arquivoId, '0');
        try {
            this->indexMap.erase(arquivoId);
        } catch(exception *e){};
    } else {
        if (this->indexMap.count(arquivoId) > 0 && this->indexMap.at(arquivoId) == processoId)
        {
            replace(this->arquivos.begin(), this->arquivos.end(), arquivoId, '0');

            this->indexMap.erase(arquivoId);
        }

    }
}

void GerArquivos::setTamanhoMaximo(int tamanho) {
    this->arquivos.resize(tamanho);
    this->tamanhoMaximo = tamanho;

    for (int j=0; j<tamanho; j++) this->arquivos[j]='0';
}


int GerArquivos::getTamanhoMaximo() {
    return this->tamanhoMaximo;
}


void GerArquivos::imprimeArquivos() {
    for (int i=0; i<this->arquivos.size(); i++)
    {
        cout << this->arquivos[i] << ' ';
    }
    cout << "\n";
}
