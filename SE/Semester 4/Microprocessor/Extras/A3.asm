%macro dispmsg 2
 	mov rax,04
 	mov ebx,01
 	mov ecx,%1
 	mov rdx,%2
 	int 80h
%endmacro
%macro accept 2
 	mov rax,03
 	mov ebx,0
 	mov ecx,%1
 	mov rdx,%2
 	int 80h
%endmacro

section .data
menumsg 		db 	10,10,'Code Conversion'
 			db	10,13,'1: Hex to BCD'
 			db	10,13,'2: BCD to Hex'
 			db 10,13,'3: Exit'
 			db	10,10,'Please Enter Choice::'
menumsg_len 		equ 	$-menumsg
wrchmsg 		db 	10,10,'Wrong Choice Entered',10,10
wrchmsg_len 		equ 	$-wrchmsg
hexinmsg 		db 	10,10,'Please enter 4 digit hex number::'
hexinmsg_len 		equ 	$-hexinmsg
bcdopmsg 		db 	10,10,'BCD Equivalent::'
bcdopmsg_len 	equ 	$-bcdopmsg
bcdinmsg 		db 	10,10,'Please enter 5 digit BCD number::'
bcdinmsg_len 		equ 	$-bcdinmsg
hexopmsg 		db 	10,10,'Hex Equivalent::'
hexopmsg_len 	equ 	$-hexopmsg

section .bss
numascii 	resb 	06 	;common buffer for choice, hex and bcd input
opbuff 		resb 	05
dnumbuff 	resb 	08

section .text
global _start
_start:
 		dispmsg menumsg,menumsg_len
 		accept numascii,2
 		cmp byte [numascii],'1'
 		jne case2
 		call hex2bcd_proc
 		jmp _start
case2: 		cmp byte [numascii],'2'
 		jne case3
 		call bcd2hex_proc
 		jmp _start
case3: 		cmp byte [numascii],'3'
 		je exit
 		jmp _start
exit:		mov rax,1
 		mov ebx,0
 		int 80h

hex2bcd_proc:
 		dispmsg hexinmsg,hexinmsg_len
 		accept numascii,5
 		call packnum
 		mov ecx,5
 		mov ax,bx
 		mov bx,10
h2bup1: 	mov dx,0
 		div bx
 		push rdx
 	 	loop h2bup1
 		mov edi,opbuff
 		mov ecx,5
h2bup2: 	pop rdx
 		add dl,30h
 		mov [edi],dl
 		inc edi
 		loop h2bup2
 		dispmsg bcdopmsg,bcdopmsg_len
 		dispmsg opbuff,5
 		ret
bcd2hex_proc:
 		dispmsg bcdinmsg,bcdinmsg_len
 		accept numascii,6
 		dispmsg hexopmsg,hexopmsg_len
 		mov esi,numascii
 		mov ecx,05
 		mov rax,0
 		mov ebx,0ah
b2hup1:	mov rdx,0
 		mul ebx
 		mov dl,[esi]
 		sub dl,30h
 		add rax,rdx
 		inc esi
 		loop b2hup1
 		mov ebx,rax
 		call disp32_num
 		ret
packnum:
 		mov bx,0
 		mov ecx,04
 		mov esi,numascii


up1:		rol bx,04
 		mov al,[esi]
 		cmp al,'9'
 		jbe sub30
 		cmp al,'F'
 		jbe sub37
 		cmp al,'f'
 		jbe sub57
sub57:		sub al,20h
sub37:		sub al,07h
sub30:		sub al,30h
 		add bl,al
 		inc esi
 		loop up1
 		ret

disp32_num:
 		mov edi,dnumbuff 		;point esi to buffer
 		mov ecx,08 								;load number of digits to display
dispup1:	rol ebx,4 			;rotate number left by four bits
 		mov dl,bl 									;move lower byte in dl
 		and dl,0fh 								;mask upper digit of byte in dl
 		add dl,30h 			     ;add 30h to calculate ASCII code
 		cmp dl,39h 			     ;compare with 39h
 		jbe dispskip1 			  ;if less than 39h skip adding 07 more
 		add dl,07h 			     ;else add 07
dispskip1:	mov [edi],dl 			;store ASCII code in buffer
 		inc edi 				       ;point to next byte
 		loop dispup1 			   ;decrement the count of digits to display
 						               ;if not zero jump to repeat
 		dispmsg dnumbuff+3,5
ret




;bash-4.3$ cd MLA27
;bash-4.3$ nasm -f elf64 A3.asm
;bash-4.3$ ld -o  A3 A3.o
;bash-4.3$ ./A3


;Code Conversion
;1: Hex to BCD
;2: BCD to Hex
;3: Exit

;Please Enter Choice::1


;Please enter 4 digit hex number::A8C9


;BCD Equivalent::43209

;Code Conversion
;1: Hex to BCD
;2: BCD to Hex
;3: Exit

;Please Enter Choice::2


;Please enter 5 digit BCD number::43209


;Hex Equivalent::0A8C9

;Code Conversion
;1: Hex to BCD
;2: BCD to Hex
;3: Exit

;Please Enter Choice::4


;Code Conversion
;1: Hex to BCD
;2: BCD to Hex
;3: Exit

;Please Enter Choice::1


;Please enter 4 digit hex number::EC42


;BCD Equivalent::60482

;Code Conversion
;1: Hex to BCD
;2: BCD to Hex
;3: Exit

;Please Enter Choice::2    


;Please enter 5 digit BCD number::33564


;Hex Equivalent::0831C

;Code Conversion
;1: Hex to BCD
;2: BCD to Hex
;3: Exit

;Please Enter Choice::3
;bash-4.3$ 


