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


// Algorithm

// 1. Read input from file.
// 2. Send input to yylex() function.
// 3. yylex() function will check for the pattern.
// 4. If pattern matches, then it will print the output.
// 5. If pattern does not match, then it will print the invalid input.
// 6. If input is EOF, then it will return 1.
// 7. Step 2 to 6 will be repeated until EOF is reached.
// 8. Stop