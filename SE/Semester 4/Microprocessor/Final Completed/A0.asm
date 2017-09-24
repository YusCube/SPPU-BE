section     .text
global      _start                           ;Must be declared for linker (ld)

_start:                                         ;Tell linker entry point

    mov     edx,len                             ;Message length
    mov     ecx,msg                             ;Message to write
    mov     ebx,1                               ;File descriptor (stdout)
    mov     eax,4                               ;System call number (sys_write)
    int     0x80                                ;Call kernel

    mov     eax,1                               ;System call number (sys_exit)
    int     0x80                                ;Call kernel

section     .data

msg     db  'Hello, world!',0xa                 ;Our dear string
len     equ $ - msg                             ;Length of our dear string

;OUTPUT
;bash-4.3$ cd MLA27
;bash-4.3$ nasm -f elf64 A0.asm
;bash-4.3$ ld -o  A0 A0.o
;bash-4.3$ ./A0
;Hello, world!
;bash-4.3$ 

