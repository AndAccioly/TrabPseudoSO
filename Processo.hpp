#ifndef PROCESSO_H
#define PROCESSO_H

#include <iostream>

class Processo{
private:
	int id;
	int prioridade;
	int memOffset;
	int quantBlocosAlocados;
	int tempoInicio;
	bool impressora;
	bool scanner;
	bool drivers;

public:
	Processo(int idN, int prioridadeN, int memOffsetN, int quantBlocosAlocadosN, int tempoInicioN, bool impressoraN, bool scannerN, bool driversN);
	Processo();
	int getId();
	int getPrioridade();
	int getMemOffset();
	int getQuantBlocosAlocados();
	int getTempoInicio();
	bool getImpressora();
	bool getScanner();
	bool getDrivers();

	void setId(int idN);
	void setPrioridade(int prioridade);
	void setMemOffset(int memOffsetN);
	void setQuantBlocosAlocados(int quantBlocosAlocadosN);
	void setTempoInicio(int tempoInicioN);
	void setImpressora(bool impressoraN);
	void setScanner(bool scannerN);
	void setDrivers(bool driversN);
	void imprimeProcesso();

};

#endif // PROCESS_H