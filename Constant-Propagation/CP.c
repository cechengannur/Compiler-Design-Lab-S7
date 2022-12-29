// ALGORITHM:

// 1. For all 4-tuples do 
//    1.1 get next 4-tuple
//    1.2 If the operator is "Label" then 
//         1.2.1 free the constant table
//         1.2.2 write the 4-tuple
//  1.3 If either or both of the operands are in the constant table then
//        1.3.1 substitute the constant value(s) for the operand(s) 
//        1.3.2 if either of the operands are intermediate results then  
//                1.3.2.1 remove those operand(s)
// from the constant table.1.4 if 4 - tuple operand(s)
// are constant then 1.4.1 if operator is "JPCT" then 1.4.1.1 if the operand is true then 1.4.1.1.1 replace the JPCT with JP 1.4.1.1.2 write the new 4 - tuple else 1.4.1.1.3 eliminate the 4 - tuple 1.4.2 if operator is "=" then 1.4.2.1 place the variable and constant in the constant table 1.4.2.2 write the 4 - tuple with the constant operand 1.4.3 else 1.4.3.1 Perform the operation.1.4.3.2 Place the intermediate result name and constant value in the constant table.Else 1.4.4 write the 4 - tuple Consider the following sequence.

//     PROGRAM :

#include <stdio.h>
#include <string.h>
#include <ctype.h>
void input();
void output();
void change(int p, char *res);
void constant();
struct expr
{
    char op[2], op1[5], op2[5], res[5];
    int flag;
} arr[10];
int n;
void main()
{
    input();
    constant();
    output();
}
void input()
{
    int i;
    printf("\n\nEnter the maximum number of  expressions : ");
    scanf("%d", &n);
    printf("\nEnter the input : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", arr[i].op);
        scanf("%s", arr[i].op1);
        scanf("%s", arr[i].op2);
        scanf("%s", arr[i].res);
        arr[i].flag = 0;
    }
}
void constant()
{
    int i;
    int op1, op2, res;
    char op, res1[5];
    for (i = 0; i < n; i++)
    {
        if (isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0]) || strcmp(arr[i].op, "=") == 0) /*if both digits, store them in variables*/
        {
            op1 = atoi(arr[i].op1);
            op2 = atoi(arr[i].op2);
            op = arr[i].op[0];
            switch (op)
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                res = op1 / op2;
                break;
            case '=':
                res = op1;
                break;
            }
            sprintf(res1, "%d", res);
            arr[i].flag = 1; /*eliminate expr and replace any operand below that uses result of this expr */
            change(i, res1);
        }
    }
}
void output()
{
    int i = 0;
    printf("\nOptimized code is : ");
    for (i = 0; i < n; i++)
    {
        if (!arr[i].flag)
        {
            printf("\n%s %s %s %s", arr[i].op, arr[i].op1, arr[i].op2, arr[i].res);
        }
    }
}
void change(int p, char *res)
{
    int i;
    for (i = p + 1; i < n; i++)
    {
        if (strcmp(arr[p].res, arr[i].op1) == 0)
            strcpy(arr[i].op1, res);
        else if (strcmp(arr[p].res, arr[i].op2) == 0)
            strcpy(arr[i].op2, res);
    }
}

// INPUT :

//     Enter the maximum number of expressions : 4

//     Enter the input :
//     = 3 - a
//     + a b t1
//     + a c t2
//     + t1 t2 t3

// OUTPUT :

//     Optimized code is :
//     + 3 b t1 
//     + 3 c t2
//     + t1 t2 t3