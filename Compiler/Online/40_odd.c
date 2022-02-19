/*
Write a C program that receives a string from the user and finds out whether that string follows a
given pattern or not. The pattern is: (I)*SA_dd+ where I=[a-z] and d=[0-9]
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isMatched1(char *str);

int main (){
    char str[50];
    printf("Input String : ");
    gets(str);
    if(isMatched(str)){
        printf("String follows the pattern.\n");
    }
    else{
        printf("String does not follow the pattern.\n");
    }

    return 0 ;
}


int isMatched(char *str){
    int state = 0;
    int i;
    for(i=0; i < strlen(str); i++)
    {
        if(state == 0 && (str[0] >= 'a' && str[0] <= 'z')){
            state = 1;
        }
        else if((state==1 || state==2) && (str[i] >= 'a' && str[i] <= 'z') ){
            state = 2;
        }
        else if((state == 0 || state==2) && str[i] == 'S' ){
            state = 3;
        }
        else if(state==3 && str[i] == 'A' ){
            state = 4;
        }
        else if( state==4 && str[i] == '_' ){
            state = 5;
        }
        else if(state==5 && (str[i] >= '0' && str[i] <= '9')){
            state=6;
        }
        else if((state==6||state==7) && (str[i] >= '0' && str[i] <= '9')){
            state=7;
        }
        else{
            return 0;
        }
    }
    if(state==7)
        return 1;
    else
        return 0;
}
