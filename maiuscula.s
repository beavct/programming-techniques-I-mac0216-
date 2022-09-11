; Este programa lê um texto da entrada padrão e passa-o para letras maiúsculas.
; O resultado é exibido na saida padrão em Linux NASM, 64-bits
; Obs.: o texto só pode ter caracteres ASCII (no mínimo 1 e no máximo 255 caracteres)
; Obs.: se o arquivo pudesse estar vazio, o laço teria que ser diferente

global _start 

section .text
_start:
      ; lê o arquivo da entrada padrão  (teclado = stdin = 0)
      ; int read(int fd, void *buf, size_t count);
      mov rdi, STDIN       ; primeiro parâmetro é o descritor de arquivo que será lido
      mov rsi, buffer      ; segundo parâmetro é o ponteiro para o buffer onde o conteúdo lido será armazenado
      mov rdx, 256         ; terceiro argumento é a quantidade de bytes a serem lidos
      mov rax, 0           ; número da syscall read
      syscall              ; chamada ao SO
                           ; ao término, rax terá a quantidade de caracteres lidos

      ; fazendo a conversão de letras minúsculas em maiúsculas:
      ; se o código ASCII do caracter está entre 'a' e 'z', subtrai de
      ; 32 (0x20) para chegar no equivalente em maiúsculo (man ascii ajuda)
      mov rcx, 0           ; inicializa o contador
loop: mov bl, [buffer+rcx] ; O caracter lido vai estar em buffer[ecx] (1 caractere ASCII = 1 byte)
      cmp bl, 'a'
      jl  prox             ; se o caracter é menor que 'a', lê o próximo
      cmp bl, 'z'        
      jg  prox             ; se o caractere é maior que 'z', lê o próximo
      sub bl, 0x20         ; transforma minúscula em maiúscula
      mov [buffer+rcx],bl  ; atualiza o buffer colocando a maiúscula no lugar

prox: inc rcx              ; avança o contador
      cmp rcx,rax
      jl  loop             ; lembrando que em eax tem o número de
                           ; caracteres. Logo, se ecx ainda é menor
                           ; que o número de caracteres, tem que
                           ; continuar no laço

      ; exibe o texto convertido na saida padrão (tela = stdout = 1)
      ; int write(int fd, const void *buf, size_t count);
      mov rdi, STDOUT      ; primeiro parâmetro é o descritor do arquivo que será escrito
      mov rsi, buffer      ; segundo parâmetro é o ponteiro para a mensagem que será escrita
      mov rdx, rax         ; terceiro parâmetro é o tamanho da mensagem (ainda está em eax)
      mov rax, 1           ; número da syscall write
      syscall              ; chamada ao SO

      ; finaliza a exeução e volta para o shell
      ; void exit(int status);
      mov rdi, 0           ; primeiro parâmetro: o cóigo de saída (0 = sucesso)
      mov rax, 60          ; numero da syscall exit
      syscall              ; chamada ao SO

section .data
; para ficar mais legível o código (melhor usar STDIN, STDOUT e STDERR do que 0, 1 e 2)
STDIN:  EQU 0
STDOUT: EQU 1
STDERR: EQU 2

section .bss
; o buffer onde a mensagem lida do arquivo será armazenada
buffer: resb 256
