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


