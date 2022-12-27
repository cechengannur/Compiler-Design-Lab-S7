%{
#include<stdio.h>
int sc=0,wc=0,lc=0,cc=0;
%}
%%
[\n] { lc++; cc+=yyleng;}
[ \t] { sc++; cc+=yyleng;}
[^\t\n ]+ { wc++; cc+=yyleng;}
%%
int main(int argc ,char* argv[ ])
{
 printf("Enter the input:\n");
 yylex();
 printf("The number of lines=%d\n",lc);
 printf("The number of spaces=%d\n",sc);
 printf("The number of words=%d\n",wc);
 printf("The number of characters are=%d\n",cc);
}
int yywrap( )
{
 return 1;
}

// to compile type lex demo.l
// then type cc lex.yy.c
// then type ./a.out
/*
Enter the input: Greetings from CEC
Welcome to Chengannur
Lex Yacc Program
(Note: After input string press enter and ctrl+d)
The number of lines=3
The number of spaces=6
The number of words=9
The number of characters are=58
*/