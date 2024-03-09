

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#include "scanner.h"


int     line;
int     putback;
FILE    *input_file;


/* Init global variables */
static void
init(void)
{
    line = 1;
    putback = '\n';

    return;
}


/* Print usage if started incorrectly */
static void
usage(char *prog)
{
    fprintf(stderr, "Usage: %s infile\n", prog);
    exit(1);

    return;
}


/* List of printable tokens */
char *token_str[] = { "+", "-", "*", "/", "intlit" };


static void
scan_file(void)
{
    token_t t;

    while (scan(&t) != NULL) {
        printf("Token %s", token_str[t.token]);
        if (t.token == T_INTLIT) {
            printf(", value %d", t.int_value);
        }
        printf("\n");
    }

    return;
}


void
main(int argc, char *argv[])
{
    if (argc != 2) {
        usage(argv[0]);
    }

    init();

    if ((input_file = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
        exit(1);
    }

    scan_file();
    exit(0);
}