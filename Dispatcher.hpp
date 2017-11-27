#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <Vector>

class Dispatcher{

private:
	vector<Processo*> processos;
	vector<string> operacoes;

public:
	Dispatcher(vector<Processo*> processos, vector<string> operacoes);
	void run();
};




#endif // DISPATCHER_H