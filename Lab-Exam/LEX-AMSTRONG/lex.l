/* Lex Program to check Amstrong Number */

%{
    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>
    #include <math.h>

    int isAmstrong(int n)
    {
        int sum = 0, temp = n, rem, count = 0;

        while (temp != 0)
        {
            temp /= 10;
            count++;
        }

        temp = n;
        while (temp != 0)
        {
            rem = temp % 10;
            sum += pow(rem, count);
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


// Algorithm

// 1. Read input from file.
// 2. Send input to yylex() function.
// 3. yylex() function will check for the pattern.
// 4. If pattern matches, it will call the function for checking Amstrong Number.
// 5. If Amstrong Number, it will print "Amstrong Number".
// 6. If not Amstrong Number, it will print "Not Amstrong Number".
// 7. If input is invalid, it will print "Invalid input".
// 8. Stop.

