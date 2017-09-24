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



;Steps to run the program as follows

;$ nasm -f elf file1.asm
;$ nasm -f elf file2.asm
;$ ld -m elf_i386 -s -o file1 file1.o -o file2 file2.o
;$ ./file2

