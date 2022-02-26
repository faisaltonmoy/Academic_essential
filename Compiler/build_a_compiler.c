#include <stdio.h>
#include <string.h>
#include "TableManipulation.h"

int isDigit(char lex)
{
    if(lex >= '0' && lex <= '9'){
        return 1;
    }
    return 0;
}

int isNumerical(char *lex)
{
    int i, l, s;
    i=0;
    if(isdigit(lex[i]))
    {
        s=1;
        i++;
    }
    else if(lex[i]=='.')
    {
        s=2;
        i++;
    }
    else
        s=0;
    l=strlen(lex);
    if(s==1)
    {
        for(; i<l; i++)
        {
            if(isdigit(lex[i]))
                s=1;
            else if(lex[i]=='.')
            {
                s=2;
                i++;
                break;
            }
            else
            {
                s=0;
                break;
            }
        }
    }
    if(s==2)
    {
        if(isdigit(lex[i]))
        {
            s=3;
            i++;
        }
        else
            s=0;
    }
    if(s==3)
    {
        for(; i<l; i++)
        {
            if(isdigit(lex[i]))
                s=3;
            else
            {
                s=0;
                break;
            }
        }
    }
    if(s==3)
    {
        s=1;
    }
    return s;
}

int isSeparator(char *lex)
{
    int s = 0 ;

    if( strlen(lex) == 1 && (lex[0] == ';' || lex[0] == ',' || lex[0] == 39) )
    {
        s = 1;
    }
    return s;
}

int isParenthesis(char *lex)
{
    int s = 0 ;

    if( strlen(lex) == 1 && (lex[0] == '(' || lex[0] == ')' || lex[0] == '{' || lex[0] == '}' || lex[0] == '[' || lex[0] == ']') )
    {
        s = 1;
    }
    return s;
}

int isOperator(char *lex)
{
    int s = 0 ;

    if(strlen(lex) == 1)
    {
        if( lex[0] == '+' || lex[0] == '-' || lex[0] == '*' || lex[0] == '/' || lex[0] == '%' || lex[0] == '=' ||
                lex[0] == '<' || lex[0] == '>' || lex[0] == '!' || lex[0] == '&' || lex[0] == '|' || lex[0] == '~' || lex[0] == '^' )
        {
            s = 1;
        }
    }
    if(strlen(lex) == 2)
    {
        if( (lex[0] == '+' && lex[1] == '+') || (lex[0] == '-' && lex[1] == '-') || (lex[0] == '=' && lex[1] == '=') || (lex[0] == '!' && lex[1] == '=') ||
                (lex[0] == '|' && lex[1] == '|') || (lex[0] == '&' && lex[1] == '&') || (lex[0] == '>' && lex[1] == '=') || (lex[0] == '<' && lex[1] == '=') )
        {
            s = 1;
        }
    }
    return s;
}

int isIdentifier(char *lex)
{
    int s = 0 ;

    if((lex[0] >= 'a' && lex[0] <= 'z') || (lex[0] >= 'A' && lex[0] <= 'Z') || lex[0] == '_' )
    {
        s = 1;
    }

    if (s==0)
        return s ;
    else
    {
        int i;
        for ( i = 1 ; i<strlen(lex); i++)
        {
            if((lex[i] >= 'a' && lex[i] <= 'z') || (lex[i] >= 'A' && lex[i] <= 'Z') || lex[i] == '_' || (lex[i] >= '0' && lex[i] <= '9') )
            {
                continue;
            }
            else
            {
                s = 0;
            }
        }
    }
    return s ;
}

int isKeyword(char *lex)
{
    if(strcmp(lex , "int") == 0 || strcmp(lex , "double") == 0 || strcmp(lex , "float") == 0
       || strcmp(lex , "if") == 0 || strcmp(lex ,"else") == 0 || strcmp(lex , "char") == 0 || strcmp(lex , "include") == 0
       || strcmp(lex , "return") == 0 || strcmp(lex , "stdio.h") == 0 || strcmp(lex , "string.h") == 0 || strcmp(lex , "#") == 0
       || strcmp(lex , "void") == 0){
        return 1;
       }
       return 0;
}


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

