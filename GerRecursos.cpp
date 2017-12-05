#include "GerRecursos.h"

/*
O gerenciador de E/S deve ser responsável por administrar a alocação e a liberação de todos os recursos disponíveis, garantindo uso exclusivo dos mesmos.
Ele deve gerenciar os seguintes recursos:
• 1 scanner
• 2 impressoras
• 1 modem
• 2 dispositivos SATA
Todos os processos, com exceção daqueles de tempo-real podem obter qualquer um desses
recursos. O pseudo-SO deve garantir que cada recurso seja alocado para um proceso por vez. Portanto, não
há preempção na alocação dos dispositivos de E/S. Assim, processos de tempo-real não precisam de
recursos de I/O.
*/

GerRecursos::GerRecursos(){

}

void GerRecursos::inicializaDispositivos(){
    cout << "Inicializando dispositivos..." << '\n';
    this->dispositivos.insert (pair<string,int> ("Scanner", 1));
    this->dispositivos.insert (pair<string,int> ("Printer1", 1));
    this->dispositivos.insert (pair<string,int> ("Printer2", 1));
    this->dispositivos.insert (pair<string,int> ("Modem", 1));
    this->dispositivos.insert (pair<string,int> ("Driver1", 1));
    this->dispositivos.insert (pair<string,int> ("Driver2", 1));
    cout << "Dispositivos inicializados com sucesso!" << '\n';
}

void GerRecursos::utilizaDispositivo(string dispositivo){

    map<string, int>::iterator it = this->dispositivos.find(dispositivo);

    if (it->second > 0) {
        it->second--;
        cout << "O dispositivo " << dispositivo << " foi alocado!\n\n";
    }
    else
        cout << "O dispositivos " << dispositivo << " esta sendo utilizado no momento!\n\n";
}

void GerRecursos::liberaDispositivo(string dispositivo){

    map<string, int>::iterator it = this->dispositivos.find(dispositivo);

    if ((it->first == "Scanner" && it->second == 0) ||
        (it->first == "Printer1" && it->second == 0) ||
        (it->first == "Printer2" && it->second == 0) ||
        (it->first == "Modem" && it->second == 0) ||
        (it->first == "Driver1" && it->second == 0)||
        (it->first == "Driver2" && it->second == 0)) {

        it->second++;
        cout << "O dispositivo " << dispositivo << " foi liberado!\n\n";
    }
}


// void GerRecursos::inicializarRecurso(Recurso tipo_recurso, Dispositivo *dispositivo, char *nome_dispositivo){
//   std::cout << "Inicializando o dispositivo " << nome_dispositivo << '\n';
// }
