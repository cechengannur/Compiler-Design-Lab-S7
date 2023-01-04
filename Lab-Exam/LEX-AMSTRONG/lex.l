/* Lex Program to check Amstrong Number */

%{
    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>

    int isAmstrong(int n)
    {
        int sum = 0, temp = n, rem;
        while (temp != 0)
        {
            rem = temp % 10;
            sum += rem * rem * rem;
            temp /= 10;
        }
        if (sum == n)
            return 1;
        else
            return 0;
    }
%}

/* Rule Section */
%%

[0-9]+ {
    if (isAmstrong(atoi(yytext)))
        printf("Amstrong Number");
    else
        printf("Not Amstrong Number");

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
