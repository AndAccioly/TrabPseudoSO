#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>

#include "Dispatcher.h"
#include "GerProcessos.h"
#include "Processo.h"
#include "GerMemoria.h"



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
	vector<string> operacoes;
	vector<int> processosTempoReal;

	ifstream arqProcessos;
	ifstream arqOperacoes;

	string linha;
	int id = 0;
	int offset = 0;

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


	//criacao do vetor de processos: iniciar um processo por linha e adicionar no vetor de processos
	while(getline(arqProcessos, linha)){
		istringstream ss(linha);
		char virgula;
		int tempoInicio, prioridade, tempoProcessamento, memoriaBlocos, impressoraNum, driverNum;
   		int pediuScanner, pediuModem;
   		ss >> tempoInicio >> virgula;
   		ss >> prioridade >> virgula;
   		ss >> tempoProcessamento >> virgula;
   		ss >> memoriaBlocos >> virgula;
   		ss >> impressoraNum >> virgula;
   		ss >> pediuScanner >> virgula;
   		ss >> pediuModem >> virgula;
   		ss >> driverNum >> virgula;

		id += 1;

		if (prioridade == 0) {
			processosTempoReal.push_back(id);
		}

		cout << "\n*************\nSCANNER\n***********\n" << pediuScanner;


   		Processo* processo = new Processo(id, prioridade, offset, memoriaBlocos, tempoInicio,
   			tempoProcessamento, impressoraNum, pediuScanner, driverNum, pediuModem);
   		processos.push_back(processo);
   		processo->imprimeProcesso();



   		offset += memoriaBlocos;
	}

	//criacao do vetor de operacoes de arquivos
	while(getline(arqOperacoes, linha)){
		operacoes.push_back(linha);
	}


	//executar e processar o vetor de processos
	Dispatcher dispatcher(processos, operacoes, processosTempoReal);
	dispatcher.run();

	arqProcessos.close();
	arqOperacoes.close();


	return 0;


}
