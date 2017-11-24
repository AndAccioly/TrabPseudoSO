#include <iostream>
#include <fstream>
#include <vector>
#include "Processo.cpp"

using namespace std;

int main(int argc, char *argv[]){


	//faz a leitura do arquivo de processos, criando um vetor
	//envia para o diespachador o vetor com os processos
	//quantum 1 segundo
	//duas filas: uma de prioridade 0 (maxima) com FIFO e uma com prioridade baixa (RR adaptativo). As de usuario tem que ter 3 filas (prioridade 1, 2 e 3)
	//maximo de 1000 processos
	//memoria de 1024 blocos - 64 para tempo real e 960 para usuario
	//nao precisa fazer swap


	vector<Processo*> processos;
	ifstream arqTeste;
	string linha;
	Processo* processo = new Processo();

	processo->setQuantBlocosAlocados(100);


	//processos.push_back(processo);

	cout << processo->getId() << " " << processo->getQuantBlocosAlocados() << "\n";
	arqTeste.open("C:/Users/Andre/Documents/UnB/SO/trab/teste.txt");

	if(arqTeste.is_open()){
		while(getline(arqTeste, linha)){
			cout << linha << "\n";	
		}		
	}

	arqTeste.close();

	return 0;


}