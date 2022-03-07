#include "Stack.h"

void unmatchedParentheses(FILE *source, FILE *target){                              //unmatched/unbalanced parenthesis ( ) checking
    char c;
    char lineNoStr[20];
    _stack *parStack = (_stack *)malloc(sizeof(_stack));
    createEmptyStack(parStack);

    if(source == NULL || target == NULL){
        printf("\nFile cannot be opened");
    }
    else{
        int i = 0, lineNoStart = 1;
        int forStat = 0;

        while( (c = fgetc(source)) != EOF ){
            ///   getting Line number and storing in lineNoStr String
            if(lineNoStart == 1 && c != ':'){                                       // line number is upto : symbol
                lineNoStr[i] = c;
                i++;
                continue;
            }
            else if(lineNoStart == 1 && c == ':'){
                lineNoStr[i] = '\0';
                i = 0;
                lineNoStart = 0;
            }
            else if(c == 10){                                                       //line number starts after a new line
                lineNoStart = 1;
            }

            int lineNo = atoi(lineNoStr);                                           //converting lineNo char array(string) to integer

            ///     for checking
            if(c == 'k'){                                                           //checking 'kw for' and setting forStat = 1
                c = fgetc(source);
                if(c == 'w'){
                    c = fgetc(source);
                    if(c == ' '){
                        c = fgetc(source);
                        if(c == 'f'){
                            c = fgetc(source);
                            if(c == 'o'){
                                c = fgetc(source);
                                if(c == 'r'){
                                    forStat = 1;
                                }
                            }
                        }
                    }
                }
            }
            if(forStat == 1 || forStat == 2){
                if(c == '('){                                                        //opening bracket of for kw
                    forStat = 2;
                }
                if(c == ')' && forStat == 2){                                        //closing bracket of for kw
                    forStat = 0;
                }
                continue;
            }

            ///     comparing parentheses
            if (forStat == 0){
                if(c == '('){
                    push(parStack, lineNo);
                }
                else if(c == ')'){
                    if( isempty(parStack)) {
                        printf("Unmatched ')' at line: %d,", lineNo);
                        printf("\n");
                    }
                    else{
                        pop(parStack);
                    }
                }
                else if ( c == ';' || c == '{' ){                                    //checking parentheses upto ; or { symbol
                    if( !isempty(parStack)) {
                        printf("Unmatched '(' at line: ");
                        printStack(parStack);
                        printf("\n");

                        while(!isempty(parStack)){
                            pop(parStack);
                        }
                    }
                }
            }
        }
    }
    while(!isempty(parStack)){
        pop(parStack);
    }
    fclose(source);
    fclose(target);

}

void unmatchedBraces(FILE *source, FILE *target){
    char c;
    char lineNoStr[20];
    _stack *brcStack = (_stack *)malloc(sizeof(_stack));
    createEmptyStack(brcStack);

    if(source == NULL || target == NULL){
        printf("\nFile cannot be opened");
    }
    else{
        int i = 0, lineNoStart = 1;
        int forStat = 0;

        while( (c = fgetc(source)) != EOF ){
            ///   getting Line number and storing in lineNoStr String
            if(lineNoStart == 1 && c != ':'){                                         // line number is upto : symbol
                lineNoStr[i] = c;
                i++;
                continue;
            }
            else if(lineNoStart == 1 && c == ':'){
                lineNoStr[i] = '\0';
                i = 0;
                lineNoStart = 0;
            }
            else if(c == 10){                                                        //line number starts after a new line
                lineNoStart = 1;
                //printf("\n");
            }

            int lineNo = atoi(lineNoStr);                                            //converting lineNo char array(string) to integer

            ///     comparing braces
            if(c == '{'){
                push(brcStack, lineNo);
            }
            else if(c == '}'){
                if( isempty(brcStack)) {
                    printf("Unmatched '}' at line: %d,", lineNo);
                    printf("\n");
                }
                else{
                    pop(brcStack);
                }
            }

        }
        if( !isempty(brcStack)) {
            printf("Unmatched '{' at line: ");
            printStack(brcStack);
            printf("\n");
        }
    }
    while(!isempty(brcStack)){
        pop(brcStack);
    }
    fclose(source);
    fclose(target);
}

