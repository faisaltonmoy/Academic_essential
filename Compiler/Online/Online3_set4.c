#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "TableManipulation.h"

char input[1000000] ;
char readVval[1000000] ;

void fileRead(char *fileName){
    FILE *fptr;
    char c;
    int i = 0;
    if ((fptr = fopen(fileName, "r")) == NULL) {
        printf("Error! opening file");
    }else{
        while((c = fgetc(fptr)) != EOF){
            input[i] = c;
            i++;
        }
    }
	fclose(fptr);
}

void fileReadSym(char *fileName){
    FILE *fptr;
    char c;
    int i = 0;
    if ((fptr = fopen(fileName, "r")) == NULL) {
        printf("Error! opening file");
    }else{
        while((c = fgetc(fptr)) != EOF){
            readVval[i] = c;
            i++;
        }
    }
	fclose(fptr);
}


void changeOutput(){
    int i;
    for(i = 0 ; i < strlen(input) ;i++ ){
        if(input[i] == 'i' && input[i+1] == 'd'){
            while(input[i] != ']'){
                printf("%c",input[i]);
                i++;
            }
            printf("\n");
        }

    }
}



void printOutput(char str[]){
    printf("%s\n",str);
}

int main()
{
      FILE * fptr;
      char *x,*y;
    char str[1000];

    printf("Write your code below \n");
    fptr = fopen("temp.txt", "w");
    while (scanf("%c",&str) != EOF)
    {
        fscanf(stdin,"%c",x);
        fscanf(stdin,"%c",y);
    }
    fclose (fptr);
    fileReadSym("input_table.txt");
    printf("\n");
    printOutput(input);
    printf("\n");
    printOutput(readVval);
    changeOutput();


    return 0;
}
