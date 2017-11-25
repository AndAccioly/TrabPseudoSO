#include <iostream>
#include <fstream>
#include <vector>
#include "Processo.cpp"
#include <cstdlib>
#include "Dispatcher.cpp"
#include <sstream>

using namespace std;

int main(int argc, char *argv[]){

	//./a processos.txt teste.txt

	//faz a leitura do arquivo de processos, criando um vetor
	//envia para o diespachador o vetor com os processos
	//quantum 1 segundo
	//duas filas: uma de prioridade 0 (maxima) com FIFO e uma com prioridade baixa (RR adaptativo). As de usuario tem que ter 3 filas (prioridade 1, 2 e 3)
	//maximo de 1000 processos
	//memoria de 1024 blocos - 64 para tempo real e 960 para usuario
	//nao precisa fazer swap

	//dois arquivos: o primeiro contem as informacoes do processo a serem criados e ferenciados pelo pseudo SO, o segundo traz as descricoes das operacoes
		//no primeiro, cada linha significa um processo diferente. Campos:
			//<tempo de inicialização>, <prioridade>, <tempo de processador>, <blocos em memória>, <númerocódigoda impressora requisitada>, 
			//<requisição do scanner>, <requisição do modem>, <númerocódigodo disco>
		//no segundo, haverá a quantidade de 

	vector<Processo*> processos;

	ifstream arqProcessos;
	ifstream arqOperacoes;

	string linha;
	

	//inicizalizaçao de arquivos de entrada
	if(argc != 3 ){
		cout << "Numero de arquivos passados incorreto.\n FECHANDO O PROGRAMA;";
		exit(0);
	}

	arqProcessos.open(argv[1]);
	arqOperacoes.open(argv[2]);

	if(!arqProcessos.is_open() || !arqOperacoes.is_open()){
		cout << "Um dos arquivos não foi aberto corretamente. Verifique o caminho do arquivo.\n";
		exit(0);
	}
	

	//inicializacao da fila de processos: iniciar um processo por linha e adicionar no vetor de processos
	
	while(getline(arqProcessos, linha)){
		istringstream ss(linha);
		char virgula;
		int tempoInicio, prioridade, tempoProcessamento, memoriaBlocos, impressoraNum, driverNum;
   		bool pediuScanner, pediuModem;
   		ss >> tempoInicio >> virgula;
   		ss >> prioridade >> virgula;
   		ss >> tempoProcessamento >> virgula;
   		ss >> memoriaBlocos >> virgula;
   		ss >> impressoraNum >> virgula;
   		ss >> pediuScanner >> virgula;
   		ss >> pediuModem >> virgula;
   		ss >> driverNum >> virgula;

   		Processo* processo = new Processo(0, prioridade, 0, memoriaBlocos, tempoInicio, tempoProcessamento, impressoraNum, pediuScanner, driverNum, pediuModem);


   		cout << linha << "\n";	
   		
   		processo->imprimeProcesso();		
	}		
	

	//executar e processar o vetor de processos
	Dispatcher dispatcher(processos);
	dispatcher.run();
	arqProcessos.close();
	arqOperacoes.close();


	return 0;


}