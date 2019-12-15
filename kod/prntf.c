#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void Myprintf(char *, ...);  // Our printf function
char *convert(unsigned int,
              int);  // Convert integer number into octal, hex, etc.

int main() {
    int n = 9;
    Myprintf("WWW.FIRMCODES.COM \n%dasd", n);
    n = 255;
    Myprintf("\n%d = 0x%x", n, n);

    return 0;
}

void Myprintf(char *format, ...) {
    char *traverse;
    unsigned int i;
    char *s;
    int err = 0;

    // Module 1: Initializing Myprintf's arguments
    va_list arg;
    va_start(arg, format);

    for (traverse = format; *traverse != '\0'; traverse++) {
        while (*traverse != '%' && *traverse != '\0') {
            putchar(*traverse);
            traverse++;
        }

        if (*traverse == '\0') {
            break;
        }
        traverse++;

        // Module 2: Fetching and executing arguments
        switch (*traverse) {
        case 'c':
            i = va_arg(arg, int);  // Fetch char argument
            putchar(i);
            break;

        case 'd':
            i = va_arg(arg, int);  // Fetch Decimal/Integer argument
            if (i < 0) {
                i = -i;
                putchar('-');
            }
            fputs(convert(i, 10), stdout);
            break;

        case 'o':
            i = va_arg(arg, unsigned int);  // Fetch Octal representation
            fputs(convert(i, 8), stdout);
            break;

        case 's':
            s = va_arg(arg, char *);  // Fetch string
            fputs(s, stdout);
            break;

        case 'x':
            i = va_arg(arg, unsigned int);  // Fetch Hexadecimal representation
            fputs(convert(i, 16), stdout);
            break;
        default:
            fputs("Format specifier not found:\"", stdout);
            putchar(*traverse);
            fputs("\".", stdout);
            err = 1;
        }
        if (err != 0)
            break;
    }

    // Module 3: Closing argument list to necessary clean-up
    va_end(arg);
}

char *convert(unsigned int num, int base) {
    static char Representation[] = "0123456789abcdef";
    // static char buffer[50];
    char *ptr;
    char *buffer = (char *)malloc(49 * sizeof(char));
    // buffer=(char*)malloc(49*sizeof(char));
    ptr = &buffer[49];
    //*ptr = '\0';
    buffer[49] = '\0';

    do {
        *--ptr = Representation[num % base];
        num /= base;
    } while (num != 0);

    return ptr;
}
