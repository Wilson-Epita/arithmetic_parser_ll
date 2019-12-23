#include <criterion/criterion.h>
#include "ll_parser.h"

Test(Lexer, expression_create_delete)
{
    struct expression *expr = expression_create("");
    expression_delete(expr);
}
