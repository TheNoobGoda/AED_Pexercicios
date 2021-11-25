#include <iostream>
#include "parque.h"
#include <vector>

using namespace std;


 ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli): lotacao(lot), numMaximoClientes(nMaxCli) {
          vagas=lot;
    }

unsigned int ParqueEstacionamento::getNumLugares() const {
     return lotacao;
 }

unsigned int ParqueEstacionamento::getNumMaximoClientes() const {
     return numMaximoClientes;
 }



InfoCartao::InfoCartao() {

}

bool ParqueEstacionamento::adicionaCliente(const string &nome) {
   int posicao = posicaoCliente(nome);


   if (posicao == -1) {
       if (vagas > 0) {
           vagas = vagas-1;
           InfoCartao newClient;
           newClient.nome = nome;
           newClient.presente = 0;
           clientes.push_back(newClient);
           return true;




       } else {
           return false;
       }
   }

 }

int ParqueEstacionamento::posicaoCliente(const string &nome) const {
    cout <<clientes.size();
    for (int i = 1; i <= clientes.size(); i++) {
        if (nome == clientes.at(i - 1).nome) {
            return i - 1;
        }
    }

    return -1;
}

bool ParqueEstacionamento::entrar(const string &nome) {

     for (int i = 0; i <=clientes.size(); i++){
         if (nome == clientes.at(i).nome){
           if (clientes.at(i).presente == true){
               return false;

           }  else if (vagas == 0){
               return false;
           }else {
               vagas = vagas -1;
               return true;
           }
         }
     }

 }


bool ParqueEstacionamento::retiraCliente(const string &nome) {
     for (int i =0; i <= clientes.size(); i++){
         if (nome == clientes.at(i).nome){
             if (clientes.at(i).presente == true){
                 return false;
             } else {
                 clientes.erase(clientes.begin()+i-1);
             }
         }
     }
 }

bool ParqueEstacionamento::sair(const string &nome) {
     for (int i =0; i <= clientes.size(); i++){
         if (nome== clientes.at(i).nome) {
             if (clientes.at(i).presente == true) {
                 clientes.at(i).presente == false;
                 vagas = vagas -1;
                 return true;
             }
         }
     }
    return false;
 }

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const {
    return numMaximoClientes-vagas;
 }

unsigned int ParqueEstacionamento::getNumClientesAtuais() const {
    return clientes.size();
 }