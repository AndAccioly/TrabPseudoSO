#ifndef GERPROCESSOS_H
#define GERPROCESSOS_H

#include <iostream>
#include <list>
#include "Processo.h"
#include "GerMemoria.h"

using namespace std;

class GerProcessos{
private:
	//se um processo de usuario (1,2,3) acabar o quantum, cai a prioridade (aumenta o numero)
	list<Processo*> prioridade0;
	list<Processo*> prioridade1;
	list<Processo*> prioridade2;
	list<Processo*> prioridade3;



	//processo ocupando a cpu
	Processo* procAtual;
	GerProcessos();
	int tempoQuantum;

public:
	static GerProcessos& instance(){
		static GerProcessos instance;
		return instance;
	}
	vector<int> processosTempoReal;
	bool estaVazio();		//verifica se as listas estao vazias. Se estiverem, retorna true
	void adicionarProcesso(Processo* processo);
	void atualizar(int timer);
	void escalonarProcesso();
	void adicionarProcessoAtual();
	int getPrioridadeProcesso(int id);
};

#endif // GERPROCESSOS_H
