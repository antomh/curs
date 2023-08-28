#include "tc.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define INPUT_STREAM   stdin
#define OUTPUT_STREAM  stdout

int main(void) {

    tc_echo_off();
    tc_icanon_off();

    char sym;
    char pcstr[100]; memset(pcstr, 0x00, 100);
    char nptr = 0;

    while (true) {
        sym = getc(INPUT_STREAM);

        if (sym == '\n')
            sym = 'N';

        if (sym == 27)
            if (getc(INPUT_STREAM) == 91) {
                switch (getc(INPUT_STREAM)) {
                    case 65:
                    // Arrow up.
                        putc('U', OUTPUT_STREAM);
                        pcstr[nptr] = 'U';
                        nptr++;
                        break;
                    case 66:
                    // Arrow down.
                        putc('D', OUTPUT_STREAM);
                        pcstr[nptr] = 'D';
                        nptr++;
                        break;
                    case 67:
                    // Arrow right.
                        tc_move_cursor_right(1);
                        if (nptr < 100) nptr++;
                        break;
                    case 68:
                    // Arrow left.
                        tc_move_cursor_left(1);
                        if (nptr > 0) nptr--;
                        break;
                    default:
                        break;
                }
                continue;
            }

        pcstr[nptr] = sym;
        nptr++;

        putc(sym, OUTPUT_STREAM);
        if (sym == '.') break;
    }
    
    tc_echo_on();
    tc_icanon_on();

    printf("\n%s", pcstr);

    return 0;
}
