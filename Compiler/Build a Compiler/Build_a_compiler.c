#include <stdio.h>
#include "ErrorChecking.h"
#include "TableManipulation.h"

/// ///////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////ASSIGNMENT 01//////////////////////////////////////////
/// ///////////////////////////////////////////////////////////////////////////////////////////
void removeComments(FILE *source, FILE *target, char sourceFileName[30], char targetFileName[30]){
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
            //////////////////////////////////      single line comment started       ///////////////////////////////////
            if(singleLineComment == 1){
                //  stop when new line appears
                if(c == 10){
                    fputc(10,target);
                    singleLineComment = 0;
                    continue;
                }
            }
            ///////////////////////////////////     multi line comment started        ////////////////////////////////////
            else if(multipleLineComment == 1){
                //  ending star
                if(c == '*'){
                    checkForCommentStop = 1;
                    continue;
                }

                //  after getting star in multi line comment
                if(checkForCommentStop == 1){
                    //  comment ends after getting slash
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
            /////////////////////////////////       Checking for comment          ///////////////////////////////////////
            else if(singleLineComment == 0 && multipleLineComment == 0){
                if(c == '/' && slashStart == 0){
                    slashStart = 1;
                    continue;
                }
                //for single line
                else if(c == '/' && slashStart == 1){
                    slashStart = 0;
                    singleLineComment = 1;
                    continue;
                }
                //for multi line
                else if(c == '*' && slashStart == 1){
                    slashStart = 0;
                    multipleLineComment = 1;
                    continue;
                }
                //one slash, means there might be division sign
                else if(c != '/' && slashStart == 1){
                    slashStart = 0;
                    fputc('/',target);
                    fputc(c,target);
                    continue;
                }
                //normal character, no comment possibility
                else {
                    fputc(c,target);
                }
            }
        }
    }
    fclose(source);
    fclose(target);
}

void removeSpaces(FILE *source, FILE *target, char sourceFileName[30], char targetFileName[30]){
    char c;
    int syntaxStart = 0;
    int syntaxSpace = 0;

    char tempFileName[30] = "170204025_temp.txt";
    FILE *temp;
    temp = fopen(tempFileName, "w");

    if(source == NULL || temp == NULL){
        printf("\nFile cannot be opened");
    }
    else{
        while( (c = fgetc(source)) != EOF ){
            //removing tab
            if(c == 9){
                fputc(32,temp);
                continue;
            }
            //removing extra space from the beginning of a syntax
            else if(c == 32 && syntaxStart == 0){
                continue;
            }
            else{
                syntaxStart = 1;
            }

            //syntax started in that line
            if(syntaxStart = 1){
                //allowing first space between syntaxes
                if(c == 32 && syntaxSpace == 0){
                    fputc(32,temp);
                    syntaxSpace = 1;
                    continue;
                }
                //removing more than 1 space between syntaxes
                else if(c == 32 && syntaxSpace == 1){
                    continue;
                }
            }
            //normal character, no space tendency
            fputc(c,temp);
            syntaxSpace = 0;
        }
    }
    fputc(' ',temp);
    fclose(source);
    fclose(temp);

    //Removing more than one spaces (because of replacing tabs with spaces)
    syntaxSpace = 0;
    int codeStart = 0;
    source = fopen(tempFileName, "r");

    while( (c = fgetc(source)) != EOF ){
        if(c == 10){
            fputc(c,target);
            codeStart = 0;  //setting codestart variable to zero after getting new line
            continue;
        }
        else if(c == 32 && syntaxSpace == 0 && codeStart == 1){          //one space between syntaxes
            fputc(32,target);
            syntaxSpace = 1;
            continue;
        }
        else if(c == 32 && syntaxSpace == 1 && codeStart == 1){     //more than one space between syntaxes
            continue;
        }
        else if(c != 32){                                           //any character other than space
            fputc(c,target);
            codeStart = 1;
            syntaxSpace = 0;
        }
    }

    fclose(source);
    fclose(target);
    remove(tempFileName);
}

