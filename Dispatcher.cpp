#include "Dispatcher.h"
#define ENCERRANDO_EXECUCAO "Encerrando execucao."

Dispatcher::Dispatcher(vector<Processo*> processosN, vector<string> operacoesN){
	processos = processosN;
	operacoes = operacoesN;
}


//timer é um numero inteiro que representa o tempo de sistema. Vai aumentando de um em um.
void Dispatcher::run(){
	GerProcessos *gerProc = new GerProcessos();
	// GerMemoria *gerMem = new GerMemoria();

	cout << "\n...................EXECUTANDO PROCESSOS...................\n";
	int timer = 0;

	while( (processos.size() > 0) || (!gerProc->estaVazio()) ){

		cout << "Ciclo " << timer << "\n";
		//verifica dentre os processos se algum deles esta na vez de ser executado. Se estiver, manda para o gerProc
		for(int i = 0; i < processos.size(); i++){
			if(processos.at(i)->getTempoInicio() == timer){

				cout << "Processo " << processos.at(i)->getId() << " vai ser adicionado\n";

				if(processos.at(i)->getPrioridade() == 0) {
					if(processos.at(i)->getQuantBlocosAlocados() < GerMemoria::instance().getTamTempoReal()) {
						GerMemoria::instance().addMemTempoReal(processos.at(i)->getId());
						GerMemoria::instance().setTamTempoReal(GerMemoria::instance().getTamTempoReal() - processos.at(i)->getQuantBlocosAlocados());
						gerProc->adicionarProcesso(processos.at(i));
					} else {
						cout << "Nao ha espaco para alocar processo!\n";
					}
				}else{
					if(processos.at(i)->getQuantBlocosAlocados() < GerMemoria::instance().getTamUsuario()) {
						GerMemoria::instance().addMemUsuario(processos.at(i)->getId());
						GerMemoria::instance().setTamUsuario(GerMemoria::instance().getTamUsuario() - processos.at(i)->getQuantBlocosAlocados());
						gerProc->adicionarProcesso(processos.at(i));
					} else {
						cout << "Nao ha espaco para alocar o processo!\n";
					}
				}

				processos.erase(processos.begin() + i);
			}
		}

		gerProc->atualizar(timer);
		timer = timer + 1;
	}

	cout << ENCERRANDO_EXECUCAO << "\n";
}
