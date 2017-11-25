#include "ExecutaTudo.hpp"

using namespace std;

ExecutaTudo::ExecutaTudo(vector<Processo*> processosN){
	processos = processosN;
}


void ExecutaTudo::run(){
	cout << "Executando...\n";
}