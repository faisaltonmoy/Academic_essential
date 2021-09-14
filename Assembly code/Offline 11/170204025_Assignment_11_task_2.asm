.MODEL SMALL
.STACK 100H     
.DATA       

M1 DB 0AH,0DH,'Enter a string : ','$' 
M2 DB 0AH,0DH,'The resulting string is : ','$'
M3 DB 0AH,0DH,'Enter a decimal number S : ','$'
M4 DB 0AH,0DH,'Enter a decimal number N : ','$'


TEXT DB 100 DUP('$')

.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX 
    MOV ES,AX
        
    CLD     
    
    MOV AH,9 
    LEA DX,M1
    INT 21H    
             
    XOR CX,CX 
    
    MOV AH,1
    
    LEA SI,TEXT
    
    WHILE_: 
    INT 21H
    CMP AL,0DH
    JE END_WHILE
    
    MOV [SI], AL
    INC SI  
    INC CX       
                    
    JMP WHILE_
           
    END_WHILE:
    
    MOV AH,9
    LEA DX,M3
    INT 21H
    
    
    CALL INDEC  
    MOV BX,AX
    SUB BX,1
     
    MOV AH,9
    LEA DX,M4
    INT 21H
        
    CALL INDEC
    
    CALL NEWLINE
    
    
    
    LEA DI,TEXT
    ADD DI,BX     
    
    SUB CX,BX
    SUB CX,AX
  
    LEA SI,TEXT
    ADD SI,BX
    ADD SI,AX 
    
    REP MOVSB
        
    MOV [DI],'$'

    MOV AH,9 
    LEA DX,M2
    INT 21H
    LEA DX,TEXT
    INT 21H    
        
    MOV AH,4CH
    INT 21H
    MAIN ENDP       
    
    PROC NEWLINE
    
    PUSH AX
    PUSH DX
    
    MOV AH,2
    MOV DL,0DH
    INT 21H
            
    MOV DL,0AH
    INT 21H
    
    POP DX
    POP AX
    
    RET
    NEWLINE ENDP      
    
    
    INDEC PROC
	PUSH BX
	PUSH CX
	PUSH DX

	BEGIN:

	
	XOR BX,BX 
	XOR CX,CX
	MOV AH,1
	INT 21H

	REPEAT2:
	CMP AL,'0'
	JNGE NOT_DIGIT
	CMP AL,'9'
	JNLE NOT_DIGIT
	
	AND AX,000FH 
	PUSH AX
	MOV AX,10

	MUL BX
	POP BX
	ADD BX,AX
	MOV AH,1
	INT 21H

	CMP AL,0DH
	JNE REPEAT2
	MOV AX,BX

	EXIT:
	POP DX
	POP CX
	POP BX

	RET

	NOT_DIGIT:
	MOV AH,2
	MOV DL,0DH
	INT 21H
	MOV DL,0AH
	INT 21H
	JMP BEGIN

	RET
INDEC ENDP
      
    
END MAIN 
 
