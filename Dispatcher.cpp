#include "Dispatcher.h"
#define ENCERRANDO_EXECUCAO "Encerrando execucao."

Dispatcher::Dispatcher(vector<Processo*> processosN, vector<string> operacoesN, vector<int> processosTempoRealN){
	processos = processosN;
	operacoes = operacoesN;
	processosTempoReal = processosTempoRealN;

}

//timer é um numero inteiro que representa o tempo de sistema. Vai aumentando de um em um.
void Dispatcher::run(){
	int numSegmentos, posicaoBloco, quantBlocos, idProcesso, codOperacao;
	char nomeArquivo;

	GerMemoria *gerMem = &GerMemoria::instance();
	GerRecursos *gerRec = &GerRecursos::instance();
	GerArquivos *gerArq = &GerArquivos::instance();
	GerProcessos *gerProc = &GerProcessos::instance();

	for(int i = 0; i < processosTempoReal.size(); i++){
		cout << "****" << processosTempoReal[i];
	}

	gerProc->processosTempoReal = processosTempoReal;
	gerRec->inicializaDispositivos();
	
	cout << "\n...................EXECUTANDO PROCESSOS...................\n";
	int timer = 0;

	int quantProcessos = processos.size();

	while( (processos.size() > 0) || (!gerProc->estaVazio()) ){

		// cout << "Ciclo " << timer << "\n";
		//verifica dentre os processos se algum deles esta na vez de ser executado. Se estiver, manda para o gerProc
		for(int i = 0; i < processos.size(); i++){
			if(processos.at(i)->getTempoInicio() == timer){

				cout << "Processo " << processos.at(i)->getId() << " vai ser adicionado\n";

				if(processos.at(i)->getPrioridade() == 0) {
					if(processos.at(i)->getQuantBlocosAlocados() <= gerMem->getTamTempoReal()) {
						gerMem->addMemTempoReal(processos.at(i)->getId());
						gerMem->setTamTempoReal(gerMem->getTamTempoReal() - processos.at(i)->getQuantBlocosAlocados());
						gerProc->adicionarProcesso(processos.at(i));
					} else {
						cout << "Nao ha espaco para alocar processo!\n";
					}
				}else{
					if(processos.at(i)->getQuantBlocosAlocados() <= gerMem->getTamUsuario()) {
						gerMem->addMemUsuario(processos.at(i)->getId());
						gerMem->setTamUsuario(gerMem->getTamUsuario() - processos.at(i)->getQuantBlocosAlocados());
						gerProc->adicionarProcesso(processos.at(i));
					} else {
						cout << "Nao ha espaco para alocar o processo!\n";
					}
				}
				processos.erase(processos.begin() + i);
			}
		}
		gerProc->atualizar(timer);
		timer = timer + 1;
	}

	cout << ENCERRANDO_EXECUCAO << "\n";

	cout << "\nSistemas de arquivos => \n";

	gerArq->setTamanhoMaximo(atoi(operacoes[0].c_str()));

	numSegmentos = atoi(operacoes[1].c_str());

	for (int i=2; i<numSegmentos+2; i++) {
		nomeArquivo = operacoes[i][0]; //converte pra inteiro
		posicaoBloco = operacoes[i][3] - '0';
		quantBlocos = operacoes[i][6] - '0';
		gerArq->addArquivo(nomeArquivo, posicaoBloco, quantBlocos);
	}

	for (int i = numSegmentos+2, j = 0; i<operacoes.size(); i++, j++)
	{
		idProcesso = (operacoes[i][0] - '0')+1;
		codOperacao = operacoes[i][3] - '0';
		nomeArquivo = operacoes[i][6];
		if (codOperacao == 0) {
			if (idProcesso <= quantProcessos) {
				if(gerArq->addArquivo(idProcesso, nomeArquivo, (operacoes[i][9] - '0')))
					cout << "Operação " << j << " => Sucesso\nO processo "<< idProcesso-1 << " criou o arquivo " << nomeArquivo << ".\n\n";
				else
					cout << "Operação " << j << " => Falha\nO processo "<< idProcesso-1 << " não pode criar o arquivo " << nomeArquivo << " (falta de espaço).\n\n";
			} else cout << "Operação " << j << " => Falha\nNão existe o processo.\n\n";
		}
		else {
			if (idProcesso<= quantProcessos) {
				cout << "Operação " << j << " => Sucesso\nO processo "<< idProcesso-1 << " removeu o arquivo " << nomeArquivo << ".\n\n";
				gerArq->remArquivo(idProcesso, nomeArquivo);
			} else cout << "Operação " << j << " => Falha\nNão existe o processo.\n\n";
		}


	}
	gerArq->imprimeArquivos();

}
