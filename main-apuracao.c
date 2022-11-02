#include "aula18-apuracao.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main () {
    while (1) {
        pegaJson();
        printf("###########\n");
        sleep(30);
    }
    exit(0);
}
