.intel_syntax noprefix
.global soma

# Obs.: no caso de usar assembly para ser chamado a partir de um .c,
# os comentários precisam ser identificados com # e não com ;

soma:
        push    rbp           # cria o stack frame
        mov     rbp,rsp       

        sub     rsp,4         # reserva espaco para x (inteiro = 32
                              # bits, precisa de 4 endereços de memória)

        mov     [rbp-4],edi   # armazena o primeiro param. em x (int = 32 bits, edi)
        add     [rbp-4],esi   # soma os dois parametros de entrada (int = 32 bits, esi)
        mov     eax,[rbp-4]   # armazena x em eax (para retorno da funcao) (int = 32 bits, eax)
        add     rsp,4         # libera espaco de x
        pop     rbp           # restaura a base da pilha
        ret
