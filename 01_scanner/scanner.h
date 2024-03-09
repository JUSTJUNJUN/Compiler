#ifndef __SCANNER_H__
#define __SCANNER_H__


/* Token */
typedef struct token_s {
    int token;
    int int_value;
} token_t;


/* Token Type */
typedef enum {
    T_PLUS,
    T_MINUS,
    T_STAR,
    T_SLASH,
    T_INTLIT,
};


#endif  /* __SCANNER_H__ */