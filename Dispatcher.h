#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "Processo.h"
#include <vector>
#include "GerProcessos.h"
#include <cstdlib>
using namespace std;

class Dispatcher{

private:
	vector<Processo*> processos;
	vector<string> operacoes;

public:
	Dispatcher(vector<Processo*> processos, vector<string> operacoes);
	void run();
};




#endif // DISPATCHER_H
