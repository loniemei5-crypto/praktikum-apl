#ifndef VALIDASI_H
#define VALIDASI_H

#include <string>
#include <stdexcept>
using namespace std;

void validasiTelepon(string telepon){
    for(char c : telepon){
        if(!isdigit(c)){
            throw invalid_argument("Telepon harus berupa angka!");
        }
    }
}

void validasiKosong(string data, string field){
    if(data.empty()){
        throw runtime_error(field + " tidak boleh kosong!");
    }
}

#endif