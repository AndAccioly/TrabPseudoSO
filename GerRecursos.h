#ifndef GERRECURSOS_H
#define GERRECURSOS_H

#include <map>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

// enum dispositivo {
//   SCANNER,
//   PRINTER,
//   MODEM,
//   HARD_DISK
// };
//
// struct dispositivo_ {
//   char *name;
//   int res_id;
//   enum device resource_type;
//   bool is_being_used;
// };
//
// typedef struct dispositivo_ Dispositivo;
// typedef enum dispositivo Recurso;

class GerRecursos {

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

private:

    GerRecursos();
    map<string, int> dispositivos;

public:

    static GerRecursos& instance(){
      static GerRecursos instance;
      return instance;
    }
    void inicializaDispositivos();
    void utilizaDispositivo(string dispositivo);
    void liberaDispositivo(string dispositivo);
    // void inicializarRecurso();
};

#endif // GERRECURSOS_H
