#include <cstring>
#include "search.hpp"

void brute_force_search(const char *pat, const char *txt, int *occur){

    int m = strlen(pat);
    int k = 0;
    for (int i = 0; txt[i+m]; ++i ){
        int j = 0;
        while (pat[j] && txt[i+j] == pat[j]){
            ++j;
        }
        if (j == m)
            occur[k++] = i;
    }

    occur[k] = -1;
}

/*int *LPS_array(const char *pat, int m){     //longest prefix that is also a suffix of txt
    int *lps = new int[m];
    int i = -1;
    *lps = -1;
    for(const char *j = pat + 1; *j ; ++j){
        if( *j == *pat + i + 1 )
            ++i;
        else
            i = -1;
        *(++lps) = i;
    }
    return lps - m;
}
void KMP_search(const char *pat, const char *txt, int *occur){
    int m = strlen(pat);
    int *lps = LPS_array(pat, m); // lps[0..m-1], ∀ i ∈ [0 .. m-1], lps[i] = {-1, 0, 1, ... i-1}
    int *occurrence = occur;
    const char *tt = txt;
    const char *patt = pat;
    
    while(*tt){
        if ( *tt == *patt ){
            ++tt;
            ++patt;
        }
        else
            if(patt != pat)      patt += *(lps + (patt - pat) - 1) + 1;
            else            ++tt;
        if (patt == pat + m){
            *(occurrence++) = (tt - &txt[0]) - (patt - pat);  // Pattern found in txt[i-j .. i-1]
            patt += *(lps + m - 1) + 1;                       // Jump defined by last position
        }
    }
    delete[] lps;
}
*/

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
    int *lps = LPS_array(pat, m); // lps[0..m-1], ∀ i ∈ [0 .. m-1], lps[i] = {-1, 0, 1, ... i-1}
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
            occur[k++] =  i - j;  // Pattern found in txt[i-j .. i-1]
            j = lps[j - 1] + 1;   // Jump defined by last position
        }
    }

    occur[k] = -1;

    delete[] lps;
}