void duplicateToken(FILE *source, FILE *target){
    char c, currentStr[50], previousStr[50];

    if(source == NULL || target == NULL){
        printf("\nFile cannot be opened");
    }
    else{
        int i = 0, lineNo = 1;
        while( (c = fgetc(source)) != EOF ){
            if(c == 10){    //line no increases after getting new line
                lineNo++;
            }
            if(c == ';'){    //semicolon resets previousStr variable
                previousStr[0] = '\0';
            }

            if(c == ' '){       //checking each lexeme separately
                currentStr[i] = '\0';
                i=0;

                if(isKeyword(currentStr)){  //only keywords are comparing
                    if(strcmp(previousStr, currentStr) == 0){   //if previously we got keyword is same as current
                        printf("Duplicate token %s at line %d\n", currentStr, lineNo);
                    }
                    strcpy(previousStr, currentStr);    //copying current to previous
                }
                continue;
            }
            else{
                currentStr[i] = c;
                i++;
            }
        }
    }

    fclose(source);
    fclose(target);
}

void duplicateSemicolon(FILE *source, FILE *target){
    char c;

    if(source == NULL || target == NULL){
        printf("\nFile cannot be opened");
    }

    else{
        int i = 0, lineNo = 1, semicolonCount = 0, forStat = 0;
        while( (c = fgetc(source)) != EOF ){
            if(c == 10){    //line no increases after getting new line
                lineNo++;
                semicolonCount = 0;
            }
            ///     for kw checking
            if(c == 'k'){       //checking 'kw for' and setting forStat = 1
                c = fgetc(source);
                if(c == 'w'){
                    c = fgetc(source);
                    if(c == ' '){
                        c = fgetc(source);
                        if(c == 'f'){
                            c = fgetc(source);
                            if(c == 'o'){
                                c = fgetc(source);
                                if(c == 'r'){
                                    forStat = 1;
                                }
                            }
                        }
                    }
                }
            }
            if(forStat == 1 || forStat == 2){
                if(c == '('){       //opening bracket of for kw
                    forStat = 2;
                }
                if(c == ')' && forStat == 2){       //closing bracket of for kw
                    forStat = 0;
                }
                continue;
            }
            /// other semicolon
            if (forStat == 0){
                if(c == ';' && semicolonCount == 0){
                    semicolonCount = 1;
                }
                else if (c == ';' && semicolonCount == 1){
                    printf("Duplicate 'Semicolon' at line %d\n", lineNo);
                }

            }
        }
    }
    fclose(source);
    fclose(target);
}

void unknownError(FILE *source, FILE *target){
    char c;

    if(source == NULL || target == NULL){
        printf("\nFile cannot be opened");
    }

    else{
        int i = 0, lineNo = 1, unknStat = 0;
        while( (c = fgetc(source)) != EOF ){
            if(c == 10){    //line no increases after getting new line
                lineNo++;
            }
            ///     unkn checking
            if(c == 'u'){
                c = fgetc(source);
                if(c == 'n'){
                    c = fgetc(source);
                    if(c == 'k'){
                        c = fgetc(source);
                        if(c == 'n'){
                            c = fgetc(source);
                            if(c == ' '){
                                printf("'Unknown' error at line %d\n", lineNo);
                            }
                        }
                    }
                }
            }
            if(unknStat == 1){

            }
        }
    }
    fclose(source);
    fclose(target);
}

void unbalancedIfElse(FILE *source, FILE *target){
    char c, str[50], previousStr[50];
    int ifStat=0;

    if(source == NULL || target == NULL){
        printf("\nFile cannot be opened");
    }
    else{
        int i = 0, lineNo = 1;
        while( (c = fgetc(source)) != EOF ){
            if(c == 10){    //line no increases after getting new line
                lineNo++;
            }

            if(c == ' '){       //checking each lexeme separately
                str[i] = '\0';
                i=0;

                if(str[0]=='i' && str[1]=='f'){
                    ifStat=1;
                }

                else if(str[0]=='e' && str[1]=='l' && str[2]=='s' && str[3]=='e'){
                    if(ifStat == 0)
                        printf("Unmatched 'else' at line %d ",lineNo);

                    ifStat=0;
                }
                str[0] = '\0';
                i=0;
            }

            else{
                str[i] = c;
                i++;
            }
        }
    }

    fclose(source);
    fclose(target);
}

void findErrors(FILE *source, FILE *target, char sourceFileName[30], char targetFileName[30]){
    unmatchedParentheses(source,target);

    source = fopen(sourceFileName, "r");
    target = fopen(targetFileName, "w");
    unmatchedBraces(source,target);

    source = fopen(sourceFileName, "r");
    target = fopen(targetFileName, "w");
    duplicateToken(source,target);

    source = fopen(sourceFileName, "r");
    target = fopen(targetFileName, "w");
    duplicateSemicolon(source,target);

    source = fopen(sourceFileName, "r");
    target = fopen(targetFileName, "w");
    unknownError(source,target);

    source = fopen(sourceFileName, "r");
    target = fopen(targetFileName, "w");
    unbalancedIfElse(source,target);
}

