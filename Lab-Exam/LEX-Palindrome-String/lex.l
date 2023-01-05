/* Lex Program to check Palindrome String */

%{
    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>

    // function to check palindrome
    int isPalindrome(char str[])
    {
        // Start from leftmost and rightmost corners of str
        int l = 0;
        int h = strlen(str) - 1;

        // Keep comparing characters while they are same
        while (h > l)
        {
            if (str[l++] != str[h--])
            {
                return 0;
            }
        }
        return 1;
    }
%}

/* Rule Section */
%%

[a-zA-Z]+ {
    if (isPalindrome(yytext)) {
        printf("%s is a palindrome\n", yytext);
    }
    else {
        printf("%s is not a palindrome\n", yytext);
    }
}

. {
    // do nothing, just skip the character
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
// 5. isPalindrome() function will check if the string is palindrome or not.
// 6. If the string is palindrome, then it will print Palindrome string.
// 7. If the string is not palindrome, then it will print Not a Palindrome string.
// 8. If the input is invalid, then it will print Invalid input.
// 9. Stop the program.