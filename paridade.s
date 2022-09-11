section .text     

paridade:
          mov   bl, 2
          div   bl
          ret                  ; retorna o controle para quem chamou

global _start
_start:
          mov   ax, numero     ; definindo o parâmetro da função 
          call  paridade       ; chama a função
          shr   ax, 8          ; instrução para deslocar os bits do registrador 8 bits para a direita
          mov   rdi, rax
          mov   rax, 60
          syscall
          ; o resto vai estar em echo $? no shell

section .data
numero: equ 13
