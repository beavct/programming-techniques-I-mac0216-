#!/bin/bash -x

rm -f *.o *.a aula19-par_impar

gcc -Wall -c -o aula19-par.o aula19-par.c
gcc -Wall -c -o aula19-impar.o aula19-impar.c 
ar -rcv libaula19-par_impar.a aula19-par.o aula19-impar.o
rm -f aula19-par.o aula19-impar.o
gcc -Wall -o aula19-par_impar aula19-main.c libaula19-par_impar.a

doxygen aula19-Doxyfile

exit 0
