#include <iostream>
#include <iomanip>
#include "search_time.hpp"
#include "real_instances.hpp"

using namespace std;

int main(int argc, char **argv){
    try{

        if (argc != 4 && argc != 6 )
            throw invalid_argument("Formato inválido. Use uma das entradas abaixo:\n"
            "./programa A [l] [m] [n] [I]\n./programa R [x] [y] ");

        double time_brt, time_kmp;

        if (*argv[1] == 'R'){
            SearchTime search(Texto_Livros);
            int y = atoi(argv[3]);   int x = atoi(argv[2]);
            if (x < 0 || y > 35129 || x > y)
                throw invalid_argument("Intervalo fora de [0 a 35129]");
            int i = y - x + 1; 
            
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
            throw invalid_argument("Somente instâncias do tipo [R] ou [A]");
        }

        cout << setw(15) << "\tAlgoritmo\t"  << setw(25) << "Execução (em segundos)\n";
        cout << setw(30) << left << "Força Bruta" << " " << fixed << setprecision(6) << time_brt << endl;
        cout << setw(30) << left << "Knuth-Morris-Pratt" << fixed << setprecision(6) << time_kmp << endl;
    }
    catch (const bad_alloc& e){
        cerr << "ERRO de alocação: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (const exception& e){
        cerr << "ERRO: " << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

