/* Lex Program to check EMail & phone number */
%{
    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>

%}

/* Rule Section */
%%


[a-zA-Z0-9_]+@[a-zA-Z0-9_]+[.][a-zA-Z0-9_]+ { printf("%s is Valid Email ID", yytext); }

[0-9]{10} { printf("%s is Valid Mobile Number", yytext); }

.+ { printf("%s is Invalid Input", yytext); }

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
