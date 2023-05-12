#ifndef SEARCH_H
#define SEARCH_H

#include <new>

void brute_force_search(const char *pat, const char *txt, int *occur);

int *LPS_array(const char *pat, int m);
void KMP_search(const char *pat, const char *txt, int *occur);


#endif