void lexemeSeparator(FILE *source, FILE *target, char sourceFileName[30], char targetFileName[30]){
    char c;
    int lexemeStart = 0;
    char tempFileName[30] = "temp1.txt";
    FILE *temp;
    temp = fopen(tempFileName, "w");
    if(source == NULL || target == NULL || temp == NULL)
    {
        printf("\nFile cannot be opened");
    }
    else
    {
        while( (c = fgetc(source)) != EOF )
        {
            if(c == ' ')
            {
                fputc(c,temp);
                lexemeStart = 0;
                continue;
            }
            if(c != ' ' && lexemeStart == 0)
            {
                lexemeStart = 1;
            }
            if(lexemeStart == 1)
            {
                if(c == ';' || c == ',' || c == 39 || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '(' || c == ')')
                {
                    fputc(' ',temp);
                    fputc(c,temp);
                    lexemeStart = 0;

                    char cc = fgetc(source);
                    if (cc == '+' || cc == '-' )
                    {
                        fputc(cc,temp);
                        fputc(' ',temp);
                    }
                    else if (cc == ';')
                    {
                        fputc(' ',temp);
                        fputc(cc,temp);
                        fputc(' ',temp);
                    }
                    else
                    {
                        fputc(' ',temp);
                        fputc(cc,temp);
                    }
                    continue;
                }
                else if(c == '>' || c == '<' || c == '!' || c == '|' || c == '&' || c == '=')
                {
                    fputc(' ',temp);
                    fputc(c,temp);
                    lexemeStart = 0;

                    char cc = fgetc(source);
                    if (cc == '=' || cc == '|' || cc == '&')
                    {
                        fputc(cc,temp);
                        fputc(' ',temp);
                    }
                    else if (cc == 39)
                    {
                        fputc(' ',temp);
                        fputc(cc,temp);
                        fputc(' ',temp);
                    }
                    else
                    {
                        fputc(' ',temp);
                        fputc(cc,temp);
                    }
                    continue;
                }
                fputc(c,temp);
            }
        }
    }
    fputc(' ',temp);
    fclose(source);
    fclose(temp);

    int syntaxSpace = 0;
    int codeStart = 0;
    source = fopen(tempFileName, "r");

    while( (c = fgetc(source)) != EOF )
    {
        if(c == 32 && syntaxSpace == 0 && codeStart == 1)
        {
            fputc(32,target);
            syntaxSpace = 1;
            continue;
        }
        else if(c == 32 && syntaxSpace == 1 && codeStart == 1)
        {
            continue;
        }
        else if(c != 32)
        {
            fputc(c,target);
            codeStart = 1;
            syntaxSpace = 0;
        }
    }
    fclose(source);
    fclose(target);
    remove(tempFileName);
}

