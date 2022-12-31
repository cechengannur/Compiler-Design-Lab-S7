#include <stdio.h>
int Fa[10][10][10], states[2][10], row = 0, col = 0, sr = 0, sc = 0, th = 0, in, stat, new_state[10][10], max_inp = -1, no_stat;
FILE *fp;
int search(int search_var)
{
    int i;
    for (i = 0; i < no_stat; i++)
        if (search_var == states[1][i])
            return 1;
    return 0;
}
int sort(int *arr, int count)
{
    int temp, i, j;
    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (arr[i] >= arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return 0;
}
int checkcon(int *arr, int *count) // for doing this {4,1}={1,2,1}=={1,2}
{
    int i, temp, j, k, c, t, m;
    for (i = 0; i < *count; i++)
    {
        if (arr[i] > row)
        {
            temp = arr[i];
            c = 0;
            t = 0;
            while (new_state[arr[i]][t] != -1)
            {
                t++;
                c++;
            }
            // right shift from ith postion (c-2) th time
            for (k = 0; k <= c - 2; k++)
            {
                for (j = 9; j >= i + 1 + k; j--)
                {
                    arr[j] = arr[j - 1];
                }
            }
            t = 0;
            for (j = i; j < c; j++)
            {
                arr[j] = new_state[temp][t];
                t++;
            }
        }
    }
    c = 0;
    for (i = 0; arr[i] != -1; i++)
        c++;
    *count = c;
    return 0;
}
int remove_duplicate(int *arr, int *count)
{
    int i, j = 0;
    for (i = 1; i < *count; i++)
    {
        if (arr[i] != arr[j])
        {
            j++;
            arr[j] = arr[i];
        }
    }
    *count = j + 1;
    return 0;
}
int check(int i, int j, int c, int *name) /// for checking is this a new state  or not
{
    int t, l, f;
    for (l = 0; l <= stat; l++)
    {
        t = 0;
        f = 0;
        while (Fa[i][j][t] != -1)
        {
            if (Fa[i][j][t] == new_state[l][t])
                t++;
            else
            {
                f = 1;
                break;
            }
        }
        if ((t == c) && !f)
        {
            *name = l;
            return 1;
        }
    }
    return 0;
}
int trans(int i ,int j,int t,int c,int *count,int *arr)//transition o/p for particular i/p on states
{
    int k = 0, co, temp;
    *count = 0;
    for (k = 0; k < c; k++)
    {
        temp = Fa[i][j][k];
        co = 0;
        while (Fa[temp][t][co] != -1)
        {
            arr[*count] = Fa[temp][t][co++];
            (*count)++;
        }
    }
    return 0;
}
int nfa2dfa(int start, int end)
{
    int j, t, c, i, k, count, arr[10], name, l;
    for (i = start; i <= end; i++)
    {
        for (j = 0; j <= max_inp; j++)
        {
            c = 0;
            t = 0;
            while (Fa[i][j][t] >= 0)
            {
                t++;
                c++;
            }
            if (c > 1)
            {
                if (check(i, j, c, &name) == 0)
                {
                    for (k = 0; k < c; k++)
                    {
                        new_state[stat][k] = Fa[i][j][k];
                        for (l = 0; states[1][l] != -1; l++)
                            if (new_state[stat][k] == states[1][l] && !search(stat))
                                states[1][no_stat++] = stat;
                    }
                    for (t = 0; t <= max_inp; t++)
                    {
                        count = 0;
                        for (k = 0; k < 10; k++)
                            arr[k] = -1;
                        trans(i, j, t, c, &count, arr);
                        checkcon(arr, &count);
                        sort(arr, count);
                        remove_duplicate(arr, &count);
                        for (k = 0; k < count; k++)
                            Fa[stat][t][k] = arr[k];
                    }
                    Fa[i][j][0] = stat++;
                    for (t = 1; t < c; t++)
                        Fa[i][j][t] = -1;
                }
                else
                {
                    Fa[i][j][0] = name;
                    for (t = 1; t < c; t++)
                        Fa[i][j][t] = -1;
                }
            }
        }
    }
    return 0;
}
int main()
{
    int i, j, k, flag = 0, start, end;
    char c, ch;
    fp = fopen("Nfa_ip.txt", "r+");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 10; j++)
            states[i][j] = -1;
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            new_state[i][j] = -1;
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            for (k = 0; k < 10; k++)
                Fa[i][j][k] = -1;
    while (fscanf(fp, "%d", &in) != EOF)
    {
        fscanf(fp, "%c", &c);
        if (flag)
        {
            states[sr][sc++] = in;
            if (c == '\n')
            {
                sr++;
                sc = 0;
            }
        }
        else if (c == '#')
        {
            flag = 1;
            Fa[row][col][th] = in;
        }
        else if (!flag)
        {
            Fa[row][col][th] = in;
            if (c == ',')
            {
                th++;
            }
            else if (c == '\n')
            {
                if (max_inp < col)
                    max_inp = col;
                col = 0;
                row++;
                th = 0;
            }
            else if (c != ',')
            {
                col++;
                th = 0;
            }
        }
    }
    no_stat = 0;
    i = 0;
    while (states[1][i++] != -1)
        no_stat++;
    stat = row + 1;
    start = 0;
    end = row;
    while (1)
    {
        nfa2dfa(start, end);
        start = end + 1;
        end = row;
        if (start > end)
            break;
    }
    printf("\n\nDFA IS : \n\n\n");
    for (i = 0; i <= max_inp; i++)
        printf("\t%d", i);
    printf("\n");
    printf("----------------------------\n");
    for (i = 0; i < stat; i++)
    {
        printf("%d-> |", i);
        for (j = 0; j <= max_inp; j++)
        {
            printf("%2d ", Fa[i][j][0]);
        }
        printf("\n");
    }
    printf("\n\n");
    printf("Total Number Of State Is : %d \n\n", stat);
    printf("Final States Are : ");
    for (i = 0; states[1][i] != -1; i++)
        printf("%d ", states[1][i]);
    printf("\n\n");
    return 0;
}

//Algorithm for NFA to DFA conversion



//Example