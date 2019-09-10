//Terrance Rutledge: This program takes in the ouput line length and then prompts the user to enter text until control-d is entered. It then reverses those strings and prints them out.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char s[100], r[100];
	int n, c, d;
	int lineLen;

	printf("Enter the output line length: ");
	scanf("%d", &lineLen);
	printf("Enter your text (control-d to exit) ");

	while(!feof(stdin)){
		gets(s);

		n = strlen(s);

		for (c = n - 1, d = 0; c >= 0; c--, d++)
			r[d] = s[c];

		r[d] = '\0';
	}
	printf("%*.s", lineLen, " ");	
	printf("%s\n", r);

	return 0;
}