void lexemeTokenization(FILE *source, FILE *target, char sourceFileName[30], char targetFileName[30]){
    char c, lex[50];
    if(source == NULL || target == NULL)
    {
        printf("\nFile cannot be opened");
    }
    else
    {
        int i = 0;
        while( (c = fgetc(source)) != EOF )
        {
            if(c == ' ')
            {
                lex[i] = '\0';
                i=0;
                if(isSeparator(lex))
                {
                    fputs("[sep ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }
                else if(isParenthesis(lex))
                {
                    fputs("[par ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }
                else if(isOperator(lex))
                {
                    fputs("[op ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }
                else if(isNumerical(lex))
                {
                    fputs("[num ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }
                else if(isKeyword(lex))
                {
                    fputs("[kw ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }
                else if(isIdentifier(lex))
                {
                    fputs("[id ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }
                else
                {
                    fputs("[unkn ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }

                continue;
            }
            else
            {
                lex[i] = c;
                i++;
            }
        }
    }
    fclose(source);
    fclose(target);
}

void lexemeSimplify(FILE *source, FILE *target, char sourceFileName[30], char targetFileName[30]){
    char c;
    int bracketStarting = 0;

    if(source == NULL || target == NULL)
    {
        printf("\nFile cannot be opened");
    }
    else
    {
        fputc(' ',target);
        while( (c = fgetc(source)) != EOF)
        {
            if(bracketStarting == 0 && c == '[')
            {
                bracketStarting = 1;
                fputc('[',target);
                continue;
            }
            if(bracketStarting == 1)
            {
                if(c == 'i')
                {
                    c = fgetc(source);
                    if(c == 'd')
                    {
                        fputs("id ",target);
                        continue;
                    }
                }
                else if(c == ' ')
                {
                    bracketStarting = 0;
                    continue;
                }
            }
            else
            {
                fputc(c,target);
            }
        }
    }
    fclose(source);
    fclose(target);
}

void symbolTableGenerate(FILE *source, FILE *target, char sourceFileName[30], char targetFileName[30]){
    int count = 0;
    char c, str[100], name[100], dataType[100], scope[100], value[100];
    char previous[100], temp[100];
    CopyStringToArray(scope,"global");

    while( (c = fgetc(source)) != EOF){
        int i = 0;
        if(c=='['){
            while(1){
                c = fgetc(source);
                if(c==']')
                    break;
                str[i] = c;
                i++;
            }

            if(isDataType(str)){
               CopyStringToArray(dataType,str);
            }
            else if((str[0]=='i' && str[1]=='d' && str[2]==' ') && strlen(str)>3){
               CopyIdToArray(temp,str);

               if(Search(temp,scope) == -1 && strcmp(previous,"=")!=0 ){
                   Insert(sl,temp,"var",dataType, scope);
                   sl++;
               }
               else{
                   if(strcmp(previous,"=") == 0){
                      UpdateScope(name,temp,scope);
                   }
                   else if(strcmp(previous,"return") == 0){
                      UpdateScope(scope,temp,scope);
                   }
               }
               CopyIdToArray(name,str);
            }
            else if(isNumerical(str)){
               if(strcmp(previous, "=") == 0){
                   if(Search(name, scope) != -1){
                       InsertStringInTable(Search(name,scope), 5, str);
                   }
                   else if(Search(name,"global") != -1 ){
                       InsertStringInTable(Search(name,"global"), 5, str);
                   }
               }
               else if(strcmp(previous,"return") == 0){
                   if(Search(scope,"global") != -1)
                       InsertStringInTable(Search(scope,"global"), 5, str);
               }
               CopyStringToArray(value,str);
            }
            else if(strlen(str)==1){
                if(str[0]=='('){
                    if(previous[0]=='i' && previous[1]=='d' && previous[2]==' ' && strlen(previous)>3) {
                        if(count==0){
                            CopyStringToArray(scope,name);
                            UpdateId(name,"func","global");
                        }
                    }
                }
                else if(str[0]=='{'){
                    count++;
                }
                else if(str[0]=='}'){
                    count--;

                    if(count==0){
                        CopyStringToArray(scope,"global");
                    }
                }
            }

            CopyStringToArray(previous,str);
        }
        else{
            Delete(str);
            i = 0;
        }
    }
    DisplayTable();
    printTableInFile(target);
    fclose(source);
    fclose(target);
}

void modifiedTokenStream(FILE *source, FILE *target, char sourceFileName[30], char targetFileName[30]){
    int i, count = 0;
    char c, str[100], name[100], dataType[100], scope[100], value[100];
    char previous[100], temp[100];

    while( (c = fgetc(source)) != EOF){
        if(c=='['){
            while(1){
                c = fgetc(source);
                if(c==']')
                    break;
                str[i] = c; i++;
            }
            if((str[0]=='i' && str[1]=='d' && str[2]==' ') && strlen(str)>3){
                Delete(temp);
                CopyIdToArray(temp,str);
                fputs("[id",target);

                if(Search(temp,scope) != -1){
                    fprintf(target," %d", Search(temp, scope) + 1);
                }
                else{
                    fprintf(target," %d", Search(temp,"global") + 1);
                }

                fputc(']',target);
                CopyIdToArray(name,str);
            }

            else if(strlen(str)==1){
                if(str[0]=='('){

                    if(previous[0]=='i' && previous[1]=='d' && previous[2]==' ' && strlen(previous)>3){
                        if(count==0){
                            CopyStringToArray(scope,name);
                        }
                    }
                }
                else if(str[0]=='{'){
                    count++;
                }
                else if(str[0]=='}'){
                    count--;
                    if(count==0){
                        CopyStringToArray(scope,"global");
                    }
                }
                fputc('[',target);
                fputc(str[0],target);
                fputc(']',target);
            }
            else{
                fputc('[',target);
                fputs(str, target);
                fputc(']',target);
            }
            CopyStringToArray(previous,str);
        }
        else{
            fputc(c,target);
            Delete(str);
            i = 0;
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
    char targetFileName[30] = "compiler_Asm_O2.txt";
    char tempFileName1[30] = "compiler_Asm_O1.txt";
    char targetFileName1[30] = "compiler_Asm2_O2.txt";
    char identifierFileName[30] = "compiler_Asm3_O1.txt";
    char modilfyFileName[30] = "compiler_Asm3_O2.txt";
    char tableFileName[30] = "compiler_Asm3_T1.txt";
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

    source = fopen(targetFileName, "r");
    temp = fopen(tempFileName1, "w");
    lexemeSeparator(source, temp, targetFileName, tempFileName1);


    temp = fopen(tempFileName1, "r");
    target = fopen(targetFileName1, "w");
    lexemeTokenization(temp, target, tempFileName, targetFileName1);

    printf("\n After Tokenization \n");
    printf("\n");
    target = fopen (targetFileName1,"r");
    while( (c = fgetc(target)) != EOF)
    {
        printf("%c",c);
    }
    fclose(target);

    printf("\n\n");

    source = fopen(targetFileName1, "r");
    target = fopen(identifierFileName, "w");
    lexemeSimplify(source, target, targetFileName, identifierFileName);

    printf("\n Only Identifier \n");
    printf("\n");
    target = fopen (identifierFileName,"r");
    while( (c = fgetc(target)) != EOF)
    {
        printf("%c",c);
    }
    fclose(target);

    printf("\n\n");

    source = fopen(identifierFileName, "r");
    target = fopen(tableFileName, "w");
    symbolTableGenerate(source, target, targetFileName, identifierFileName);

    source = fopen(identifierFileName, "r");
    target = fopen(modilfyFileName, "w");
    modifiedTokenStream(source, target, targetFileName, identifierFileName);

    printf("\n Modified Token \n");
    printf("\n");
    target = fopen (modilfyFileName,"r");
    while( (c = fgetc(target)) != EOF)
    {
        printf("%c",c);
    }
    fclose(target);

    printf("\n\n");


    remove(tableFileName);

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
