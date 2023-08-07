# str-search

A comparison of the search in text times of the following algorithms:
- [Brute-force search](https://en.wikipedia.org/wiki/Brute-force_search)
- [Knuth–Morris–Pratt algorithm](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm)

## Execution modes:
The program generetes instances for search and runs them for each algorithm. Follow the types of instances below:
- Random: Fill the string with a random text.
- Real: Use a book of [public domain](https://www.gutenberg.org/ebooks/1661) to search predefined patterns.

## Usage

### Dependencies
- GNU C++ Compiler ( g++ )
- GNU Make installed

### Run
1. Clone the repository:
    `git clone https://github.com/WandersonSoares00/str-search`
2. Change the directory:
    `cd str-search`
3. Compile:
    `make all`
4. Run with options: <br>
    The program can be executed using the following formats: <br>
    *./main A [end range] [pattern size] [text size] [number of instances]* <br>
    
    Where [end range] indicate the final range starting from 'a' to the text and pattern.

    Here's an example:
    run `./main A d 5 500 3` <br>
    This command will display the search time results for 3 randomly generated texts and patterns, each with a size of 500 characters and a pattern size of 5 characters. The character range for both text and pattern generation will be from 'a' to 'd'.
    <br>
    Another format is: <br>
    *./main R [x] [y]*
    Where [x] indicates the start range of the patterns to be searched in the real instance found in [src/real_instances.hpp](src/real_instances.hpp) and [y] is the end range. Note that 0 <= x <= y <= 35129.
## Licence information
This project is licensed under the GNU General Public License v3.0.
