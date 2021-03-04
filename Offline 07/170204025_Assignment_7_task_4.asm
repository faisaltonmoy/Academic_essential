
.MODEL SMALL
.STACK 100H
.DATA               

A1 DB 0AH,'ENTER A DECIMAL DIGIT STRING :$'
A2 DB 0AH,'THE SUM OF THE DIGIT IN HEX IS $'        

COUNT DB 4

.CODE
    MAIN PROC
        MOV AX,@DATA 
        MOV DS,AX
        MOV AH,9 
        LEA DX,A1
        INT 21H

        CALL READ
        MOV AH,9
        LEA DX,A2
        INT 21H

        CALL SHOW
        MOV AH,4CH 
        INT 21
    MAIN ENDP

    READ PROC 
        XOR BX,BX
        
        WHILE_: 
        MOV AH,1
        INT 21H
        CMP AL,0DH 
        JE END_W
        AND AL,0FH
        CBW 
        ADD BX,AX
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
        JMP SHOW1
       
        LETTER1:
        ADD DL,37H

        SHOW1: 
        MOV AH,2
        INT 21H
        
        ROL BX,CL
        DEC COUNT
        CMP COUNT,0
        JNE START
        RET
    SHOW ENDP
END MAIN