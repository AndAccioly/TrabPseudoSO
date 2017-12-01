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
	bool impressora;
	bool scanner;
	bool drivers;
	bool modem;

public:
	Processo(int idN, int prioridadeN, int memOffsetN, int quantBlocosAlocadosN,
			int tempoInicioN, int tempoProcessamentoN, bool impressoraN, bool scannerN, bool driversN, bool pediuModemN);
	Processo();
	int getId();
	int getPrioridade();
	int getMemOffset();
	int getQuantBlocosAlocados();
	int getTempoInicio();
	int getTempoProcessamento();
	bool getImpressora();
	bool getScanner();
	bool getDrivers();
	bool getModem();

	void setId(int idN);
	void setPrioridade(int prioridade);
	void setMemOffset(int memOffsetN);
	void setQuantBlocosAlocados(int quantBlocosAlocadosN);
	void setTempoInicio(int tempoInicioN);
	void setImpressora(bool impressoraN);
	void setTempoProcessamento(int tempoProcessamentoN);
	void setScanner(bool scannerN);
	void setDrivers(bool driversN);
	void setModem(bool modemN);
	void imprimeProcesso();

};

#endif // PROCESS_H
