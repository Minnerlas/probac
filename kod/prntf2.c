#include <stdio.h>
#include <stdarg.h>
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
 
 
void prnt(char* format,...){
    va_list args;
    int j=0,f=0;
    char *s;
    va_start(args, format);
 
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
                j=va_arg(args,int);
                if (j<0){
                    j=-j;
                    putchar('-');
                }
                fputs(inttoascii(j,10),stdout);
                break;
            case 'u':
                j=va_arg(args,int);
                fputs(inttoascii(j,10),stdout);
                break;
            case 'x':
                j=(uint)va_arg(args,int);
                fputs(inttoascii(j,16),stdout);
                break;
            case 'c':
                j=va_arg(args,int);
                putchar(j);
 
                break;
            case 's':
                s=va_arg(args,char*);
                if(s==NULL){
                    fputs("(null)",stdout);
                    break;
                }
                fputs(s,stdout);
 
                break;
            case 'o':
                j=va_arg(args,int);
                fputs(inttoascii(j,8),stdout);
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
 
    va_end(args);
}
 
int main(int argc, char** argv, char** env){
    char *s=NULL;
    prnt("Hello World\n");
 
    return 0;
}