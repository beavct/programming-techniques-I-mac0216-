#include "aula19-par.h"
#include "aula19-impar.h"
#include <stdio.h>
#include <stdlib.h>

/*!
 * \brief Programa principal: main
 * Testa as funções ehPar e ehImpar com os valores 2 e 3
 * 
 * \return retorno: (int) Não há verificações cuidadosas de erro nesse
 * programa. No geral vai sempre devolver zero. Claro que há situações
 * em que pode retornar outro valor para o SO, em casos em que ocorram
 * erros irrecuperáveis que façam o programa abortar a execução
 * (segfault por exemplo)
 */
int main() {
    if (ehPar(2))
        printf("2 é par\n");
    else
        printf("2 é ímpar\n");

    if (ehImpar(3))
        printf("3 é ímpar\n");
    else
        printf("3 é par\n");

    exit(0);
}
