#ifndef SEARCH_TIME_HPP
#define SEARCH_TIME_HPP

#include "str.hpp"

class SearchTime{
    Str txt, pattern;
    int *occurr_brt, *occurr_kmp;
    double time_brt, time_kmp;

    public:
    SearchTime(const char *text);
    SearchTime(int n, int m);
    ~SearchTime();

    void randomize_txt(char end_range);
    void randomize_pattern(char end_range);
    void setPattern(const char *pattern);
    double getTime_brt();
    double getTime_kmp();
    void run();

    private:
    double time( int *occurr, void (*search)(const char *, const char *, int *) );
    bool compare_occurr();
};

#endif
