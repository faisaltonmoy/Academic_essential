.MODEL SMALL
.STACK 100H
.DATA

IN1 DB 'FIRST INPUT: $'
IN2 DB 'SECOND INPUT: $'
OUT1 DB 'FIRST NUMBER IS: $'
OUT2 DB 'SECOND NUMBER IS: $'
SUM DB 'SUM IS: $'

.CODE  

MAIN PROC 
    
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,9
    LEA DX,IN1
    INT 21H
    
    MOV AH,1
    INT 21H
    MOV BL,AL 
    
    MOV AH,2
    MOV DL,10
    INT 21H  
    MOV DL,13
    INT 21H 
    
    MOV AH,9
    LEA DX,IN2
    INT 21H
    
    MOV AH,1
    INT 21H
    MOV BH,AL 
    
    MOV AH,2
    MOV DL,10
    INT 21H  
    MOV DL,13
    INT 21H
    
    MOV AH,9
    LEA DX,OUT1
    INT 21H 
    
    MOV AH,2
    MOV DL,BL
    INT 21H 
    
    MOV AH,2
    MOV DL,10
    INT 21H  
    MOV DL,13
    INT 21H
    
    MOV AH,9
    LEA DX,OUT2
    INT 21H 
    
    MOV AH,2
    MOV DL,BH
    INT 21H
                        
    MOV AH,2
    MOV DL,10
    INT 21H  
    MOV DL,13
    INT 21H 
    
    ADD BL,BH 
    SUB BL,30H
      
    MOV AH,9
    LEA DX,SUM
    INT 21H 
    
    MOV AH,2
    MOV DL,BL
    INT 21H
    
    
    EXIT:
    MOV AH,4CH
    INT 21H
    MAIN ENDP

END MAIN