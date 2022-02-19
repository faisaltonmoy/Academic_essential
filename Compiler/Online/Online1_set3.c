/*
Write a C program that will scan an input file (c source code) and find out how many float
numbers are displayed in the console in that input program.
*/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

char user_input[1000000] ;
int right = 0;

void Read(char *fileName){
    FILE *fptr;
    char c;
    int i = 0;
    if ((fptr = fopen(fileName, "r")) == NULL) {
        printf("Error! opening file");
    }else{
        while((c = fgetc(fptr)) != EOF){
            user_input[i] = c;
            i++;
        }
    }
	fclose(fptr);
}

void Finder(char str[]){

    int found_val = 0;
    for(int i = 0 ; i < strlen(str); i++){
        if(str[i] == 'p'){
            found_val = i;
            break;
        }
    }

    int i = found_val;
    if(str[i] == 'p' && str[i + 1] == 'r' && str[i + 2] == 'i' && str[i + 3] == 'n' && str[i + 4] == 't' && str[i + 5] == 'f'){

        for(int i = found_val ; i < strlen(str); i++){
            if(str[i] == '%' && str[i + 1] == 'f'){
                right += 1;
            }
        }
    }

}
void raw(){

    int j = 0;
    int k = 0;
    for(int i = 0; i < strlen(user_input) ; i++ ){
        char b[1000000];
        if(user_input[i] != '\n' ){
            b[k] = user_input[i];
            k++;
        }
        else{
            b[k] ='\0';
            k = 0;
            Finder(b);
        }
    }
    printf("\nNo. of Float Numbers displayed: %d\n",right);
}
int main()
{

    Read("Task.c");
    raw();
    return 0;
}
