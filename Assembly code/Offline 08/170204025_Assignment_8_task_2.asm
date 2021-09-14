.MODEL SMALL
.STACK 100H
.DATA
   A1 DB  0DH,0AH,'ENTER AN ALGEBRIC EXPRESSION : ',0DH,0AH,'$'
   C1 DB  0DH,0AH,'EXPRESSION IS CORRECT $'
   LB DB  0DH,0AH,'TOO MANY LEFT BRACKETS.BEGIN AGAIN $'
   RB DB  0DH,0AH,'TOO MANY RIGHT BRACKETS.BEGIN AGAIN $'
   M1 DB  0DH,0AH,'BRACKETS MISMATCH.BEGIN AGAIN $'
   C2 DB  0DH,0AH,'TYPE Y IF U WANT TO CONTINUE : $'
              
.CODE
    MAIN PROC
        MOV AX, @DATA              
        MOV DS, AX

        START:                      

        LEA DX, A1               
        MOV AH, 9
        INT 21H

        XOR CX, CX                  

        MOV AH, 1                   

        INPUT:                      
        INT 21H                    

        CMP AL, 0DH            
        JE END_INPUT         

        CMP AL, "["              
        JE BRACKET         

        CMP AL, "{"          
        JE BRACKET         

        CMP AL, "("             
        JE BRACKET          

        CMP AL, ")"        
        JE PARENTHESES        
                                   
        CMP AL, "}"      
        JE CURLY          

        CMP AL, "]"               
        JE SQUARE        

        JMP INPUT                

        BRACKET:             

        PUSH AX                 
        INC CX                  
        JMP INPUT               

        PARENTHESES:            

        POP DX                     
        DEC CX                     
        CMP CX, 0        
        JL R_B         

        CMP DL, "("              
        JNE MISMATCH              
        JMP INPUT                 
       
        CURLY:            

        POP DX                     
        DEC CX                    

        CMP CX, 0                 
        JL R_B        

        CMP DL, "{"                
        JNE MISMATCH              
        JMP INPUT                 

        SQUARE:        
                                   
        POP DX                     
        DEC CX                   

        CMP CX, 0           
        JL R_B         

        CMP DL, "["             
        JNE MISMATCH          
        JMP INPUT             

        END_INPUT:               

        CMP CX, 0              
        JNE L_B           

        MOV AH, 9    

        LEA DX, C1        
        INT 21H                      

        LEA DX, C2       
        INT 21H                       

        MOV AH, 1             
        INT 21H                   

        CMP AL, "Y"                
        JNE EXIT                  
        JMP START                   

        MISMATCH:                   

        LEA DX, M1             
        MOV AH, 9                     
        INT 21H

        JMP START                  

        L_B:              

        LEA DX, LB        
        MOV AH, 9
        INT 21H

        JMP START                   

        R_B:             

        LEA DX, RB      
        MOV AH, 9
        INT 21H

        JMP START                  

        EXIT:                    

        MOV AH, 4CH                 
        INT 21H
    MAIN ENDP
END MAIN