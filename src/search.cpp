#include <cstring>
#include "search.hpp"
#include <iostream>

void brute_force_search(const char *pat, const char *txt, int *occur){

    int m = strlen(pat);
    int k = 0;
    for (int i = 0; txt[i + m - 1]; ++i ){
        int j = 0;
        while (pat[j] && txt[i+j] == pat[j]){
            ++j;
        }
        if (j == m){
            occur[k++] = i;
        }
    }

    occur[k] = -1;
}


int *LPS_array(const char *pat, int m){     //longest prefix that is also a suffix of txt
    int *lps = new int[m];
    int i = -1;

    lps[0] = -1;
    for(int j = 1; j < m; ++j){
        if( pat[j] == pat[i+1] )
            ++i;
        else
            i = -1;
        lps[j] = i;
    }

    return lps;
}

void KMP_search(const char *pat, const char *txt, int *occur){
    int m = strlen(pat);
    int *lps = LPS_array(pat, m);
    int i = 0, j = 0, k = 0;

    while(txt[i]){
        if ( txt[i] == pat[j] ){
            ++i;
            ++j;
        }
        else
            if(j != 0)      j = lps[j - 1] + 1;
            else            ++i;
        if (j == m){
            occur[k++] =  i - j;
            j = lps[j - 1] + 1;
        }
    }
    
    occur[k] = -1;

    delete[] lps;
}
