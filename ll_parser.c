#include <stdlib.h>
#include <err.h>
#include <string.h>
#include "ll_parser.h"

static long rule_logical_or(struct expression *expr);
static long rule_logical_and(struct expression *expr);
static long rule_or(struct expression *expr);
static long rule_xor(struct expression *expr);
static long rule_and(struct expression *expr);
static long rule_sum(struct expression *expr);
static long rule_product(struct expression *expr);
static long rule_pow(struct expression *expr);
static long rule_neg(struct expression *expr);
static long rule_final(struct expression *expr);

// Lexer

/* Expression create 
 * Return value : struct expression *   : New instance of structure expression
 * Arguments    : char *                : Value of expr.str. str will be duplicated.
*/ 
struct  expression *expression_create(char *str)
{
    struct expression *res = malloc(sizeof(struct expression));
    if (!res)
        errx(1, "Maloc failed in 'expression_create'");

    res->str = strdup(str);
    res->len = strlen(str);
    res->cur = 0;

    return res;
}

/* Expression delete
 * Return value : void
 * Arguments    : struct expression * : Will delete the instance of expression
*/ 
void    expression_delete(struct expression *expr)
{
    if (!expr)
        return;
    free(expr->str);
    free(expr);
}
