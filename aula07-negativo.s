section .text

global _start
_start:
        mov   ah, 0xff ; 0xff é 11111111 binário = 255 decimal

        cmp   ah, 0    ; ah é 255, que é maior que zero

        jg    maior    ; então esse jump desviará o código para o rótulo
                       ; 'maior' e o echo $? retornaria 1? Não. Porque
                       ; na verdade 0xff é -1. Para o assembly
                       ; interpretar o 0xff como 255, teria que usar
                       ; ja no lugar de jg

menor:  mov   rdi, 0
        mov   rax, 60
        syscall

maior:  mov   rdi, 1
        mov   rax, 60
        syscall
