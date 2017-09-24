section .data
msg1 db 10,'Enter Your Choice',10
msg1len equ $-msg1
msg2 db 10,'Menu', 10
msg2len equ $-msg2
msg3 db 10,'1. Non-Overlap block transfer without string instruction',10
msg3len equ $-msg3
msg4 db '2. Non-Overlap block transfer with string instruction',10
msg4len equ $-msg4
msg5 db '3. Overlap block transfer without string instruction(Positive Offset)',10
msg5len equ $-msg5
msg6 db '4. Overlap block transfer with string instruction(Positive Offset)',10
msg6len equ $-msg6
msg7 db '5. Overlap block transfer without string instruction(Negative Offset)',10
msg7len equ $-msg7
msg8 db '6. Overlap block transfer with string instruction(Negative Offset)',10
msg8len equ $-msg8
msg9 db 10,'Source:',10
msg9len equ $-msg9
msg0 db 10,'Destination:',10
msg0len equ $-msg0
msg10 db 10,'Do you wish to continue(1.Yes/2.No)?',10
msg10len equ $-msg10
src db 01h,02h,03h,04h,05h
dst times 7 db 00
section .bss
num resb 2
ans resb 2
arr resb 2
cnt resb 1
count resb 1
%macro disp 4
mov eax,%1
mov ebx,%2
mov ecx,%3
mov edx,%4
int 80h
%endmacro
section .text
global _start
_start:
beg:
disp 4,1,msg9,msg9len
mov byte[cnt],5
mov esi,src
det:
mov bl,[esi]
call disp_proc
inc esi
dec byte[cnt]
jnz det
disp 4,1,msg1,msg1len
disp 4,1,msg2,msg2len
disp 4,1,msg3,msg3len
disp 4,1,msg4,msg4len
disp 4,1,msg5,msg5len
disp 4,1,msg6,msg6len
disp 4,1,msg7,msg7len
disp 4,1,msg8,msg8len
disp 3,0,num,2
mov ah,[num]
cmp ah,31h
je no
cmp ah,32h
je nos
cmp ah,33h
je opos
cmp ah,34h
je ospos
cmp ah,35h
je oneg
cmp ah,36h
je osneg
con:
disp 4,1,msg10,msg10len
disp 3,0,ans,2
mov ah,[ans]
sub ah,30h
cmp ah,1
je beg
cmp ah,2
jae exit
exit:
mov eax,1
mov ebx,0
int 80h
no:
mov byte[cnt],5
mov esi,src
mov edi,dst
nxt:
mov al,[esi]
mov [edi],al
inc esi
inc edi
dec byte[cnt]
jnz nxt
disp 4,1,msg0,msg0len
mov byte[count],7
sub edi,05
print:
mov bl,[edi]
call disp_proc
inc edi
dec byte[count]
jnz print
jmp con
nos:
mov ecx,5
mov esi,src
mov edi,dst
cld
rep movsb
disp 4,1,msg0,msg0len
mov byte[count],7
sub edi,5
print2:
mov bl,[edi]
call disp_proc
inc edi
dec byte[count]
jnz print2
jmp con
opos:
mov byte[cnt],5
mov esi,src+4
mov edi,src+6
;add edi,2
nxt3:
mov al,[esi]
mov [edi],al
dec esi
dec edi
dec byte[cnt]
jnz nxt3
sub edi,1
disp 4,1,msg0,msg0len
mov byte[count],7
print3:
mov bl,[edi]
call disp_proc
inc edi
dec byte[count]
jnz print3
jmp con
ospos:
mov ecx,5
mov esi,src+4
mov edi,src+4
add edi,2
std
rep movsb
dec edi
disp 4,1,msg0,msg0len
mov byte[count],7
print4:
mov bl,[edi]
call disp_proc
inc edi
dec byte[count]
jnz print4
jmp con
oneg:
mov byte[cnt],5
mov esi,src
mov edi,src-2
;sub edi,2
nxt5:
mov al,[esi]
mov [edi],al
inc esi
inc edi
dec byte[cnt]
jnz nxt5
sub edi,5
disp 4,1,msg0,msg0len
mov byte[count],7
print5:
mov bl,[edi]
call disp_proc
inc edi
dec byte[count]
jnz print5
jmp con
osneg:
mov ecx,5
mov esi,src
mov edi,src
sub edi,2
cld
rep movsb
sub edi,5
disp 4,1,msg0,msg0len
mov byte[count],7
print6:
mov bl,[edi]
call disp_proc
inc edi
dec byte[count]
jnz print6
jmp con
disp_proc:
mov ecx,2
mov eax,arr
nxt_dgt:
rol bl, 4
mov dl, bl
and dl, 0Fh
cmp dl, 39h
jbe add30h_2
add dl, 07h
add30h_2:
add dl, 30h
mov [eax],dl
inc eax
loop nxt_dgt
disp 4,1,arr,2
ret


