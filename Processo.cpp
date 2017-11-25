#include "Processo.hpp"

//Guarda todas as informações do processo.
using namespace std;

Processo::Processo(int idN, int prioridadeN, int memOffsetN, int quantBlocosAlocadosN, int tempoInicioN, bool impressoraN, bool scannerN, bool driversN){
	id = idN;
	prioridade = prioridadeN;
	memOffset = memOffsetN;
	quantBlocosAlocados = quantBlocosAlocadosN;
	tempoInicio = tempoInicioN;
	impressora = impressoraN;
	scanner = scannerN;
	drivers = driversN;
}

Processo::Processo(){
	id = 0;
	prioridade = 0;
	memOffset = 2;
	quantBlocosAlocados = 0;
	tempoInicio = 1;
	impressora = true;
	scanner = true;
	drivers = false;
}

int Processo::getId(){ return id; }

int Processo::getPrioridade(){ return prioridade; }

int Processo::getMemOffset(){ return memOffset; }

int Processo::getQuantBlocosAlocados(){	return quantBlocosAlocados; }

int Processo::getTempoInicio(){	return tempoInicio; }

bool Processo::getImpressora(){ return impressora; }

bool Processo::getScanner(){ return scanner; }

bool Processo::getDrivers(){ return drivers; }


void Processo::setId(int idN){ id = idN; }

void Processo::setPrioridade(int prioridadeN){ prioridade = prioridadeN; }

void Processo::setMemOffset(int memOffsetN){ memOffset = memOffsetN; }

void Processo::setQuantBlocosAlocados(int quantBlocosAlocadosN){ quantBlocosAlocados = quantBlocosAlocadosN; }

void Processo::setTempoInicio(int tempoInicioN){ tempoInicio = tempoInicioN; }

void Processo::setImpressora(bool impressoraN){ impressora = impressoraN; }

void Processo::setScanner(bool scannerN){ scanner = scannerN; }

void Processo::setDrivers(bool driversN){ drivers = driversN; }

void Processo::imprimeProcesso(){
	cout << "id:         " << id << "\n";
	cout << "prioridade: " << prioridade << "\n";
	cout << "memOffset:  " << memOffset << "\n";
	cout << "qntBlocos:  " << quantBlocosAlocados << "\n";
	cout << "tInicio:    " << tempoInicio << "\n";
	cout << "impressora: " << impressora << "\n";
	cout << "drivers:    " << drivers << "\n";
}