#ifndef STREAM_FILE
#define STREAM_FILE

#include <fstream>
#include <sstream>
using namespace std;

void read(string fileName) {
    ifstream file(fileName);

    if ( !file.is_open() )
        throw runtime_error("Erro na leitura");

    stringstream sstream;
    string line;
    char mark = ';';
    while ( getline(file, line, mark) ) {
        sstream = stringstream(line);

        // do stuff
        // sstream will handle conversions
    }

    file.close();
}

template <typename T>
void write(string fileName, T& val) {
    ofstream file(fileName, std::ios::app);

    if ( !file.is_open() )
        throw runtime_error("Erro na abertura do arquivo");

    file << val << endl;

    file.close();
}

#endif
