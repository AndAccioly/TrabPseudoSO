#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "Processo.h"
#include <vector>
#include "GerProcessos.h"
#include "GerArquivos.h"
#include "GerRecursos.h"
#include <cstdlib>
using namespace std;

class Dispatcher{

private:
	vector<Processo*> processos;
	vector<string> operacoes;
	vector<int> processosTempoReal;

public:
	Dispatcher(vector<Processo*> processos, vector<string> operacoes, vector<int> processosTempoReal);
	void run();
};




#endif // DISPATCHER_H
