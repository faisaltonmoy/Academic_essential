#include <stdio.h>
#include <string.h>

int A(char *str, int i);
int B(char *str, int i);

int main(){
    char str1[30];
    while(1){
        gets(str1);
        if(A(str1,0))
            printf("Accepted:  %s\n",str1);
        else
            printf("Rejected:  %s\n",str1);
    }
    return 0;
}

int A(char *str, int i){
    int len = strlen(str);

    if(i < len && str[i] == 'a'){
        i++;
        return A(str, i);
    }
    else if(i == len-1){
        return B(str, i);
    }
    return 0;
}

int B(char *str, int i){
    if(str[i] == 'b'){
        return 1;
    }
    else{
       return 0;
    }
}
//      S ->  b | AB
//      A -> a | aA
//      B -> b
//      b, ab, aab, aaab, ...
