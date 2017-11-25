#include "Dispatcher.hpp"

using namespace std;

Dispatcher::Dispatcher(vector<Processo*> processosN){
	processos = processosN;
}


void Dispatcher::run(){
	cout << "Executando...\n";
}