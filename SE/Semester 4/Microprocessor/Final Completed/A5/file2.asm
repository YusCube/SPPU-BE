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


