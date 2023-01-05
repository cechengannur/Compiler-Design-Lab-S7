%{

#include<stdio.h>

#include "y.tab.h"

extern int yylval;

%}



%%

[0-9]+ {

    yylval=atoi(yytext);

    return NUMBER;

}

[\t] ;

[\n] return 0;

. return yytext[0];

%%

int yywrap()

{

return 1;

}


/* tO cOMPILE

    yacc -d calc.y
    lex calc.l
    gcc lex.yy.c y.tab.c -w
    ./a.out
 */

// Algorithm YACC & LEX Calculator

// 1. Start
// 2. Read the expression
// 3. Check for the valid expression matching the grammar
// 4. If the expression is valid, then evaluate the expression
// 5. If the expression is invalid, then display the error message
// 6. Stop