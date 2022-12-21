// Grammar: E->2E2|3E3|4
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void main() {
	char buff[100];
	char rules[3][10] = {"2E2", "3E3", "4"};
	char stack[100];
	int top = -1;

	printf("Input String: ");
		scanf("%s", buff);
	strcat(buff, "$");

	int index = 0;

	do {
		if (top != -1) {
			int i;
			for (i = 0; i < 3; ++i)
				if (strstr(stack, rules[i]) != NULL)
					break;
			if (i < 3) {
				// Reduce
				char *p;
				p = strstr(stack, rules[i]);
				p[0] = 'E';
				//while (&(stack[top]) != p)
				//	stack[top--] = '\0';
				p[1] = '\0';
				top = (int)(p - stack);
			}
			else {
				// Shift
				stack[++top] = buff[index++];
				stack[top + 1] = '\0';

			}
		}
		else {
			// Input is finished
			if (buff[index] == '$')
				break;

			// Else shift again...
			stack[++top] = buff[index++];
			stack[top + 1] = '\0';
		}
	} while (index > 0 && buff[index - 1] != '$');

	if (strcmp(stack, "E$") == 0)
		printf("String Accepted\n");
	else
		printf("String Rejected\n");
}
