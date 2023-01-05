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


// Algorithm

// 1. Read input from file.
// 2. Send input to yylex() function.
// 3. yylex() function will check for the pattern.
// 4. If pattern matches, then it will call the function isPalindrome().
// 5. isPalindrome() function will check if the number is palindrome or not.
// 6. If the number is palindrome, then it will print Palindrome Number.
// 7. If the number is not palindrome, then it will print Not a Palindrome Number.
// 8. If the input is invalid, then it will print Invalid input.
// 9. Stop the program.