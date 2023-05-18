#include "search_time.hpp"
#include <iostream>
#include <chrono>

#include "search.hpp"

SearchTime :: SearchTime(int n, int m) : txt(n), pattern(m) {
    if (m > n)
        throw std::invalid_argument("Padrão maior que o texto");
    occurr_brt = new int[ n + 1];
    occurr_kmp = new int[ n + 1];
    time_brt = time_kmp = 0.0f;
}

SearchTime :: SearchTime(const char *text) : txt(text), pattern(nullptr, -1) {
    occurr_brt = new int[ txt.getSize() + 1];
    occurr_kmp = new int[ txt.getSize() + 1];
    time_brt = time_kmp = 0.0f;
}

SearchTime :: ~SearchTime(){
    delete[] occurr_brt;
    delete[] occurr_kmp;
}

void SearchTime :: setPattern(const char *pattern){
    this -> pattern.setStr(pattern);
}

void SearchTime :: randomize_txt(char end_range){
    txt.randomize('a', end_range);
}
void SearchTime :: randomize_pattern(char end_range){
    pattern.randomize('a', end_range);
}

double SearchTime :: getTime_brt(){
    return time_brt;
}
double SearchTime :: getTime_kmp(){
    return time_kmp;
}

bool SearchTime :: compare_occurr(){
    int *brt = occurr_brt;
    int *kmp = occurr_kmp;
    while (*brt != -1 || *kmp != -1){
        if (*brt != *kmp)
            return false;
        ++brt;
        ++kmp;
    }

    return true;
}

double SearchTime :: time( int *occurr, void (*search)(const char *, const char *, int *) ){
    std::chrono::time_point<std::chrono::steady_clock> start, end;

    if (txt.isDinamic()){
        char *pat = pattern.getStr();
        char *t = txt.getStr();
        start = std::chrono::steady_clock::now();
        search(pat, t, occurr);
        end = std::chrono::steady_clock::now();
    }
    else{
        const char *pat = pattern.getStrConst();
        const char *t = txt.getStrConst();
        start = std::chrono::steady_clock::now();
        search(pat, t, occurr);
        end = std::chrono::steady_clock::now();
    }
    
    std::chrono::duration<double> d = end - start;

    return d.count();
}

void SearchTime :: run(){
    time_brt += time(occurr_brt, brute_force_search);
    time_kmp += time(occurr_kmp, KMP_search);
    
    if(!compare_occurr())
        throw std::logic_error("Padrões incorretos.");
}

