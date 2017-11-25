#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <Vector>

class Dispatcher{

private:
	vector<Processo*> processos;

public:
	Dispatcher(vector<Processo*> processos);
	void run();
};




#endif // DISPATCHER_H