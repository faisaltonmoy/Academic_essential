#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int check(char *str);

int main (){
    char str[50];
    printf("Input String : ");
    gets(str);
    if(check(str)){
        printf("String follows the pattern.\n");
    }
    else{
        printf("String does not follow the pattern.\n");
    }
    return 0 ;
}


int check(char *str){
    int state = 0;
    int i;
    for(i=0; i < strlen(str); i++)
    {
        if(state == 0 && (str[0] >= '0' && str[0] <= '9')){
            state = 1;
        }
        else if((state == 0 || state == 1) && (str[i] >= '0' && str[i] <= '9') ){
            state = 2;
        }
         else if((state == 0 ||state == 1 || state == 2) && (str[i] >= 'a' && str[i] <= 'z') ){
            state = 3;
        }
        else if(state == 3 && str[i] == '_' ){
            state = 4;
        }
        else if( state == 4 && (str[i] >= 'a' && str[i] <= 'z') ){
            state = 5;
        }
        else if((state == 5||state == 6) && (str[i] >= '0' && str[i] <= '9')){
            state=6;
        }
        else{
            return 0;
        }
    }
    if(state == 6)
        return 1;
    else
        return 0;
}
