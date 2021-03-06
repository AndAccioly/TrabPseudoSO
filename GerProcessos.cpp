#include "GerProcessos.h"

#define TAMANHO_MAXIMO 1000
#define QUANTUM 10

/*
O gerenciador de processos deve ser capaz de agrupar os processos em quatro níveis de prioridades.
*/

GerProcessos::GerProcessos(){
	tempoQuantum = 0;
	procAtual = NULL;
}

bool GerProcessos::estaVazio(){
	if(prioridade0.size() == 0 && prioridade1.size() == 0 && prioridade2.size() == 0 && prioridade3.size() == 0 && procAtual == NULL){
		return true;
	}else{
		return false;
	}
}

//atualiza os processos conforme o tempo total de execucao
void GerProcessos::atualizar(int tempoTotal){

	// GerMemoria *gerMem = new GerMemoria();

	if(estaVazio()){
		return;
	}
	//cout  << prioridade0.size() << prioridade1.size() << prioridade2.size() << prioridade3.size() <<" NAO ESTA VAZIO\n";

	tempoQuantum = tempoQuantum + 1;

	if(procAtual == NULL){
		escalonarProcesso();
	}else{
		//processos FIFO
		if(procAtual->getPrioridade() == 0){
			int t = procAtual->getTempoProcessamento() - 1;
			if(t < 0){
				//processo terminou a execucao: retira da cpu e escalona um novo
				cout << "P" << procAtual->getId() << " return SIGINT\n";
				GerMemoria::instance().remMemTempoReal(procAtual->getId());
				GerMemoria::instance().setTamTempoReal(GerMemoria::instance().getTamTempoReal() + procAtual->getQuantBlocosAlocados());
				escalonarProcesso();
			}else{
				procAtual->setTempoProcessamento(t);
			}

			//processos ROUND-ROBIN ADAPTATIVO
		}else{
			//cout << "QUANTUM " << tempoQuantum << " " << QUANTUM << "\n";
			int t = procAtual->getTempoProcessamento();
			int p = procAtual->getPrioridade();

			if(t <= tempoQuantum){
				cout << "P" << procAtual->getId() << " return SIGINT\n";

				if (procAtual->getModem() == 1) GerRecursos::instance().liberaDispositivo("Modem");
				if (procAtual->getScanner() == 1) GerRecursos::instance().liberaDispositivo("Scanner");
				if (procAtual->getImpressora() == 1) GerRecursos::instance().liberaDispositivo("Printer1");
				if (procAtual->getImpressora() == 2) GerRecursos::instance().liberaDispositivo("Printer2");
				if (procAtual->getDrivers() == 1) GerRecursos::instance().liberaDispositivo("Driver1");
				if (procAtual->getDrivers() == 2) GerRecursos::instance().liberaDispositivo("Driver2");

				GerMemoria::instance().remMemUsuario(procAtual->getId());
				GerMemoria::instance().setTamUsuario(GerMemoria::instance().getTamUsuario() + procAtual->getQuantBlocosAlocados());

				tempoQuantum = 0;
				escalonarProcesso();
			}

			if(tempoQuantum == QUANTUM){
				cout << "Trocando processo " << procAtual->getId() << "\n";
				procAtual->setTempoProcessamento(t - QUANTUM);
				if(p < 3){
					cout << "Atualizando prioridade de " << p << " para " << p+1<< "\n";
					procAtual->setPrioridade(p+1);
				}
				adicionarProcesso(procAtual);
				escalonarProcesso();
				tempoQuantum = 0;
			}
		}
	}
}

void GerProcessos::escalonarProcesso(){
	//cout << "ESCALONANDO" << "\n";
	//cout << prioridade0.size() << " " << prioridade1.size() << " " << prioridade2.size() << " " << prioridade3.size() << "\n";

	if(prioridade0.size() > 0){
		procAtual = prioridade0.front();
		prioridade0.pop_front();
		//cout << "Escalonando processo " << procAtual->getId() << " da fila 0 " << "\n";
	}else if (prioridade1.size() > 0){
		procAtual = prioridade1.front();
		prioridade1.pop_front();
		//cout << "Escalonando processo " << procAtual->getId() << " da fila 1 " << "\n";
	}else if (prioridade2.size() > 0){
		procAtual = prioridade2.front();
		prioridade2.pop_front();
		//cout << "Escalonando processo " << procAtual->getId() << " da fila 2 " << "\n";
	}else if (prioridade3.size() > 0){
		procAtual = prioridade3.front();
		prioridade3.pop_front();
		//cout << "Escalonando processo " << procAtual->getId() << " da fila 3 " << "\n";
	}else{
		//cout << "todas as filas vazias\n";
		procAtual = NULL;
	}

	if (procAtual != NULL && procAtual->getPrioridade() > 0) {
		if (procAtual->getModem() == 1) GerRecursos::instance().utilizaDispositivo("Modem");
		if (procAtual->getScanner() == 1) GerRecursos::instance().utilizaDispositivo("Scanner");
		if (procAtual->getImpressora() == 1) GerRecursos::instance().utilizaDispositivo("Printer1");
		if (procAtual->getImpressora() == 2) GerRecursos::instance().utilizaDispositivo("Printer2");
		if (procAtual->getDrivers() == 1) GerRecursos::instance().utilizaDispositivo("Driver1");
		if (procAtual->getDrivers() == 2) GerRecursos::instance().utilizaDispositivo("Driver2");
	}

	tempoQuantum = 0;
}

int GerProcessos::adicionarProcesso(Processo* processo){
	//cout << "Processo " << processo->getId() << " com prioridade " << processo->getPrioridade() << "\n";
	if(prioridade0.size() + prioridade1.size() + prioridade2.size() + prioridade3.size() > TAMANHO_MAXIMO){
		cout << "FILA DE PROCESSOS CHEIA\n";
		return 1;
	}
	if(processo->getPrioridade() == 0){
		//cout << "Adicionando a fila de prioridade 0\n";
		prioridade0.push_back(processo);
	}else if(processo->getPrioridade() == 1){
		//cout << "Adicionando a fila de prioridade 1\n";
		prioridade1.push_back(processo);
	}else if(processo->getPrioridade() == 2){
		//cout << "Adicionando a fila de prioridade 2\n";
		prioridade2.push_back(processo);
	}else if(processo->getPrioridade() >= 3){
		//cout << "Adicionando a fila de prioridade 3\n";
		prioridade3.push_back(processo);
	}
	return 0;

}

int GerProcessos::getPrioridadeProcesso(int id){
	for (int i = 0; i < processosTempoReal.size(); i++) if (processosTempoReal[i] == id) return 0;
	return 404;
}
