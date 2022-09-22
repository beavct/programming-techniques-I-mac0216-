; Esta funcao calcula (A**2 + B**2) / (C**2).
; Suposicao:  o resultado do calculo cabe em 16 bits.
; O resultado é retornado em ax. 
; Os valores dos parâmetros de entrada C, B e A são passados pela pilha.
; A memória para variáveis locais é alocada dinamicamente.
; O chamador é quem limpa os parâmetros da pilha.
;
; short int func (short int A, short int B, short int C)
;
; obs.: short int ocupa 16 bits então cada valor (cada parâmetro e o retorno
;       da função ocupam, cada, 2 posições na memória)

section .data

; Os parâmetros vem na pilha com os seguintes deslocamentos 
; em relacao a rbp
A: equ 	+16
B: equ 	+18
C: equ	+20

; Deslocamentos das variáveis locais
temp1:	equ	-4
temp2:	equ	-6
temp3:	equ -8

section .text     

func:   ;;;;; RESPONSABILIDADE 1: salvar RBP do chamador e definir nova base
        push    rbp
        mov     rbp, rsp

        ;;;;; RESPONSABILIDADE 2: salvar todos os registradores que vão ser afetados
        push    dx

        ;;;;; RESPONSABILIDADE 3: alocar espaço para variáveis locais
        sub     rsp, 6

        ;;;;; RESPONSABILIDADE 4: realizar trabalho usando argumentos e variáveis locais
        mov     ax, [rbp+A]        ; copia A em AX  
        mul  	word [rbp+A]       ; A * A
        mov     [rbp+temp1], ax    ; armazena A*A como uma variável local

        mov     ax, [rbp+B]        ; copia B em AX
        mul     word [rbp+B]        ; B * B
        mov     [rbp+temp2], ax    ; armazena B*B localmente

        mov     ax, [rbp+C]        ; copia C em AX
        mul     word [rbp+C]        ; C * C
        mov     [rbp+temp3], ax    ; armazena C*C localmente

        mov     ax, [rbp+temp1]    ; obtem A*A
        add     ax, [rbp+temp2]    ; A*A + B*B

        ;;;;; RESPONSABILIDADE 5: setar valor de retorno (em espaço próprio ou em *AX)
        div     word [rbp+temp3]   ; divide por C*C (resposta em AX)

        ;;;;; RESPONSABILIDADE 6: desalocar o espaço das variáveis locais
        add     rsp, 6

        ;;;;; RESPONSABILIDADE 7: restaurar registradores afetados
        pop     dx

        ;;;;; RESPONSABILIDADE 8: restaurar RBP
        pop     rbp

        ;;;;; RESPONSABILIDADE 9: retornar
        ret

global _start

_start:
        ; chama FUNC (10, 20, 5)
        ;;;;; RESPONSABILIDADE 1: empilhar parâmetros na ordem inversa
        mov   ax, 5    ; empilha C
        push  ax
        mov   ax, 20   ; empilha B
        push  ax
        mov   ax, 10   ; empilha A
        push  ax

        ;;;;; RESPONSABILIDADE 2: chamar função
        call  func

        ;;;;; RESPONSABILIDADE 3: liberar espaço dos parâmetros        
        add   rsp, 6
 
        ; devolve o resultado que vem em ax chamando o nucleo do Linux
        mov    rdi, rax      ; primeiro parametro: exit code
        mov    rax, 60       ; numero da chamada ao sistema (sys_exit)
        syscall              ; executa a chamada

        ; o valor de retorno pode ser visto no bash com echo $? 
