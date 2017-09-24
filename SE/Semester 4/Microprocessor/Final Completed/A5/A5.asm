;Assignment 5
;Write 8086 ALP to perform string manipulation. The strings to be accepted from the user is to be stored in data segment of program_l and write FAR PROCEDURES in code segment program_2 for following operations on the string:(a) Concatenation of two strings (b) Number of occurrences of a sub-string in the given string Use PUBLIC and EXTERN directive. Create .OBJ files of both the modules and link them to create an EXE file. 

;In this program create 3 files as follows
;1. file1.asm
;2. file2.asm
;3. macro.asm

;1. file1.asm
;--------------------------------------------------------------------------------------------
;Assignment Name :X86/64 Assembly language program (ALP) 
;String Manipulation : Concatenation of 2 strings &
;Find no. of occurrences of substring.
;Accept string from user.
;------------------------------------------------------------------------

extern    con_proc        ; [ FAR PROCRDURE 
extern    sub_proc        ;   USING EXTERN DIRECTIVE ]

global    str1,str1_size, str2, str2_size

%include    "macro.asm"
;------------------------------------------------------------------------
section .data
nline        	db    	10,10
    	nline_len:    	equ    	$-nline

    	msg        	db     	10,"MIL assignment 07 : String Manipulation"
            		db    	10,"---------------------------------------------------",10
    	msg_len:    	equ    	$-msg

    	s1msg        	db    	10,"Enter string 1    : "
    	s1msg_len:    	equ    	$-s1msg    
  
    	s2msg        	db    	10,"Enter string 2    : "
    	s2msg_len:    	equ    	$-s2msg    

    	menu        	db    	10,"-----------MENU-----------"
                		db    	10,"1.String Concatenation"
                  		db    	10,"2.No. of occurences of substring"
                  		db    	10,"3.Exit"
              		db    	10,"Enter choice    :  "
    	menu_len:    	equ    	$-menu

    	emsg        	db    	10,"INVALID CHOICE!!!!! Please try again! ",10
    	emsg_len:    	equ    	$-emsg
;---------------------------------------------------------------------------


section .bss
    	buf        	resb    	2
    	buf_len:    	equ    	$-buf
  	str1        	resb    	20    
  	str1_len:    	equ    	$-str1
  	str2        	resb    	20    
    	str2_len:    	equ    	$-str2
    	str1_size    	resw    	1
    	str2_size    	resw    	1
;--------------------------------------------------------------------------
section .text
    global _start
_start:
        		print    	msg, msg_len        		;assignment no. 
        		print    	s1msg, s1msg_len        
        		read     	str1, str1_len
        		dec    	eax
        		mov    	[str1_size], ax
        		print    	s2msg, s2msg_len        
        		read     	str2, str2_len
        		dec    	eax
        		mov    	[str2_size], ax
Disp_Menu:	print    	menu, menu_len        
        		read    	buf, 2
        		mov    al, [buf]    
        		sub	al, 30h
C1:      		cmp	al, 1
        		jne	C2
        		call    	con_proc
        		jmp	Disp_Menu
C2:      		cmp 	al,2
jne 	C3
call    	sub_proc
jmp	Disp_Menu
C3:    		cmp	al, 3
jne	err
exit
err:    		print    emsg, emsg_len
jmp	Disp_Menu
;-------------------------------------------------------------------------------- 
;2. file2.asm
;--------------------------------------------------------------------------------
section .data 
    	nline        	db    	10,10 
    	nline_len:    	equ    	$-nline 
    	cmsg        	db    	10,"The Concatenated String is    : " 
    	cmsg_len:    	equ    	$-cmsg 
    	ymsg        	db    	10,"The substring is Present.",10 
            		db    	10,"No. of occurences of substring    : " 
    	ymsg_len:    	equ    	$-ymsg 
    	nmsg        	db    	10,"The substring is not Present.",10 
            		db    	10,"No. of occurences of substring    : " 
    	nmsg_len:    	equ    	$-nmsg 
;---------------------------------------------------------------------------------

section .bss 
    	str3        	resb    	40 
    	str3_len:    	equ    	$-str3 
    	str3_size    	resw    	1 
   	sscount        	resw    	1 
    	cur_add        	resq    	1 
    	end_add  	resq    	1 
    	char_ans    	resb    	4 
;--------------------------------------------------------------------- 

extern str1,str1_size, str2, str2_size 
global con_proc, sub_proc 

%include    "macro.asm" 
;--------------------------------------------------------------------- 
section .text 
    global    _main 
