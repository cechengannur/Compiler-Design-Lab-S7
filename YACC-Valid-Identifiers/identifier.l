%{

    #include "y.tab.h"

%}

%%

[a-zA-Z_][a-zA-Z_0-9]* return letter;

[0-9]                       return digit;

.                      return yytext[0];

\n                     return 0;

%%

int yywrap()

{

return 1;

}

// To compile this file, use the following command:
// yacc -d identifier.y
// lex identifier.l
// gcc lex.yy.c y.tab.c -w
// ./a.out