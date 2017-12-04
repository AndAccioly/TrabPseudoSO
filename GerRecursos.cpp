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

// void GerRecursos::inicializarRecurso(Recurso tipo_recurso, Dispositivo *dispositivo, char *nome_dispositivo){
//   std::cout << "Inicializando o dispositivo " << nome_dispositivo << '\n';
// }
