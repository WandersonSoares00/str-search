#include <iostream>
#include <iomanip>
#include "search_time.hpp"
#include "real_instances.hpp"

using namespace std;

int main(int argc, char **argv){
    try{

        if (argc != 4 && argc != 6 )
            throw invalid_argument("Use ./programa A [l] [m] [n] [I]");

        double time_brt, time_kmp;
        
        
        if (*argv[1] == 'R'){          //   ./programa R [x] [y] (0 a 35130)
            SearchTime search(Texto_Livros);
            int i = atoi(argv[3]) - atoi(argv[2]) + 1;  //y - x + 1
            
            while (--i){
                search.setPattern(Padroes_Palavras[i]);
                search.run();
            }
            time_brt = search.getTime_brt();   time_kmp = search.getTime_kmp();
        }
        else if (*argv[1] == 'A'){
            SearchTime search(atoi(argv[4]), atoi(argv[3]));
            int i = atoi(argv[5]);
            while (i--){
                search.randomize_txt(*argv[2]);
                search.randomize_pattern(*argv[2]);
                search.run();
            }
            time_brt = search.getTime_brt();    time_kmp = search.getTime_kmp();
        }
        else{
            throw invalid_argument("A ou R.");
        }

        cout << setw(30) << left<<"Força Bruta" << setw(20) << right << fixed << setprecision(6) << showpoint << time_brt << '\n';
        cout << setw(30) << left<<"Knuth–Morris–Pratt" << setw(20) << right << fixed << setprecision(6) << showpoint << time_kmp << '\n';
    }
    catch (const exception& e){
        cerr << "ERRO: " << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

