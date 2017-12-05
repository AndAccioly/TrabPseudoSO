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
	int tempoProcessamento;
	int impressora;
	int scanner;
	int drivers;
	int modem;

public:
	Processo(int idN, int prioridadeN, int memOffsetN, int quantBlocosAlocadosN,
			int tempoInicioN, int tempoProcessamentoN, int impressoraN, int scannerN, int driversN, int pediuModemN);
	Processo();
	int getId();
	int getPrioridade();
	int getMemOffset();
	int getQuantBlocosAlocados();
	int getTempoInicio();
	int getTempoProcessamento();


	int getImpressora();
	int getScanner();
	int getDrivers();
	int getModem();

	void setId(int idN);
	void setPrioridade(int prioridade);
	void setMemOffset(int memOffsetN);
	void setQuantBlocosAlocados(int quantBlocosAlocadosN);
	void setTempoInicio(int tempoInicioN);
	void setImpressora(int impressoraN);
	void setTempoProcessamento(int tempoProcessamentoN);
	void setScanner(int scannerN);
	void setDrivers(int driversN);
	void setModem(int modemN);
	void imprimeProcesso();

};

#endif // PROCESS_H