;OUTPUT
;bash-4.3$ cd MLA27
;bash-4.3$ nasm -f elf64 A2.asm
;bash-4.3$ ld -o  A2 A2.o
;bash-4.3$ ./A2
;
;Source:
;0102030405
;Enter Your Choice
;
;Menu
;
;1. Non-Overlap block transfer without string instruction
;2. Non-Overlap block transfer with string instruction
;3. Overlap block transfer without string instruction(Positive Offset)
;4. Overlap block transfer with string instruction(Positive Offset)
;5. Overlap block transfer without string instruction(Negative Offset)
;6. Overlap block transfer with string instruction(Negative Offset)
;1
;
;Destination:
;01020304050000
;Do you wish to continue(1.Yes/2.No)?
;1
;
;Source:
;0102030405
;Enter Your Choice
;
;Menu
;
;1. Non-Overlap block transfer without string instruction
;2. Non-Overlap block transfer with string instruction
;3. Overlap block transfer without string instruction(Positive Offset)
;4. Overlap block transfer with string instruction(Positive Offset)
;5. Overlap block transfer without string instruction(Negative Offset)
;6. Overlap block transfer with string instruction(Negative Offset)
;2
;
;Destination:
;01020304050000
;Do you wish to continue(1.Yes/2.No)?
;1
;
;Source:
;0102030405
;Enter Your Choice
;
;Menu
;
;1. Non-Overlap block transfer without string instruction
;2. Non-Overlap block transfer with string instruction
;3. Overlap block transfer without string instruction(Positive Offset)
;4. Overlap block transfer with string instruction(Positive Offset)
;5. Overlap block transfer without string instruction(Negative Offset)
;6. Overlap block transfer with string instruction(Negative Offset)
;3
;
;Destination:
;01020102030405
;Do you wish to continue(1.Yes/2.No)?
;1
;
;Source:
;0102010203
;Enter Your Choice
;
;Menu
;
;1. Non-Overlap block transfer without string instruction
;2. Non-Overlap block transfer with string instruction
;3. Overlap block transfer without string instruction(Positive Offset)
;4. Overlap block transfer with string instruction(Positive Offset)
;5. Overlap block transfer without string instruction(Negative Offset)
;6. Overlap block transfer with string instruction(Negative Offset)
;4
;
;Destination:
;01020102010203
;Do you wish to continue(1.Yes/2.No)?
;1
;
;Source:
;0102010201
;Enter Your Choice
;
;Menu
;
;1. Non-Overlap block transfer without string instruction
;2. Non-Overlap block transfer with string instruction
;3. Overlap block transfer without string instruction(Positive Offset)
;4. Overlap block transfer with string instruction(Positive Offset)
;5. Overlap block transfer without string instruction(Negative Offset)
;6. Overlap block transfer with string instruction(Negative Offset)
;5
;
;Destination:
;01020102010201
;Do you wish to continue(1.Yes/2.No)1
;
;Source:
;0102010201
;Enter Your Choice
;
;Menu
;
;1. Non-Overlap block transfer without string instruction
;2. Non-Overlap block transfer with string instruction
;3. Overlap block transfer without string instruction(Positive Offset)
;4. Overlap block transfer with string instruction(Positive Offset)
;5. Overlap block transfer without string instruction(Negative Offset)
;6. Overlap block transfer with string instruction(Negative Offset)
;6
;
;Destination:
;01020102010201
;Do you wish to continue(1.Yes/2.No)2
;bash-4.3$ 
