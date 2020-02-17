#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    FILE * rfp;
    FILE * wfp;
    char filename[64];
    char exec[128];
    char ch;
    if(argc!=2)
    {
        printf("                            ______________________                             \n");
        printf("                     _______|__Brainfuck__to__C__|_________                    \n");
        printf("                     |__Copyright__(C)__2019__PengZekai___|                    \n");
        printf("                        £ºPlease enter the file address £º                     \n");
        printf("================================================================================\n"); 
        printf(" >>> ");
        scanf("%s",filename);
    }
    else
    {
        strcpy(filename,argv[1]);
    }
    rfp=fopen(filename,"r");
    strcat(filename,".c");
    wfp=fopen(filename,"w");
    if(rfp==NULL || wfp==NULL)
    {
        printf("Can't open the file!\n");
        return -1;
    }
    fputs("/*Compile from an bf file ,Compiler author:PengZekai*/\n",wfp);
    fputs("#include <stdio.h>\n",wfp);
	fputs("#include <string.h>\n",wfp);
    fputs("int main(int argc,char *argv[])\n{",wfp);
    fputs("char *ptr; \n",wfp);
	fputs("char memory_tmp[0xffff];\n",wfp);
    fputs("memset(memory_tmp,0,sizeof(memory_tmp));\n",wfp);
	fputs("ptr=memory_tmp;\n ",wfp);

    while((ch=fgetc(rfp))!=EOF)
    {
        //printf("%c",ch);
        switch(ch)
        {
            case '>':
                fputs("++ptr;\n",wfp);
                break;
            case '<':
                fputs("--ptr;\n",wfp);
                break;
            case '+':
                fputs("++*ptr;\n",wfp);
                break;
            case '-':
                fputs("--*ptr;\n",wfp);
                break;
            case '.':
                fputs("putchar(*ptr);\n",wfp);
                break;
            case ',':
                fputs("*ptr=getchar();\n",wfp);
                break;
            case '[':
                fputs("while(*ptr)\n{\n",wfp);
                break;
            case ']':
                fputs("}\n",wfp);
                break;
            default:
                break;
        }
    }
    fputs("\n return 0; \n }",wfp);
    fclose(rfp);
    fclose(wfp);
    memset(exec,0,sizeof(exec));
    printf("\n                     Copyright  (C)  2019  PengZekai                 ");
    printf("\n       ===================brainfuck to C is OK======================\n\n");
    putchar(0);
    return 0;
}