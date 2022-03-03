#include <stdio.h>

int main ()
{
  FILE * fptr;
  int i,n;
  char str[1000];

  char str1;

	printf(" Input the number of lines to be written : ");
	scanf("%d", &n);
	printf("\n :: Write your code below ::\n");
	fptr = fopen("prog.c", "w");
	for(i = 0; i < n+1;i++)
		{
		fgets(str, sizeof str, stdin);
		fputs(str, fptr);
		}
  fclose (fptr);

    FILE *p1, *p2;
    p1 = fopen("prog.c", "r");
    p2 = fopen("output.txt","w");
    if(!p1)
        printf("\nFile can't be opened!");
    else
    {
        char c,c2;
        while((c=fgetc(p1))!=EOF)
        {
            if( c == '/')
            {
                if((c2=fgetc(p1))=='*')////block comment
                {
                    char cmt1,cmt2;

                    while((cmt1=fgetc(p1))!=EOF)
                    {
                        if(cmt1=='*')
                        {
                            cmt2=fgetc(p1);
                            if(cmt2=='/')
                                break;
                        }
                    }
                }
                else if( c2 == '/')//single line comment
                {
                    char cm;
                    while((cm=fgetc(p1))!=EOF)
                    {
                        if(cm=='\n')
                            break;
                    }

                }
                else
                {
                    fputc(c,p2);
                    fputc(c2,p2);
                }
            }
            else if(c=='\n'||c=='\t')//newline,tab
            {
                continue;
            }
            else
                {
                    fputc(c,p2);

                }
        }


        fclose(p1);
        fclose(p2);

        printf("\n\nOutput File:\n");
        p2 = fopen("output.txt","r");
        while((c=fgetc(p2))!=EOF)
            printf("%c",c);
        fclose(p2);
    }

    return 0;
}
