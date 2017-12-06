#include "Processo.h"

//Guarda todas as informações do processo.
using namespace std;

Processo::Processo(int idN, int prioridadeN, int memOffsetN, int quantBlocosAlocadosN, int tempoInicioN, int tempoProcessamentoN, int impressoraN, int scannerN, int driversN, int pediuModemN){
	id = idN;
	prioridade = prioridadeN;
	memOffset = memOffsetN;
	quantBlocosAlocados = quantBlocosAlocadosN;
	tempoInicio = tempoInicioN;
	tempoProcessamento = tempoProcessamentoN;
	impressora = impressoraN;
	scanner = scannerN;
	drivers = driversN;
	modem = pediuModemN;
}

Processo::Processo(){
	// id = 0;
	// prioridade = 0;
	// memOffset = 2;
	// quantBlocosAlocados = 0;
	// tempoInicio = 1;
	// tempoProcessamento = 2;
	// impressora = true;
	// scanner = true;
	// drivers = false;
	// modem = true;
}

int Processo::getId(){ return id; }

int Processo::getPrioridade(){ return prioridade; }

int Processo::getMemOffset(){ return memOffset; }

int Processo::getQuantBlocosAlocados(){	return quantBlocosAlocados; }

int Processo::getTempoInicio(){	return tempoInicio; }

int Processo::getTempoProcessamento(){ return tempoProcessamento; }

int Processo::getImpressora(){ return impressora; }

int Processo::getScanner(){ return scanner; }

int Processo::getDrivers(){ return drivers; }

int Processo::getModem(){ return modem; }


void Processo::setId(int idN){ id = idN; }

void Processo::setPrioridade(int prioridadeN){ prioridade = prioridadeN; }

void Processo::setMemOffset(int memOffsetN){ memOffset = memOffsetN; }

void Processo::setQuantBlocosAlocados(int quantBlocosAlocadosN){ quantBlocosAlocados = quantBlocosAlocadosN; }

void Processo::setTempoInicio(int tempoInicioN){ tempoInicio = tempoInicioN; }

void Processo::setTempoProcessamento(int tempoProcessamentoN){ tempoProcessamento = tempoProcessamentoN; }

void Processo::setImpressora(int impressoraN){ impressora = impressoraN; }

void Processo::setScanner(int scannerN){ scanner = scannerN; }

void Processo::setDrivers(int driversN){ drivers = driversN; }

void Processo::setModem(int modemN){ modem = modemN; }

void Processo::imprimeProcesso(){
	cout << "id:         " << id << "\n";
	cout << "offset:     " << memOffset << "\n";
	cout << "blocos:     " << quantBlocosAlocados << "\n";
	cout << "prioridade: " << prioridade << "\n";
	cout << "tInicio:    " << tempoInicio << "\n";
	cout << "tProc:      " << tempoProcessamento << "\n";
	cout << "impressora: " << impressora << "\n";
	cout << "scanner:    " << scanner << "\n";
	cout << "modem:      " << modem << "\n";
	cout << "drivers:    " << drivers << "\n\n";
}
