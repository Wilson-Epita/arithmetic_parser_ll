#pragma once
#include <stddef.h>

struct expression
{
    char    *str;
    size_t  len;
    size_t  cur;
};

struct  expression *expression_create(char *str);
void    expression_delete(struct expression *expr);
