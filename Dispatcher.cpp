#include "Dispatcher.h"
#define ENCERRANDO_EXECUCAO "Encerrando execucao."

Dispatcher::Dispatcher(vector<Processo*> processosN, vector<string> operacoesN){
	processos = processosN;
	operacoes = operacoesN;
}


//timer é um numero inteiro que representa o tempo de sistema. Vai aumentando de um em um.
void Dispatcher::run(){
	GerProcessos *gerProc = new GerProcessos();

	cout << "\n...................EXECUTANDO PROCESSOS...................\n";
	int timer = 0;

	while( (processos.size() > 0) || (!gerProc->estaVazio()) ){
		if(timer > 100){
			exit(0);
		}
		cout << "Ciclo " << timer << "\n";
		//verifica dentre os processos se algum deles esta na vez de ser executado. Se estiver, manda para o gerProc
		for(int i = 0; i < processos.size(); i++){
			if(processos.at(i)->getTempoInicio() == timer){
				cout << "Processo " << processos.at(i)->getId() << " vai ser adicionado\n";
				gerProc->adicionarProcesso(processos.at(i));
				processos.erase(processos.begin() + i);
			}
		}


		gerProc->atualizar(timer);
		timer = timer + 1;
	}

	cout << ENCERRANDO_EXECUCAO << "\n";
}
