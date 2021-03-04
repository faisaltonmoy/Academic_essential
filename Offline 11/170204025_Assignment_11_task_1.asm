DATA SEGMENT
    MSG1 DB 10,13,'ENTER STRING : $'
    MSG4 DB 10,13,'THE GIVEN STRING IS NOT A PALINDROME $' 
    MSG5 DB 10,13,'THE GIVEN STRING IS A PALINDROME $'
    MSG6 DB 10,13,'REVERSE STRING IS : $' 
    P1 LABEL BYTE
    M1 DB 0FFH
    L1 DB ?
    P11 DB 0FFH DUP ('$')
    P22 DB 0FFH DUP ('$')
DATA ENDS 
DISPLAY MACRO MSG
    MOV AH,9
    LEA DX,MSG
    INT 21H
ENDM   
CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
START:
        MOV AX,DATA
        MOV DS,AX                
               
        DISPLAY MSG1
       
        LEA DX,P1
        MOV AH,0AH    
        INT 21H
       
        DISPLAY MSG6
               
        LEA SI,P11
        LEA DI,P22
       
        MOV DL,L1
        DEC DL
        MOV DH,0
        ADD SI,DX
        MOV CL,L1
        MOV CH,0
       
REVERSE:
        MOV AL,[SI]
        MOV [DI],AL
        INC DI
        DEC SI
        LOOP REVERSE
       
        DISPLAY P22
                      
        LEA SI,P11
        LEA DI,P22   
       
        MOV CL,L1
        MOV CH,0
       
CHECK:
        MOV AL,[SI]
        CMP [DI],AL
        JNE NOTPALIN
        INC DI
        INC SI
        LOOP CHECK
     
       
        DISPLAY MSG5
        JMP EXIT
NOTPALIN:
        DISPLAY MSG4
               
EXIT:   MOV AH,4CH
        INT 21H
CODE ENDS
END START