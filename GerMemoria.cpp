#include "GerMemoria.h"
#include <algorithm>
#include <iostream>

GerMemoria::GerMemoria() {
    this->tamTempoReal = 64;
    this->tamUsuario = 960;
}

void GerMemoria::setTamTempoReal(int tamanho){
    this->tamTempoReal = tamanho;
    cout << "Tamanho Memoria Tempo Real: " << tamanho << '\n';
}
void GerMemoria::setTamUsuario(int tamanho){
    this->tamUsuario = tamanho;
    cout << "Tamanho Memoria Usuario: " << tamanho << '\n';
}

int GerMemoria::getTamTempoReal(){
    return this->tamTempoReal;
}

int GerMemoria::getTamUsuario(){
    return this->tamUsuario;
}
void GerMemoria::addMemTempoReal(int processoId){
    memTempoReal.push_back(processoId);
}
void GerMemoria::addMemUsuario(int processoId){
    memUsuario.push_back(processoId);
}
void GerMemoria::remMemTempoReal(int processoId){
    memTempoReal.erase(remove(memTempoReal.begin(), memTempoReal.end(), processoId), memTempoReal.end());
}
void GerMemoria::remMemUsuario(int processoId){
    memUsuario.erase(remove(memUsuario.begin(), memUsuario.end(), processoId), memUsuario.end());
}
