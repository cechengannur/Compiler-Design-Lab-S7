/* Lex Program to check Palindrome Number */

%{
    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>

    int isPalindrome(int n)
    {
        int rev = 0, temp = n;
        while (temp != 0)
        {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }
        return rev == n;
    }
%}

/* Rule Section */
%%

[0-9]+ {
    if (isPalindrome(atoi(yytext)))
        printf("Palindrome Number");
    else
        printf("Not a Palindrome Number");

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
