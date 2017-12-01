#ifndef DISPATCHER_H
#define DISPATCHER_H


#include <vector>
#include <cstdlib>

#include "Processo.h"
#include "GerProcessos.h"
#include "GerMemoria.h"

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
