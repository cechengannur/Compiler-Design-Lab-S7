%{

    #include<stdio.h>

    int valid=1;   

%}

%token num id op

%%

start : id '=' s ';'

s :     id x       

      | num x       

      | '-' num x   

      | '(' s ')' x 

      ;

x :     op s        

      | '-' s       

      |             

      ;

%%

int yyerror()

{

    valid=0;

    printf("\nInvalid expression!\n");

    return 0;

}

int main()

{

    printf("\nEnter the expression:\n");

    yyparse();

    if(valid)

    {

        printf("\nValid expression!\n");

    }

}

// To compile this file, use the following command:
// yacc -d exp.y
// lex exp.l
// gcc lex.yy.c y.tab.c -w
// ./a.out