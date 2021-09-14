.MODEL SMALL
.STACK 100H
.DATA

VAR1 DB 10,13,'*********** $'  
VAR2 DB 10,13,'*         * $'

.CODE

MAIN PROC
    
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,9
    LEA DX,VAR1 
    INT 21H
    
    MOV AH,9
    LEA DX,VAR2
    INT 21H
    INT 21H
    INT 21H
    INT 21H
    INT 21H 
    
    MOV AH,9
    LEA DX,VAR1 
    INT 21H
         
    EXIT:
    MOV AH,4CH
    INT 21
    MAIN ENDP
END MAIN