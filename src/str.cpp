#include "str.hpp"
#include <ostream>

int Int_Random_gerator :: generate(int min, int max){
    static std::random_device rd; // Dispositivo de hardware para geração de números aleatórios
    static std::mt19937 gen(rd()); // Gerador de números aleatórios Mersenne Twister 
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

Str :: Str(const char *str, int size){
    strConst = str;
    this -> size = size;    //size = strlen(str)
    dinamic = false;
}

Str :: Str(int size){
    this -> size = size;
    str = new char[size + 1];
    dinamic = true;
    str[size] = '\0';
}

Str :: ~Str(){
    if(dinamic)
        delete[] str;
}

void Str :: randomize(char begin = 'a', char end = 'z'){
    if (!dinamic)   return;
    for(int i = 0; i < size ; ++i){
        str[i] = Int_Random_gerator::generate(begin, end);
    }
}

void Str :: setStr(const char *str){
    this->strConst = str;
}

void Str :: setStr(char *str){
    this->str = str;
}

char* Str :: getStr(){
    return str;
}

const char* Str :: getStrConst(){
    return strConst;
}

bool Str :: isDinamic(){
    return dinamic;
}

int Str :: getSize(){
    return size;
}

std::ostream& operator <<(std::ostream &out, Str s){
    char *st = s.getStr();
    while (*st)
        out << *st++;
    return out;
}

