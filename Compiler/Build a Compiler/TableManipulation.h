int sl = 0;
char table[100][100][100];

void InsertSlNoInTable(int i, int j, int sl){
    int x = sl;
    int count = 0;

    while(sl != 0){
        sl = sl / 10;
        count++;
    }

    int k;
    for(k = count-1; k >= 0; k--){
        table[i][j][k] = (x % 10) + 48;
        x = x / 10;
    }
    table[i][j][count]  = '\0';
}
void InsertStringInTable(int i, int j, char* str2){
    int k;
    for(k = 0;k<strlen(str2);k++){
        table[i][j][k] = str2[k];
    }
    table[i][j][k]  = '\0';
}
void Insert(int sl, char* name, char* idtype, char* dataType, char* scope){
    InsertSlNoInTable(sl,0,sl+1);
    InsertStringInTable(sl,1,name);
    InsertStringInTable(sl,2,idtype);
    InsertStringInTable(sl,3,dataType);
    InsertStringInTable(sl,4,scope);
}
void UpdateScope(char* str1, char* str2, char* scope)
{
    int i;
    int a = Search(str1,scope);
    int b = Search(str2,scope);

    if(a == -1)
        a = Search(str1,"global");

    if(b == -1)
        b = Search(str2,"global");


    if(a != -1){
        for(i = 0; table[b][5][i] != '\0'; i++){   //updating scope if str1 not global
            table[a][5][i] = table[b][5][i];
        }
        table[a][5][i]  = '\0';
    }

}
void UpdateId(char* str1, char* str2, char* scope){
    int a = Search(str1,scope);
    int k;
    if(a!=-1){
        for(k = 0;k<strlen(str2);k++){    //updating id type
            table[a][2][k] = str2[k];
        }
        table[a][2][k]  = '\0';
    }
}
void Delete(char* str){
    int i;
    for(i = 0;i<50;i++){
        str[i] = '\0';
    }
}
int Search(char* str, char* scope){
   int i,k;
   char str2[50], str3[50];

   for(i = 0; i < sl; i++){
       Delete(str2);
       Delete(str3);

       for(k = 0; table[i][1][k] != '\0'; k++){ //id name
           str2[k] =  table[i][1][k];
       }

       for(k = 0;table[i][4][k]!='\0';k++){     //data type
           str3[k] =  table[i][4][k];
       }

       if(strcmp(str,str2) == 0 && strcmp(scope,str3) == 0)
           return i;
   }
   return -1;
}
void DisplayTable()
{
    int i,j;
    printf("-----------------------------------  Symbol Table  -----------------------------------\n");
    printf("Sl.No.\t\tName\t\tId Type\t\tData Type\tScope\t\tValue\n");
    printf("--------------------------------------------------------------------------------------\n");
    for(i = 0;i<sl;i++)
    {
        int bl = 0;
        int k;
        char s[50];
        Delete(s);
        for(k = 0;table[i][2][k]!='\0';k++)
        {
            s[k] = table[i][2][k];
        }
        if(strcmp("func",s)==0)
            bl = 1;
        for(j = 0;j<6;j++)
        {
            if(bl==1 && j==5)
                continue;
            printf("%s\t\t",table[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
}
void printTableInFile(FILE *target)
{
    int i,j;
    fputs("Sl.No.\t\tName\tId Type\t\t\tData Type\t\t\tScope\t\t\tValue", target);
    fputs("\n", target);
    for(i = 0;i<sl;i++){
        int bl = 0;
        int k;
        char s[50];
        Delete(s);
        for(k = 0;table[i][2][k]!='\0';k++){
            s[k] = table[i][2][k];
        }
        if(strcmp("func",s)==0)
            bl = 1;
        for(j = 0;j<6;j++){
            if(bl==1 && j==5)
                continue;
            fputs(table[i][j], target);
            fputs("\t\t\t", target);
        }
        fputs("\n", target);
    }
}
void CopyIdToArray(char* str1, char* str2){
    int i, j;
    Delete(str1);

    for(i = 3,j = 0;i<strlen(str2);i++,j++){
        str1[j] = str2[i];
    }
}
void CopyStringToArray(char* str1, char* str2){
    int i;
    Delete(str1);

    for(i = 0; i < strlen(str2); i++){
        str1[i] = str2[i];
    }
}
int isDataType(char* str1){
    //if(strcmp(lex , "int") == 0 || strcmp(lex , "double") == 0 || strcmp(lex , "float") == 0
       //|| strcmp(lex , "char") == 0 || strcmp(lex , "void") == 0){
       // return 1;
       //}
       //return 0;
    int n = 5;
    char str2[5][20] = {"int","float","double","char", "void"};
    int i;
    for(i = 0;i<n;i++){
        if(strcmp(str1,str2[i])==0)
            return 1;
    }
    return 0;
}

