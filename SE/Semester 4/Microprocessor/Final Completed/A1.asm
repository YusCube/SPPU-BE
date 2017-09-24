section .data
	welmsg db 10, 'Program to count Positive and Negative numbers in an array',10
	welmsg_len equ $-welmsg
	
	pmsg db 10, 'Count of positive numbers::'
	pmsg_len equ $-pmsg
	
	nmsg db 10, 'Count of negative numbers::'
	nmsg_len equ $-nmsg
	
	nwline db 10
	
	array dw 8505h,90ffh,0037h,81a8h,1a9fh,0adh,021ch,38fh
	arrcnt equ 8
	
	pcnt db 0
	ncnt db 0
	
section .bss
	dispbuff resb 4
	
%macro print 2
	mov rax, 1
	mov rdi, 1
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro

section .text
global _start
_start:
		print welmsg,welmsg_len
		
		mov esi,array
		mov ecx,arrcnt
		
up1:	bt word[esi],15
		jnc pnxt
		inc byte[ncnt]
		jmp pskip
		
pnxt: inc byte[pcnt]

pskip:	inc esi
			inc esi
			loop up1
			
			print pmsg,pmsg_len
			mov bl,[pcnt]
			call disp8num
			
			print nmsg,nmsg_len
			mov bl,[ncnt]
			call disp8num
			
			print nwline,1		;Newline char
			
			mov rax, 60			;Exit system call
			xor rdi, rdi
			syscall
			
disp8num:
			mov ecx,2		;Number digits to display
			mov edi,dispbuff;Temp buffer
dup1:		rol bl,4			;Rotate number from bl to get MS digit to LS digit
			mov al,bl		;Move rotated no to AL
			and al,0fh		;Mask upper digit
			cmp al,09		;Compare with 9
			jbe dskip		;If no below or equal to 9 go to add only 30h
			add al,07h		;Else first add 07h
dskip:	add al,30h		;Add 30h
			mov[edi],al		;Store ASCII code in temp buff
			inc edi			;Increment pointer to next location in temp buff
			loop dup1		;repeat till ecx becomes zero
			
			print dispbuff,2;display the value from temp buff
			ret				;return to calling program

;OUTPUTS

;OUTPUT 1-0505h,10ffh,8037h,81a8h,8a9fh,0adh,021ch,5f6h,99fh
;bash-4.3$ nasm -f elf64 A1.asm
;bash-4.3$ ld -o A1 A1.o
;bash-4.3$ ./A1

;Program to count Positive and Negative numbers in an array

;Count of positive numbers::06
;Count of negative numbers::03
;bash-4.3$ 


;OUTPUT 2-0505h,90ffh,0037h,81a8h,1a9fh,0adh,021ch,38fh,69ah
;bash-4.3$ nasm -f elf64 A1.asm
;bash-4.3$ ld -o A1 A1.o
;bash-4.3$ ./A1

;Program to count Positive and Negative numbers in an array

;Count of positive numbers::07
;Count of negative numbers::02
;bash-4.3$


;OUTPUT 3-0505h,90ffh,0037h,81a8h,1a9fh,0adh,021ch,38fh 
;bash-4.3$ nasm -f elf64 A1.asm
;bash-4.3$ ld -o A1 A1.o
;bash-4.3$ ./A1

;Program to count Positive and Negative numbers in an array

;Count of positive numbers::06
;Count of negative numbers::02
;bash-4.3$ 


;OUTPUT 4-8505h,90ffh,0037h,81a8h,1a9fh,0adh,021ch,38fh
;bash-4.3$ nasm -f elf64 A1.asm
;bash-4.3$ ld -o A1 A1.o
;bash-4.3$ ./A1

;Program to count Positive and Negative numbers in an array

;Count of positive numbers::05
;Count of negative numbers::03
;bash-4.3$ 

