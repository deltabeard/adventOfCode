/* Day 2: I Was Told There Would Be No Math
 *
 * Mahyar Koshkouei
 */

// lxwxh

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE	*fp;
	char	*line = NULL;
	size_t	len = 0;
	ssize_t	token;
	char	token_s[100];
	/* We want to seperate the integers, so 'x' is the delimiter */
	const char delim = 'x';
	char	*saveptr, *str1;
	char	*subtoken;

	fp = fopen("input.txt", "r");
	if(fp == NULL)
	{
		puts("Unable to open file.");
		return 1;
	}

	while(fgetc(fp) != EOF)
	{
		while(
		// While loop every '\n'

	}

	while((token = getline(&line, &len, fp)) != -1)
	{
		snprintf(token_s, 100, "%zu", token);

		printf("%s\n", token_s);

		/*
		for(str1 = token_s; ; str1 = NULL)
		{
			subtoken = strtok_r(str1, delim, &saveptr);
			if (subtoken == NULL)
				break;
			printf(" --> %s\n", subtoken);
		}

		puts("Getto da ze!");
		*/
	}

	fclose(fp);

	if(line)
		free(line);

	return 0;
}
