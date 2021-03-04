.MODEL SMALL
.STACK 100H
.DATA

MSG1 DB 10,13,'ENTER HEX NUMBER (0-F): $'  
MSG2 DB 10,13,'THE DECIMAL NUMBER IS: '
MSG3 DB ?,'$'
MSG4 DB 10,13,'DO U WANT TO CHECK AGAIN? (Y/N) $'
MSG5 DB 10,13,'ERROR INPUT $'   
MSG6 DB 10,13,'THE DECIMAL NUMBER IS: 1'
MSG7 DB ?,'$'


.CODE

MAIN PROC
    
    MOV AX,@DATA
    MOV DS,AX  
    
    START:  MOV AH,9
            LEA DX,MSG1
            INT 21H                                
           
    
    CMP1:   MOV AH,1
            INT 21H
            
            CMP AL,'0'
            JL CMP2
            CMP AL,'9'
            JG CMP2
            
            MOV MSG3,AL
            MOV AH,9
            LEA DX,MSG2
            INT 21H 
            
    
    AGAIN:  MOV AH,9
            LEA DX,MSG4
            INT 21H
            
            MOV AH,1
            INT 21H
            CMP AL,'Y'
            JE START
            CMP AL,'y'
            JE START
            
            JMP EXIT
   
   
    CMP2:   CMP AL,'A'
            JL  ERROR
            CMP AL,'F'
            JG  ERROR
            SUB AL,11H 
            
            MOV MSG7,AL
            MOV AH,9
            LEA DX,MSG6
            INT 21H
            
            JMP AGAIN  
            
    
    ERROR:  MOV AH,9
            LEA DX,MSG5
            INT 21H
            JMP AGAIN
    
    
    EXIT:   MOV AH,4CH
            INT 21H 
    
    
    MAIN ENDP
END MAIN
    
    

