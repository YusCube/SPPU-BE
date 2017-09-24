;Write X86/64 ALP to perform multiplication of two 8-bit hexadecimal numbers.
;Use successive addition and add and shift method. Accept input from the user. (Use 
;of 64-bit registers is expected)

section .data
	msg		db	'Enter 2-digit hexadecimal number',10;
	msglen equ $-msg
	msg1		db	'The result of multiplication is:',10;
	msg1len	 equ	$-msg1
	menumsg 		db 	10,10,'Hex Multiplication'
 			db	10,13,'1: Successive addition'
 			db	10,13,'2: Add and shift method'
 			db 	10,13,'3: Exit'
 			db	10,10,'Please Enter Choice::'
	menumsg_len 		equ 	$-menumsg
	newline	db	10

section .bss
 	num	resb	03
 	num1	resb	01
 	result	resb	04
 	choice	resb	2

%macro dispmsg 2
 	mov rax,1
 	mov rdi,1
 	mov rsi,%1
 	mov rdx,%2
 	syscall
%endmacro

%macro accept 2
 	mov rax,0
 	mov rdi,0
 	mov rsi,%1
 	mov rdx,%2
 	syscall
%endmacro

section .text
global _start
_start:
 		mov rax,0
 		mov rbx,0
 		mov rcx,0
 		mov rdx,0
 		mov byte[num],0
 		mov byte[num1],0
 		mov byte[result],0
 		dispmsg menumsg,menumsg_len
 		accept choice,2
 		cmp byte[choice],'1'
 		jne case1
 		call Suc_add
 		dispmsg newline,1
 		jmp _start
	case1:		cmp byte[choice],'2'
	 		jne case2
	 		call Add_shift
	 		dispmsg newline,1
	 		jmp _start
	case2:		cmp byte[choice],'3'
	 		jne case3
	 		mov rax,60
	 		mov rdi,0
	 		syscall

	case3:		dispmsg menumsg,menumsg_len
	 		jmp _start
	
	ascii_hex:
			mov rcx,02
			mov rbx,0
	 		mov rax,0
	 		mov rsi,num
	up:		rol bl,4
	 		mov al,[rsi]
	 		cmp al,39h
	 		jbe skip
	 		sub al,7h
	skip:		sub al,30h
	 		add al,bl
	 		mov bl,al
	 		inc rsi
	 		loop up
	 		ret
disp_proc:
 		mov rcx,4
 		mov rdi,result
	up2:		rol bx,4
	 		mov al,bl
	 		and al,0fh
	 		cmp al,09h
	 		jg skip1
	 		add al,30h
	 		jmp label
	skip1:		add al,37h
	label:		mov [rdi],al
	 		inc rdi
	 		loop up2
	 		dispmsg result,4
	 		ret
	Suc_add:
	 		dispmsg msg,msglen
 			accept num,3
 			call ascii_hex
 			mov [num1],bl
 			dispmsg msg,msglen
 			accept num,3
 			call ascii_hex
 			mov rcx,0
 			mov rax,0
 			mov rax,[num1]
	repeat:		add rcx,rax
 			dec bl
 			jnz repeat
 			mov [result],rcx
 			dispmsg msg1,msg1len
 			mov rbx,[result]
 			call disp_proc
 			ret
	Add_shift:
 			dispmsg msg,msglen
 			accept num,3
 			call ascii_hex
			mov [num1],bl
 			dispmsg msg,msglen
 			accept num,3
	 		call ascii_hex
	 		mov [num],bl
	 		mov rbx,0
	 		mov rcx,0
	 		mov rdx,0
	 		mov rax,0
	 		mov dl,08
	 		mov al,[num1]
	 		mov bl,[num]
	up3:		shr bx,01
	 		jnc label1
	 		add cx,ax
	label1:		shl ax,01
	 		dec dl
	 		jnz up3
	 		mov [result],rcx
	 		dispmsg msg1,msg1len
	 		mov rbx,[result]
	 		call disp_proc
	 		ret	
	 		
	 		
	 		
	 		
	 		
	 		
