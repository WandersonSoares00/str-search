#include <iostream>
#include "search.hpp"

int main(int argc, char **argv){

    int v[100];
    brute_force_search(argv[2], argv[1], v);

    KMP_search(argv[2], argv[1], v);

    return EXIT_SUCCESS;
}

