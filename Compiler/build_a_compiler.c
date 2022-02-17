#include <stdio.h>
#include <string.h>

void removeComments(FILE *source, FILE *target, char sourceFileName[30], char targetFileName[30]) //for single & multiple line comments
{
    char c;
    int slashStart = 0;
    int checkForCommentStop = 0;
    int singleLineComment = 0;
    int multipleLineComment = 0;

    if(source == NULL || target == NULL){
        printf("\nFile cannot be opened");
    }
    else{
        while( (c = fgetc(source)) != EOF ){

            if(singleLineComment == 1){

                if(c == 10){
                    fputc(10,target);
                    singleLineComment = 0;
                    continue;
                }
            }

            else if(multipleLineComment == 1){

                if(c == '*'){
                    checkForCommentStop = 1;
                    continue;
                }


                if(checkForCommentStop == 1){

                    if(c == '/'){
                        multipleLineComment = 0;
                        continue;
                    }
                    else {
                        checkForCommentStop = 0;
                        continue;
                    }
                }
            }

            else if(singleLineComment == 0 && multipleLineComment == 0){
                if(c == '/' && slashStart == 0){
                    slashStart = 1;
                    continue;
                }

                else if(c == '/' && slashStart == 1){
                    slashStart = 0;
                    singleLineComment = 1;
                    continue;
                }

                else if(c == '*' && slashStart == 1){
                    slashStart = 0;
                    multipleLineComment = 1;
                    continue;
                }

                else if(c != '/' && slashStart == 1){
                    slashStart = 0;
                    fputc('/',target);
                    fputc(c,target);
                    continue;
                }

                else {
                    fputc(c,target);
                }
            }
        }
    }
    fclose(source);
    fclose(target);
}

void removeSpaces(FILE *source, FILE *target, char sourceFileName[30], char targetFileName[30]) //for removing extra spaces
{
    char c;
    int syntaxStart = 0;
    int syntaxSpace = 0;

    if(source == NULL || target == NULL)
    {
        printf("\nFile cannot be opened");
    }
    else
    {
        while( (c = fgetc(source)) != EOF )
        {
            //removing tab
            if(c == 9)
            {
                continue;
            }
            //removing new line
            else if(c == 10)
            {
                syntaxStart = 0;
                continue;
            }
            //removing extra space from the beginning of a syntax
            else if(c == 32 && syntaxStart == 0)
            {
                continue;
            }
            else
            {
                syntaxStart = 1;
            }

            //syntax started in that line
            if(syntaxStart = 1)
            {
                //allowing first space between syntaxes
                if(c == 32 && syntaxSpace == 0)
                {
                    fputc(32,target);
                    syntaxSpace = 1;
                    continue;
                }
                //removing more than 1 space between syntaxes
                else if(c == 32 && syntaxSpace == 1)
                {
                    continue;
                }
            }
            //normal character, no space tendency
            fputc(c,target);
            syntaxSpace = 0;
        }
    }
    fclose(source);
    fclose(target);
}
int main()
{

    FILE * fptr;
    char str[1000];

    printf("Write your code below \n");
    fptr = fopen("compiler_Asm2_Input.txt", "w");
    while (scanf("%c",&str) != EOF)
    {
        fgets(str, sizeof str, stdin);
        fputs(str, fptr);
    }
    fclose (fptr);

    char c;
    char sourceFileName[30] = "compiler_Asm2_Input.txt";
    char tempFileName[30] = "compiler_Asm2_O1.txt";
    char targetFileName[30] = "compiler_Asm2_O2.txt";
    char identifierFileName[30] = "compiler_Asm3_O1.txt";
    FILE *source, *target, *temp;

    source = fopen(sourceFileName, "r");
    temp = fopen(tempFileName, "w");
    removeComments(source, temp, sourceFileName, tempFileName);
    fclose(source);
    fclose(temp);

    temp = fopen(tempFileName, "r");
    target = fopen(targetFileName, "w");
    removeSpaces(temp, target, tempFileName, targetFileName);
    fclose(temp);
    fclose(target);

    printf("\n After removing space and comment \n");
    printf("\n");
    target = fopen (targetFileName,"r");
    while( (c = fgetc(target)) != EOF)
    {
        printf("%c",c);
    }
    fclose(target);

    printf("\n\n");

    return 0;
}
/*
#include <stdio.h>

int main() {

    int number1, number2, sum;

    printf("Enter two integers: ");
    scanf("%d %d", &number1, &number2);

    // calculating sum
    sum = number1 + number2;

    printf("%d + %d = %d", number1, number2, sum);
    return 0;
}
*/
