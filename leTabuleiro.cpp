#include <iostream>
#include <fstream> 
#define MAX 256

using namespace std;

int main(int argc, char **argv) {
    fstream arquivoTabuleiro; // instancia um objeto da classe fstream, que é um arquivo
    char linha[MAX];

    if (argc!=2) {
        cerr << "Uso: " << argv[0] << " <arquivo do labirinto>" << endl;
        return 1;
    }

    arquivoTabuleiro.open(argv[1],ios::in); // open- abre o arquivo; 
                                            // ios::in informa que é para leitura (ios::out é escrita);

    while (arquivoTabuleiro.getline(linha,MAX))
        cout << "[" << linha << "]" << endl;

    arquivoTabuleiro.close(); // fecha o arquivo

    return 0;
}

// exemplo que pode ser usado em .txt:
// ****..
// *....*
// ***..*
// ./leTabuleiro.cpp arquivo.txt