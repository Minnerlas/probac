#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
char* inttoascii(uint n,int b){
    char *ptr;
    char cifre[]="0123456789abcdef";
    char *buff;
    int i=0,duz=0;
    buff=(char*)malloc(21*sizeof(char));
    buff[20]='\0';
    if(n==0){
        buff[0]='0';
        buff[1]=0;
        return buff;
    }
    while(n!=0){
        buff[i]=cifre[n%b];
        n/=b;
        i++;
        duz++;
    }
    buff[i]='\0';
    for(i=0;i<duz/2;i++){
        char t=buff[i];
        buff[i]=buff[duz-1-i];
        buff[duz-1-i]=t;
    }
 
 
    return buff;
}
 
 
void prnt(char* format,void **n){
    va_list args;
    int j=0,f=0,ind=0;
    char *s;
 
    for(int i=0;format[i]!=0;i++){
        while(format[i]!='%'){
            if(format[i]==0){
                f=1;
                break;
            }
            putchar(format[i]);
            i++;
        }
 
        if(f)
            break;
 
 
        switch(format[++i]){
            case 'd':
                j=*(int*)n[ind];
                ind++;
                if (j<0){
                    j=-j;
                    putchar('-');
                }
                s=inttoascii(j,10);
                fputs(s,stdout);
                free(s);
                break;
            case 'u':
                j=*(unsigned int*)n[ind];
                ind++;
                s=inttoascii(j,10);
                fputs(s,stdout);
                free(s);
                break;
            case 'x':
                j=*(unsigned int*)n[ind];
                ind++;
                s=inttoascii(j,16);
                fputs(s,stdout);
                free(s);
                break;
            case 'c':
                j=*(int*)n[ind];
                ind++;
                putchar(j);
 
                break;
            case 's':
                s=(char*)n[ind];
                ind++;

                //s=va_arg(args,char*);
                if(s==NULL){
                    fputs("(null)",stdout);
                    break;
                }
                fputs(s,stdout);
 
                break;
            case 'o':
                j=*(int*)n[ind];
                ind++;
                s=inttoascii(j,8);
                fputs(s,stdout);
                free(s);
                break;
            case '%':
                putchar('%');
                break;
            default:
                fputs("\nUnknown format specifier %",stdout);
                putchar(format[i]);
                puts(".");
        }
    }
}
 
int main(int argc, char** argv, char** env){
    char *s="Nikola";
    int a=4,b=2,c = 42;
    void *n[5];
    n[0]=s;
    n[1]=&b;
    n[2]=&c;
    prnt("Hello World\n%s\n%d\n%x\n",n);
 
    return 0;
}