/* Lex Program to check valid Mobile Number */

%{
    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>
%}

/* Rule Section */
%%

[0-9]{10} {printf("\nMobile Number Valid %s \n", yytext);}

.+ {printf("\nMobile Number Invalid %s \n", yytext);}/* If any other character is found */

%%

// driver code
int main()
{
	// read input from file
    freopen("input.txt", "r", stdin);
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}