_main: 
;    global    con_proc, sub_proc 

con_proc:                  ;STRING CONCATINATION PROCEDURE 
    		cld 
    		mov    	ecx,0 
    		mov    	cx,[str1_size] 
          		mov    	esi, str1        					; 1st string 
    		mov    	edi, str3        					; concatenated string 
    		rep     	movsb 
    		mov    	ecx,0 
    		mov    	cx,[str2_size] 
          		mov    	esi, str2        					; 2nd string 
    		rep     	movsb 
    		mov    	cx,[str1_size] 
    		add    	cx,[str2_size] 
    		mov    	[str3_size],cx 
    		print 	cmsg, cmsg_len 
    		print 	str3, str3_len 
    		ret 
;-------------------------------------------------------------------------------------------------------- 
sub_proc:                ;substring procedure 

    		mov    	esi, str1 
  		cld
   		mov    	[cur_add],esi        				; store starting address of string1 
    		mov    	ecx,esi            					; calculate end address of string1 
    		add    	cx, [str1_size] 
    		dec    	ecx 
    		mov    	[end_add],ecx 

back:    	mov    	edi, str2 
    		xor    	ecx, ecx 
    		mov    	cx, [str2_size] 
    		repe     	cmpsb 
    		jnz     	conti 
    		inc     	word[sscount] 
conti: 		inc     	word[cur_add] 
    		mov    	esi,[cur_add] 
    		cmp    	esi,[end_add] 
    		jbe     	back 
    		cmp     	word[sscount],00 
    		je     	no 
     		print   	ymsg, ymsg_len 
       		jmp     	last 
no:    		print  	nmsg, nmsg_len 
last: 		mov     ax,[sscount] 
         		call     display_16 
    		ret 
;-----------------------------------------------------------------------------------------------------------------------
display_16: 
    		mov 	esi,char_ans+3    		; load last byte address of char_ans in rsi 
    		mov    	ecx,4            			; number of digits  
cnt:    		mov   	edx,0            			; make rdx=0 (as in div instruction rdx:rax/rbx) 
    		mov  	ebx,16        			; divisor=16 for hex 
    		div     	ebx 
    		cmp     	dl, 09h        			; check for remainder in RDX 
    		jbe      	add30 
    		add      	dl, 07h  
add30: 		add     	dl, 30h        			; calculate ASCII code 
    		mov  	[esi],dl        			; store it in buffer 
    		dec     	esi            			; point to one byte back 
    		dec     	ecx            			; decrement count 
    		jnz     	cnt            			; if not zero repeat 
    		print 	char_ans, 4        		; display result on screen 
  		ret 
;------------------------------------------------------------------------------------------------------------------------------



;3. macro.asm

;------------------------------------------------------------------------------------ 
;macro.asm
;macros as per 64 bit conventions


%macro print 2
    	mov    	eax,4        					;print/write
    	mov    	ebx,1        					;stdout/screen
    	mov    	ecx,%1    					;msg
    	mov    	edx,%2    					;msg_len
    	int 80h
%endmacro

%macro read 2
    	mov    	eax,3        					;read
    	mov    	ebx,0        					;stdin/keyboard
    	mov    	ecx,%1    					;buf
    	mov    	edx,%2    					;buf_len
    	int 80h
%endmacro

%macro exit 0
    	print    	nline, nline_len
    	mov    eax, 1    					;exit
    	int 80h    
%endmacro
;----------------------------------------------------------------------------------------------------------------------


;Steps to run the program as follows

;[shivasaran@sss-ragemachine Nasm] nasm -f elf file1.asm
;[shivasaran@sss-ragemachine Nasm] nasm -f elf file2.asm
;[shivasaran@sss-ragemachine Nasm] ld -m elf_i386 -s -o file1 file1.o -o file2 file2.o
;[shivasaran@sss-ragemachine Nasm]$ ./file2

;Output - 

MIL assignment 07 : String Manipulation
---------------------------------------------------

Enter string 1    : Assassination

Enter string 2    : ss

-----------MENU-----------
1.String Concatenation
2.No. of occurences of substring
3.Exit
Enter choice    :  1

The Concatenated String is    : Assassinationss
-----------MENU-----------
1.String Concatenation
2.No. of occurences of substring
3.Exit
Enter choice    :  2

The substring is Present.

No. of occurences of substring    : 0002
-----------MENU-----------
1.String Concatenation
2.No. of occurences of substring
3.Exit
Enter choice    :  3


[shivasaran@sss-ragemachine Nasm]$ 



