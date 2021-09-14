.MODEL SMALL
.STACK 100H
.DATA

MSG1 DB "ENTER TWO CAPITAL LATTER $"
MSG2 DB 10,13,"THE ALPHABATIC ORDER IS $" 


.CODE 

MAIN PROC
    
    MOV AX,@DATA
    MOV DS,AX  
    
    MOV AH,9
    LEA DX,MSG1
    INT 21H   
    
    
    START:
    
    MOV AH,1
    INT 21H
    MOV CL,AL
    INT 21H
    MOV CH,AL 
    
    CMP CL,CH
    JGE L1 
    
    CMP CH,CL
    JMP L2 
             
             
    L1:  
    
    LEA DX,MSG2
    MOV AH,9
    INT 21H
    
    MOV AH,2
    INT 21H
    MOV DL,CH
    INT 21H
    MOV DL,CL 
    INT 21H  
    
    JMP EXIT     
    
    
    L2:
    
    LEA DX,MSG2
    MOV AH,9
    INT 21H
    
    MOV AH,2
    INT 21H
    MOV DL,CL
    INT 21H
    MOV DL,CH 
    INT 21H
               
               
    EXIT:
    MOV AH,4CH
    INT 21H
    
    MAIN ENDP
END MAIN

    
    
    
    
    
    
