.MODEL SMALL
.STACK 100H
.DATA      

A1 DB 0AH,'TYPE A HEXA NUMBER 0 -FFFF :$'
A2 DB 0AH,'THE SUM IN HEXA IS $'

COUNT DB 4
NUM DW ?        

.CODE
    MAIN PROC
        MOV AX,@DATA 
        MOV DS,AX
        MOV AH,9 
        LEA DX,A1
        INT 21H

        CALL READ
        MOV NUM,BX
        MOV AH,9 
        LEA DX,A1
        INT 21H
        
        CALL READ
        MOV AH,9 
        LEA DX,A2
        INT 21H
        ADD BX,NUM
        JC SHOW1 
        MOV AH,2 
        MOV DL,'0'
        INT 21H
        JMP NEXT
        
        SHOW1:
        MOV AH,2
        MOV DL,'1'
        INT 21H
       
        NEXT:
        CALL SHOW
        MOV AH,4CH 
        INT 21H
    MAIN ENDP 

    READ PROC 
        XOR BX,BX
        MOV CL,4
        MOV AH,1
        INT 21H
        
        WHILE_:
        CMP AL,0DH
        JE END_W
        CMP AL,'9' 
        JG LETTER
        AND AL,0FH
        JMP SHIFT

        LETTER:
        SUB AL,37H
        
        SHIFT:
        SHL BX,CL
        OR BL,AL
        INT 21H
        JMP WHILE_
        
        END_W: 
        RET
    READ ENDP

    SHOW PROC 
        MOV CL,4
        
        START:
        MOV DL,BH
        SHR DL,CL
        CMP DL,9
        JG LETTER1
        ADD DL,30H
        JMP SHOW2

        LETTER1:
        ADD DL,37H    
        
        SHOW2: 
        MOV AH,2
        INT 21H
        ROL BX,CL
        DEC COUNT
        CMP COUNT,0
        JNE START
        RET
    SHOW ENDP
END MAIN