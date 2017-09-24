;Assignment 12
;Write 80387 ALP to obtain:
;i)Mean
;ii)Variance
;iii)Standard Deviation. Also plot the histogram for the data set . The data elements are avaliable in a text file

;Program-
section .data
	welmsg		db 	10,"WELCOME TO 64 BIT PROGRAMMING"
	welmsg_len 	equ 	$-welmsg
	meanmsg		db 	10,"Calculated mean is:"
	meanmsg_len 	equ 	$-meanmsg
	sdmsg		db 	10,"Calculated Standard deviations is:"
	sdmsg_len 	equ 	$-sdmsg
	varmsg		db 	10,"Calculated variance is:"
	varmsg_len 	equ 	$-varmsg
	array 		dd 	100.26,210.21,21.67,235.78,27.93
	arraycnt	dw 	05
	dpoint 		dw	'.'
	hdec		dq	100

section .bss
	dispbuff 	resb	1
	resbuff		rest	1
	mean 		resd	1
	variance	resd 	1

%macro disp 2
	mov rax, 4
	mov rbx, 1
	mov rcx, %1
	mov rdx, %2
	int 80h
%endmacro

%macro accept 2
	mov rax, 3
	mov rbx, 0
	mov rcx, %1
	mov rdx, %2
	int 80h
%endmacro

section .text
global _start
_start:
		disp 	welmsg,welmsg_len
		finit
		fldz
		mov 	rbx,array
		mov 	rsi,00
		xor	rcx,rcx
		mov 	cx,[arraycnt]
	
up:
		fadd	dword[RBX+RSI*4]
		inc 	rsi
		loop 	up
		fidiv 	word[arraycnt]
		fst	dword[mean]
		disp	meanmsg,meanmsg_len
		call 	dispres
		MOV 	RCX,00
		MOV	CX,[arraycnt]
		MOV	RBX,array
		MOV	RSI,00
		FLDZ

up1:
		FLDZ	
		FLD	DWORD[RBX+RSI*4]
		FSUB 	DWORD[mean]
		FST 	ST1
		FMUL
		FADD
		INC	RSI
		LOOP	up1
		FIDIV	word[arraycnt]
		FST	dWORD[variance]
		FSQRT
		disp	sdmsg,sdmsg_len
		CALL	dispres
		FLD	dWORD[variance]
		disp	varmsg,varmsg_len
		CALL 	dispres

exit:
		mov 	rax,60
		mov 	rdi,0
		int 	80h
	
disp8_proc:
		mov	rdi,dispbuff
		mov	rcx,02
		back:	rol	bl,04
		mov	dl,bl
		and	dl,0FH
		cmp	dl,09
		jbe	next1
		add	dl,07H
		next1:	add	dl,30H
		mov	[rdi],dl
		inc	rdi
		loop	back
		ret

dispres:
		fimul	dword[hdec]
		fbstp	tword[resbuff]
		xor	rcx,rcx
		mov	rcx,09H
		mov	rsi,resbuff+9
		
up2:
		push	rcx
		push	rsi
		mov	bl,[rsi]
		call 	disp8_proc
		disp	dispbuff,2
		pop	rsi
		dec	rsi
		pop	rcx
		loop	up2
		disp	dpoint,1
		mov	bl,[resbuff]
		call	disp8_proc
		disp	dispbuff,2
		ret	
		
		
;Output - 
;[shivasaran@sss-ragemachine Final]$ nasm -f elf64 A12.asm
;[shivasaran@sss-ragemachine Final]$ ld -o A12 A12.o
;[shivasaran@sss-ragemachine Final]$ ./A12
;
;WELCOME TO 64 BIT PROGRAMMING
;Calculated mean is:000000000000000119.39
;Calculated Standard deviations is:000000000000000089.39
;Calculated variance is:000000000000008014.34
;[shivasaran@sss-ragemachine Final]$ 

