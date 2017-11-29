#ifndef GERPROCESSOS_H
#define GERPROCESSOS_H

#include <Vector>
#include <list>

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

	int tempoQuantum;
public:
	GerProcessos();
	bool estaVazio();		//verifica se as listas estao vazias. Se estiverem, retorna true
	void adicionarProcesso(Processo* processo);
	void atualizar(int timer);
	void escalonarProcesso();
	void adicionarProcessoAtual();

};

#endif // GERPROCESSOS_H