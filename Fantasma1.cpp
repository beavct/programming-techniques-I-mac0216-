#include <iostream>
#define VIVO 1
#define MORTO 0

using std::cout;
using std::endl;
 
// O ideal é colocar as classes em arquivos separados

class Fantasma {
    private:
        int x;
        int y;
        int status = VIVO;
        char sprite;
    public:
        void setPosicao(int x, int y) {
                this->x = x; // Para o compilador entender que estão
                this->y = y; // recebendo os valores dos árâmetros dos métodos (x e y)  
        }
        void morre() {
            status = MORTO; 
        }
        int getStatus() {
            return status;
        }
        int getX();
};

int main () {
    Fantasma Gasparzinho;

    cout << Gasparzinho.getStatus() << endl;
}