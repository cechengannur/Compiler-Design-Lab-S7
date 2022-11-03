#include <stdio.h>
#include <string.h>
#include <ctype.h>

int num_of_productions;
char production_set[20][20];

void FIRST(char Result[], char c);
void add_to_Result_Set(char result[], char c);

int main()
{
	int i;
	char choice;
	char c;
	char result[30];

	printf("Enter the no. of productions : ");
	scanf("%d", &num_of_productions);
	puts("Enter the production string like \"E=E+T\" \nand epsilon as #");

	for (i = 0; i < num_of_productions; ++i)
	{
		printf("Enter production Number %d : ", i + 1);
		scanf("%s", production_set[i]);
	}
	do
	{
		// memset( result, '\0', sizeof(result) );

		printf("Find FIRST of --> ");
		scanf(" %c", &c);

		FIRST(result, c);

		printf("\nFirst (%c) = { ", c);
		for (i = 0; i < strlen(result); ++i)
			printf("%c ", result[i]);
		puts(" }");

		printf("Press \'y\' or \'Y\' to continue : ");
		scanf(" %c", &choice);
	} while (choice == 'y' || choice == 'Y');

	return 0;
}

void FIRST(char Result[], char c)
{
	int i, j, k;
	char Sub_Result[20];
	int found_epsilon;

	Sub_Result[0] = '\0';
	Result[0] = '\0';

	if (!(isupper(c)))
	{
		add_to_Result_Set(Result, c);
		return;
	}

	for (i = 0; i < num_of_productions; ++i)
	{
		if (production_set[i][0] == c)
		{
			if (production_set[i][2] == '#')
				add_to_Result_Set(Result, '#');
			else
			{
				j = 2;

				while (production_set[i][j] != '\0')
				{
					found_epsilon = 1;

					FIRST(Sub_Result, production_set[i][j]);

					for (k = 0; k < strlen(Sub_Result); ++k)
						add_to_Result_Set(Result, Sub_Result[k]);

					for (k = 0; k < strlen(Sub_Result); ++k)
						if (Sub_Result[k] == '#')
						{
							found_epsilon = 0;
							break;
						}
					if (found_epsilon)
						break;
					j++;
				}
			}
		}
	}
	return;
}

void add_to_Result_Set(char Result[], char val)
{
	int k;
	for (k = 0; Result[k] != '\0'; ++k)
	{
		if (Result[k] == val)
		{
			return;
		}
	}
	Result[k] = val;
	Result[k + 1] = '\0';
}