/// ///////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////ASSIGNMENT 02//////////////////////////////////////////
/// ///////////////////////////////////////////////////////////////////////////////////////////
void lexemeSeparator(FILE *source, FILE *target, char sourceFileName[30], char targetFileName[30]){
    char c;
    int lexemeStart = 0;
    char tempFileName[30] = "temp1.txt";
    FILE *temp;
    temp = fopen(tempFileName, "w");

    if(source == NULL || target == NULL || temp == NULL){
        printf("\nFile cannot be opened");
    }

    else{
        while( (c = fgetc(source)) != EOF ){
            if(c == 10){	//new line
                fputc(c,temp);
                continue;
            }

			if(c == ' '){
                fputc(c,temp);
                lexemeStart = 0;
                continue;
            }

            if(c != ' ' && lexemeStart == 0){
                lexemeStart = 1;
            }

            if(lexemeStart == 1){
                if (c == '(' || c == ')' || c == '{' || c == '}'){
                    fputc(' ',temp);      //leading space of the lexeme
                    fputc(c,temp);
                    fputc(' ',temp);      //trailing space of the lexeme
                    lexemeStart = 0;
                    continue;
                }
                if(c == ';' || c == ',' || c == 39 || c == '+' || c == '-' || c == '*' || c == '/' || c == '%'){    //apostrophe ascii = 39
                    fputc(' ',temp);      //leading space of the lexeme
                    fputc(c,temp);
                    lexemeStart = 0;

                    char cc = fgetc(source);    //checking next character
                    if (cc == '+' || cc == '-' ){ //for  ++  --
                        fputc(cc,temp);
                        fputc(' ',temp);  //trailing space of the lexeme
                    }

                    else if (cc == ';'){  //semicolon after apostrophe
                        fputc(' ',temp);  //leading space of the lexeme
                        fputc(cc,temp);
                        fputc(' ',temp);  //trailing space of the lexeme
                    }

                    else{
                        fputc(' ',temp);  //leading space of the lexeme
                        fputc(cc,temp);
                    }

                    continue;
                }

                else if(c == '>' || c == '<' || c == '!' || c == '|' || c == '&' || c == '='){
                    fputc(' ',temp);      //leading space of the lexeme
                    fputc(c,temp);
                    lexemeStart = 0;

                    char cc = fgetc(source);    //checking next character
                    if (cc == '=' || cc == '|' || cc == '&'){   //for checking  >=  <=  !=  &&  ||
                        fputc(cc,temp);
                        fputc(' ',temp);  //trailing space of the lexeme
                    }

                    else if (cc == 39){     //apostrophe ASCII = 39
                        fputc(' ',temp);  //leading space of the lexeme
                        fputc(cc,temp);
                        fputc(' ',temp);  //trailing space of the lexeme
                    }

                    else{
                        fputc(' ',temp);  //leading space of the lexeme
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

    //Removing more than one spaces
    int syntaxSpace = 0;
    int lineStart = 0;
    lexemeStart = 0;
    source = fopen(tempFileName, "r");

    while( (c = fgetc(source)) != EOF ){
        if(c != 32 && c != 10){     //normal character other then space(32) and new line(10)
            fputc(c,target);
            lineStart = 1;
            syntaxSpace = 0;
        }

        else if(c == 10){
            fputc(c,target);
            lineStart = 0;
        }

        else if(c == 32 && syntaxSpace == 0 && lineStart == 1){          //one space between syntaxes
            fputc(32,target);
            syntaxSpace = 1;
        }

        else if(c == 32 && syntaxSpace == 1 && lineStart == 1){     //more than one space between syntaxes
            continue;
        }
    }
    fclose(source);
    fclose(target);
    remove(tempFileName);
}

void lexemeTokenization(FILE *source, FILE *target, char sourceFileName[30], char targetFileName[30]){
    char c, lex[50];
    if(source == NULL || target == NULL){
        printf("\nFile cannot be opened");
    }

    else{
        int i = 0;

        while( (c = fgetc(source)) != EOF ){
            if(c == 10){
                fputc(c, target);
                continue;
            }

            if(c == ' '){       //checking each lexeme separately and putting them in target file
                lex[i] = '\0';
                i=0;

                if(isSeparator(lex)){
                    fputs("[sep ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }

                else if(isParenthesis(lex)){
                    fputs("[par ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }

                else if(isBracket(lex)){
                    fputs("[brc ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }

                else if(isOperator(lex)){
                    fputs("[op ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }

                else if(isNumerical(lex)){
                    fputs("[num ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }

                else if(isKeyword(lex)){
                    fputs("[kw ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }

                else if(isIdentifier(lex)){
                    fputs("[id ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }

                else {
                    fputs("[unkn ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }

                continue;
            }
            else{
                lex[i] = c;
                i++;
            }
        }
    }
    fclose(source);
    fclose(target);
}

int isDigit(char *lex){
    if(lex >= '0' && lex <= '9'){
        return 1;
    }
    return 0;
}

int isNumerical(char *lex){
    int i, l, s;
    i=0;

    if(isdigit(lex[i])) {
        s=1; i++;
    }

    else if(lex[i]=='.') {
        s=2;
        i++;
    }

    else{
        s=0;
    }

    l=strlen(lex);

    if(s==1){
        for(;i<l;i++){
            if(isdigit(lex[i])){
                s=1;
            }

            else if(lex[i]=='.') {
                s=2;
                i++;
                break;
            }

            else {
                s=0;
                break;
            }
        }
    }

    if(s==2){
        if(isdigit(lex[i])) {
            s=3; i++;
        }

        else
            s=0;
    }

    if(s==3){
        for(;i<l;i++) {
            if(isdigit(lex[i])){
                s=3;
            }

            else {
                s=0;
                break;
            }
        }
    }

    if(s==3){
        s=1;
    }

    return s;
}

int isSeparator(char *lex){
    int s = 0 ;

    if( strlen(lex) == 1 && (lex[0] == ';' || lex[0] == ',' || lex[0] == 39) ){
        s = 1;
    }
   return s;
}

int isParenthesis(char *lex){
    int s = 0 ;

    if( strlen(lex) == 1 && (lex[0] == '{' || lex[0] == '}') ){
        s = 1;
    }
   return s;
}

int isBracket(char *lex){
    int s = 0 ;

    if( strlen(lex) == 1 && (lex[0] == '(' || lex[0] == ')' || lex[0] == '[' || lex[0] == ']') ){
        s = 1;
    }
   return s;
}

int isOperator(char *lex){
    int s = 0 ;

    if(strlen(lex) == 1){       //single operator
        if( lex[0] == '+' || lex[0] == '-' || lex[0] == '*' || lex[0] == '/' || lex[0] == '%' || lex[0] == '=' ||
           lex[0] == '<' || lex[0] == '>' || lex[0] == '!' || lex[0] == '&' || lex[0] == '|' || lex[0] == '~' || lex[0] == '^' ){
            s = 1;
        }
    }

    if(strlen(lex) == 2){       //double operator
        if( (lex[0] == '+' && lex[1] == '+') || (lex[0] == '-' && lex[1] == '-') || (lex[0] == '=' && lex[1] == '=') || (lex[0] == '!' && lex[1] == '=') ||
           (lex[0] == '|' && lex[1] == '|') || (lex[0] == '&' && lex[1] == '&') || (lex[0] == '>' && lex[1] == '=') || (lex[0] == '<' && lex[1] == '=') ){
            s = 1;
        }
    }
    return s;
}

int isIdentifier(char *lex){
    int s = 0 ;

    if((lex[0] >= 'a' && lex[0] <= 'z') || (lex[0] >= 'A' && lex[0] <= 'Z') || lex[0] == '_' ){
        s = 1;      //checking first character if it's valid or not (a-z) || (A-Z) || _
    }

    if (s==0){
        return s ;
    }

    else{
        int i;

        for ( i = 1 ; i<strlen(lex); i++){
            if((lex[i] >= 'a' && lex[i] <= 'z') || (lex[i] >= 'A' && lex[i] <= 'Z') || lex[i] == '_' || (lex[i] >= '0' && lex[i] <= '9') ){
                continue;
            }

            else{
                s = 0;
            }
        }
    }
    return s ;
}

int isKeyword(char *lex){
    int s = 0 ;

    if(lex[0] == 'i' && lex[1] == 'n' && lex[2] == 't' && lex[3] == '\0' ){
        s = 1;      //int
    }

    else if(lex[0] == 'c' && lex[1] == 'h' && lex[2] >= 'a' && lex[3] == 'r' && lex[4] == '\0' ){
        s = 1;      //char
    }

    else if(lex[0] == 'f' && lex[1] == 'l' && lex[2] >= 'o' && lex[3] == 'a' && lex[4] == 't' && lex[5] == '\0' ){
        s = 1;      //float
    }

    else if(lex[0] == 'd' && lex[1] == 'o' && lex[2] >= 'u' && lex[3] == 'b' && lex[4] == 'l' && lex[5] == 'e' && lex[6] == '\0' ){
        s = 1;      //double
    }

    else if(lex[0] == 'l' && lex[1] == 'o' && lex[2] >= 'n' && lex[3] == 'g' && lex[4] == '\0' ){
        s = 1;      //long
    }

    else if(lex[0] == 's' && lex[1] == 'h' && lex[2] >= 'o' && lex[3] == 'r' && lex[4] == 't' && lex[5] == '\0' ){
        s = 1;      //short
    }

    else if(lex[0] == 'w' && lex[1] == 'h' && lex[2] >= 'i' && lex[3] == 'l' && lex[4] == 'e' && lex[5] == '\0' ){
        s = 1;      //while
    }

    else if(lex[0] == 'f' && lex[1] == 'o' && lex[2] >= 'r' && lex[3] == '\0' ){
        s = 1;      //for
    }

    else if(lex[0] == 'd' && lex[1] == 'o' && lex[2] == '\0' ){
        s = 1;      //do
    }

    else if(lex[0] == 'i' && lex[1] == 'f' && lex[2] == '\0' ){
        s = 1;      //if
    }

    else if(lex[0] == 'e' && lex[1] == 'l' && lex[2] >= 's' && lex[3] == 'e' && lex[4] == '\0' ){
        s = 1;      //else
    }

    else if(lex[0] == 'v' && lex[1] == 'o' && lex[2] >= 'i' && lex[3] == 'd' && lex[4] == '\0' ){
        s = 1;      //void
    }

    else if(lex[0] == 's' && lex[1] == 't' && lex[2] >= 'a' && lex[3] == 't' && lex[4] == 'i' && lex[5] == 'c' && lex[6] == '\0' ){
        s = 1;      //static
    }

    else if(lex[0] == 'b' && lex[1] == 'r' && lex[2] >= 'e' && lex[3] == 'a' && lex[4] == 'k' && lex[5] == '\0' ){
        s = 1;      //break
    }

    else if(lex[0] == 'c' && lex[1] == 'o' && lex[2] >= 'n' && lex[3] == 't' && lex[4] == 'i' && lex[5] == 'n' && lex[6] == 'u' && lex[7] == 'e' && lex[8] == '\0' ){
        s = 1;      //continue
    }

    else if(lex[0] == 'd' && lex[1] == 'e' && lex[2] >= 'f' && lex[3] == 'a' && lex[4] == 'u' && lex[5] == 'l' && lex[6] == 't' && lex[7] == '\0' ){
        s = 1;      //default
    }

    else if(lex[0] == 'c' && lex[1] == 'o' && lex[2] >= 'n' && lex[3] == 's' && lex[4] == 't' && lex[5] == '\0' ){
        s = 1;      //const
    }

    else if(lex[0] == 's' && lex[1] == 'w' && lex[2] >= 'i' && lex[3] == 't' && lex[4] == 'c' && lex[5] == 'h' && lex[6] == '\0' ){
        s = 1;      //switch
    }

    else if(lex[0] == 'c' && lex[1] == 'a' && lex[2] >= 's' && lex[3] == 'e' && lex[4] == '\0' ){
        s = 1;      //case
    }

    else if(lex[0] == 's' && lex[1] == 'i' && lex[2] >= 'z' && lex[3] == 'e' && lex[4] == 'o' && lex[5] == 'f' && lex[6] == '\0' ){
        s = 1;      //sizeof
    }

    else if(lex[0] == 's' && lex[1] == 't' && lex[2] >= 'r' && lex[3] == 'u' && lex[4] == 'c' && lex[5] == 't' && lex[6] == '\0' ){
        s = 1;      //struct
    }

    else if(lex[0] == 's' && lex[1] == 'i' && lex[2] >= 'g' && lex[3] == 'n' && lex[4] == 'e' && lex[5] == 'd' && lex[6] == '\0' ){
        s = 1;      //signed
    }

    else if(lex[0] == 'u' && lex[1] == 'n' && lex[2] >= 's' && lex[3] == 'i' && lex[4] == 'g' && lex[5] == 'n' && lex[6] == 'e' && lex[7] == 'd' && lex[8] == '\0' ){
        s = 1;      //unsigned
    }

    else if(lex[0] == 'r' && lex[1] == 'e' && lex[2] >= 't' && lex[3] == 'u' && lex[4] == 'r' && lex[5] == 'n' && lex[6] == '\0' ){
        s = 1;      //return
    }

    return s ;
}

/// ///////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////ASSIGNMENT 03//////////////////////////////////////////
/// ///////////////////////////////////////////////////////////////////////////////////////////
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

/// ///////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////ASSIGNMENT 04//////////////////////////////////////////
/// ///////////////////////////////////////////////////////////////////////////////////////////
void lineNumberPrint(FILE *source, FILE *target, char sourceFileName[30], char targetFileName[30]){
    char c;
    int lineNo = 1;
    char lineNoBuffer[20];
    itoa(lineNo,lineNoBuffer,10);


    if(source == NULL){
        printf("\nFile cannot be opened");
    }
    else{
        itoa(lineNo, lineNoBuffer,10);
        fputs(lineNoBuffer,target);
        fputs(": ",target);
        while( (c = fgetc(source)) != EOF ){
            if( (c == 10) ){
                fputc(10,target);
                lineNo++;
                itoa(lineNo,lineNoBuffer,10);
                fputs(lineNoBuffer,target);
                fputs(": ",target);
                continue;
            }

            fputc(c,target);
        }
    }
    fclose(source);
    fclose(target);
}

int main(){

    FILE * fptr;
    char str[1000];

    printf("Write your code below \n");
    fptr = fopen("170204025_Asm_Input.txt", "w");
    while (1) {
            gets(str);
            if (strcmp(str, "z") == 0 || strcmp(str, "Z") == 0)
                  break;
            strcat(str, "\n");
            fputs(str, fptr);
        }
        fclose(fptr);

    char c;
    char sourceFileName[30] = "compiler_Asm_Input.txt";
    char tempFileName[30] = "compiler_Asm1_Out1.txt";              //removed comment output
    char targetFileName[30] = "compiler_Asm1_Out2.txt";            //removed space output
    char lexSeparatorFileName[30] = "compiler_Asm2_Out1.txt";      //lexeme separator output
    char lexTokenFileName[30] = "compiler_Asm2_Out2.txt";          //lexeme tokenized output
    char identifierFileName[30] = "compiler_Asm3_Out1.txt";        //only identifier output
    char modilfyFileName[30] = "compiler_Asm3_Out2.txt";           //modified token output
    char lineNumberFileName[30] = "compiler_Asm4_Out1.txt";        //line number output
    char errorFileName[30] = "compiler_Asm4_Out2.txt";             //Error output
    char tableFileName[30] = "compiler_Asm3_T1.txt";
    FILE *source, *target;

    ///removing comment
    source = fopen(sourceFileName, "r");
    target = fopen(tempFileName, "w");
    removeComments(source, target, sourceFileName, tempFileName);

    ///removing spaces
    source = fopen(tempFileName, "r");
    target = fopen(targetFileName, "w");
    removeSpaces(source, target, tempFileName, targetFileName);

printf("\n===== After Removing Spaces & Comments =====\n\n");
    target = fopen (targetFileName,"r");
    while( (c = fgetc(target)) != EOF)
    {
        printf("%c",c);
    }
    fclose(target);

    printf("\n\n");

    ///lexeme separator
    source = fopen(targetFileName, "r");
    target = fopen(lexSeparatorFileName, "w");
    lexemeSeparator(source, target, targetFileName, lexSeparatorFileName);

    ///lexeme tokenized
    source = fopen(lexSeparatorFileName, "r");
    target = fopen(lexTokenFileName, "w");
    lexemeTokenization(source, target, lexSeparatorFileName, lexTokenFileName);

    printf("\n========== After Tokenization ==========\n\n");
    target = fopen (lexTokenFileName,"r");
    while( (c = fgetc(target)) != EOF)
    {
        printf("%c",c);
    }
    fclose(target);

    printf("\n\n");

        source = fopen(lexTokenFileName, "r");
    target = fopen(identifierFileName, "w");
    lexemeSimplify(source, target, lexTokenFileName, identifierFileName);

    printf("\n============== Only Identifier ==============\n\n");
    target = fopen (identifierFileName,"r");
    while( (c = fgetc(target)) != EOF)
    {
        printf("%c",c);
    }
    fclose(target);

    printf("\n\n");

    source = fopen(identifierFileName, "r");
    target = fopen(tableFileName, "w");
    symbolTableGenerate(source, target, lexTokenFileName, identifierFileName);

    source = fopen(identifierFileName, "r");
    target = fopen(modilfyFileName, "w");
    modifiedTokenStream(source, target, lexTokenFileName, identifierFileName);

    printf("\n============== Modified Token ==============\n\n");
    target = fopen (modilfyFileName,"r");
    while( (c = fgetc(target)) != EOF)
    {
        printf("%c",c);
    }
    fclose(target);

    printf("\n\n");


    remove(tableFileName);

    ///Line Numbering
    source = fopen(lexTokenFileName, "r");
    target = fopen(lineNumberFileName, "w");
    lineNumberPrint(source, target, lexTokenFileName, lineNumberFileName);

    ///  printing in console
    printf("\n============== Line Numbering ==============\n\n");
    target = fopen (lineNumberFileName,"r");
    while( (c = fgetc(target)) != EOF){
        printf("%c",c);
    }
    fclose(target);
    printf("\n\n");

    printf("\n============== Error in code ==============\n\n");
    ///Finding Errors
    source = fopen(lineNumberFileName, "r");
    target = fopen(errorFileName, "w");
    findErrors(source, target, lineNumberFileName, errorFileName);

    printf("\n\n");

    return 0;
}
