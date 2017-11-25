#ifndef EXECUTATUDO_H
#define EXECUTATUDO_H

#include <Vector>

class ExecutaTudo{

private:
	vector<Processo*> processos;

public:
	ExecutaTudo(vector<Processo*> processos);
	void run();
};




#endif // EXECUTATUDO_H