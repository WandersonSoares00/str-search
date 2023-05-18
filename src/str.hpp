#ifndef STR_RANDOM_H
#define STR_RANDOM_H

#include <random>
#include <chrono>

class Int_Random_gerator{
public:
    static int generate(int min, int max);
};

class Str{
    bool dinamic;
    int size;
    char *str;  const char *strConst;

    public:

    Str(const char *str, int size = 5000);
    Str(int size);
    ~Str();
    
    void randomize(char begin, char end);
    
    void setStr(char *str);
    void setStr(const char *str);
    char* getStr();
    const char* getStrConst();
    bool isDinamic();

    int getSize();
};

#endif