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