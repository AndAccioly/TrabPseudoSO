#include "GerProcessos.hpp"

#include <iostream>

#define TAMANHO_MAXIMO 1000
#define QUANTUM 100



GerProcessos::GerProcessos(){
	tempoQuantum = 0;
}

bool GerProcessos::estaVazio(){
	if(prioridade0.size() == 0 && prioridade1.size() == 0 && prioridade2.size() == 0 && prioridade3.size() == 0){
		return false;
	}else{
		return true;
	}
}

//atualiza os processos conforme o tempo total de execucao
void GerProcessos::atualizar(int tempoTotal){

	tempoQuantum = tempoQuantum + 1;
	if(tempoQuantum == QUANTUM){
		tempoQuantum = 0;
	}


}

void GerProcessos::adicionarProcesso(Processo* processo){
	
	cout << "Processo " << processo->getId() << " com prioridade " << processo->getPrioridade() << "\n";
	if(processo->getPrioridade() == 0){
		cout << "Adicionando a fila de prioridade 0\n";
		prioridade1.push_back(processo);
	}else if(processo->getPrioridade() == 1){
		cout << "Adicionando a fila de prioridade 1\n";
		prioridade1.push_back(processo);
	}else if(processo->getPrioridade() == 2){
		cout << "Adicionando a fila de prioridade 2\n";
		prioridade2.push_back(processo);
	}else if(processo->getPrioridade() >= 3){
		cout << "Adicionando a fila de prioridade 3\n";
		prioridade3.push_back(processo);
	} 
}