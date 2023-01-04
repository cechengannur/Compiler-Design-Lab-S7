/* Lex Program to check Prime Number */

%{
    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>

    int isPrime(int n)
    {
        int i;
        for (i = 2; i < n; i++)
        {
            if (n % i == 0)
                return 0;
        }
        return 1;
    }

    int oddEven(int num){
        if(num % 2 == 0){
            return 1;
        }
        return 0;
    }

    int factorial(int num){
        int i;
        int fact = 1;
        for(i = 1; i <= num; i++){
            fact = fact * i;
        }
        return fact;
    }
%}

/* Rule Section */
%%

[0-9]+ {
    if (isPrime(atoi(yytext)))
        printf("%s is a prime number", yytext);
    else
        printf("%s is not a prime number", yytext);
}

.+ {
    printf("Invalid input");
}



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