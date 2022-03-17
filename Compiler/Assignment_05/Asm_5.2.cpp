#include <stdio.h>
#include <string.h>
int Exp(char *str);
int Term(char *str);
int Factor(char *str);
int isId(char *str);
int isNum(char *str);

int main(){

    char str1[30];
    while(1){
        gets(str1);
        if(Exp(str1))
            printf("Accepted:  %s\n",str1);
        else
            printf("Rejected:  %s\n",str1);
    }
    return 0;
}

int Exp(char *str){
    int len = strlen(str);
    int symFlag = 0;
    int brcFlag = 0;
    int symPos = 0;
    int i = 0, j = 0;

    while(i<len){       ///Exp -> Term+Term | Term-Term (checking number of + or - and getting its index value)
        if(str[i] == '('){
            brcFlag = 1;
            i++;
            continue;
        }
        if(brcFlag == 1){
            if(str[i] == ')'){
                brcFlag = 0;
            }
            i++;
            continue;
        }

        if(str[i] == '+' || str[i] == '-'){
            symPos=i;
            symFlag++;
        }
        i++;
    }

    if(symFlag > 1){        //invalid
        return 0;
    }

    else if(symFlag == 1){      ///Exp -> Term+Term | Term-Term
        char str1[100], str2[100];
        for (i = 0; i < symPos; i++){                    //copying left side term of + or - symbol in str1
            str1[i] = str[i];
        }
        str1[i] ='\0';
        //printf("%s\t %d\n", str1, strlen(str1));

        for (i = symPos+1, j = 0; i<len; i++, j++){     //copying right side term of + or - symbol in str2
            str2[j] = str[i];
        }
        str2[j] ='\0';
        //printf("%s\t %d\n", str2, strlen(str2));

        if(Term(str1)){                                 //checking if both str1 & str2 are terms
            if(Term(str2)){
                return 1;
            }
        }
    }

    else if(symFlag == 0){     ///Exp -> Term
        if(Term(str)){
                return 1;
        }
    }

    return 0;
}

int Term(char *str){
    int len = strlen(str);
    int symFlag = 0;
    int brcFlag = 0;
    int rmvBrcFlag = 0;
    int symPos = 0;
    int i = 0, j=0;

    int brcCntFlag = 0;

    if(str[0] == '('){          ///removing '(' and ')' from str
        i++;
        brcCntFlag++;
        while(i<len && brcCntFlag != 0){   //(a+9)*5+4+(b-c) ((a+9)*5+4+(b-c))
            if(str[i] == '('){
                brcCntFlag++;
                i++;
                continue;
            }
            if(str[i] == ')'){
                brcCntFlag--;
                i++;
                continue;
            }
            i++;
        }
        if(i == len && brcCntFlag == 0){
            rmvBrcFlag = 1;
        }
        if(rmvBrcFlag == 1){
            for(i = 0; i < len-2 ; i++){
                str[i] = str[i+1];
            }
            str[i] = '\0';
            len = len - 2;  //2 brc have been removed
        }
    }

    i = 0;
    while(i<len){       ///Term -> Factor*Factor | Factor/Factor (checking number of * or / and getting its index value)
        if(str[i] == '('){
            brcFlag = 1;
            i++;
            continue;
        }
        if(brcFlag == 1){
            if(str[i] == ')'){
                brcFlag = 0;
            }
            i++;
            continue;
        }

        if(str[i] == '*' || str[i] == '/'){
            symPos=i;
            symFlag++;
        }
        i++;
    }

    if(symFlag > 1){        //invalid
        return 0;
    }
    else if(symFlag == 1){      ///Term -> Factor*Factor | Factor/Factor
        char str1[100], str2[100];
        for (i = 0; i < symPos; i++){                    //copying left side term of * or / symbol in str1
            str1[i] = str[i];
        }
        str1[i] ='\0';

        for (i = symPos+1, j = 0; i<len; i++, j++){     //copying right side term of * or / symbol in str2
            str2[j] = str[i];
        }
        str2[j] ='\0';


        if(Factor(str1)){                                 //checking if both str1 & str2 are terms
            if(Factor(str2)){
                return 1;
            }
        }
    }

    else if(symFlag == 0){     ///Term -> Factor
        if(Factor(str)){
                return 1;
        }
    }

    return 0;

}

int Factor(char *str){
    int len = strlen(str);
    int symFlag = 0;
    int brcFlag = 0;
    int rmvBrcFlag = 0;
    int symPos = 0;
    int i = 0, j=0;
    int brcCntFlag = 0;

    if(str[0] == '('){          ///removing '(' and ')' from str
        i++;
        brcCntFlag++;
        while(i<len && brcCntFlag != 0){   //(a+9)*5+4+(b-c) ((a+9)*5+4+(b-c))
            if(str[i] == '('){
                brcCntFlag++;
                i++;
                continue;
            }
            if(str[i] == ')'){
                brcCntFlag--;
                i++;
                continue;
            }
            i++;
        }
        if(i == len && brcCntFlag == 0){
            rmvBrcFlag = 1;
        }
        if(rmvBrcFlag == 1){
            for(i = 0; i < len-2 ; i++){
                str[i] = str[i+1];
            }
            str[i] = '\0';
            len = len - 2;  //2 brc have been removed
            Exp(str);           /// <Factor> -> (<Exp>)
        }
    }

        if(isId(str))           /// <Factor> -> ID
            return 1;
        else if(isNum(str))     /// <Factor> -> NUM
            return 1;
        Exp(str);

    return 0;
}

int isId(char *str){
    if(str[0]>='a' && str[0]<='e')
        return 1;
    return 0;
}

int isNum(char *str){
    if(str[0]>='0' && str[0]<='9')
        return 1;
    return 0;
}

    /*Test:
    b+4**
    b+4
    (((((a+9)*5*)4+(b-c)
    a+(b+3)
    a+b+c
    a*b+c*d
    (a+9*8)*5+(4/(b+c))
    */
