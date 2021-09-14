.MODEL SMALL
.STACK 100H
.CODE

MAIN PROC
    
    MOV CX,5
    LVL1:
    MOV BX,CX
    
    LVL2:
    MOV AH,2
    MOV DL,'*'
    INT 21H
    LOOP LVL2
    
    MOV AH,2
    MOV DL,10
    INT 21H
    MOV DL,13
    INT 21H
    
    MOV CX,BX
    LOOP LVL1
    
    EXIT:
    MOV AH,4CH
    INT 21H  
    MAIN ENDP
    
END MAIN