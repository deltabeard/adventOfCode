/* Day 5:Doesn't He Have Intern-Elves For This?
 *
 * Mahyar Koshkouei
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
 * Checks if the input string contains at least three vowels.
 *
 * \param	char*	Input string to check.
 * \return	True if at least three vowels found, else false.
 */
bool check_vowel(char *str)
{
	int number_of_vowels = 0;
	
	for(int j = 0; j < 16; j++)
	{
		switch(str[j]) {
			case 'a' :
			case 'e' :
			case 'i' :
			case 'o' :
			case 'u' :
				number_of_vowels++;
				break;
		}
	}

	if(number_of_vowels >= 3)	
		return true;

	return false;
}

/*
 * Checks that the input string does not contain the strings "ab", "cd", "pq",
 * "xy".
 *
 * \param	char*	Input string to check.
 * \return	True if the strings listed above *can not* be found in the
 * 		input string, else false.
 */
bool check_magic_strings(char *str)
{
	if(strstr(str, "ab") != NULL)
		return false;

	if(strstr(str, "cd") != NULL)
		return false;

	if(strstr(str, "pq") != NULL)
		return false;

	if(strstr(str, "xy") != NULL)
		return false;

	return true;
}

/*
 * Checks if the input string contains at least one letter that appears twice
 * in a row.
 *
 * \param	char*	Input string to check.
 * \return		True if input string contains at least one letter that
 * 			appears twice in a row, else false.
 */
bool check_double_letter(char *str)
{
	for(int j = 0; j < 16; j++)
	{
		if(str[j] == str[j+1])
			return true;
	}

	return false;
}

int main(int argc, char *argv[])
{
	FILE		*fp;
	FILE		*fpdbg;
	char		char_buffer;
	static char	buffer[17];
	int		i = 0;
	int 		nice = 0;

	if(argc >= 2)
		fp = fopen(argv[1], "r");
	else
		fp = fopen("input.txt", "r");

	if(fp == NULL)
	{
		puts("Unable to open file.");
		printf("To run: %s FILE\n", argv[0]);
		puts("FILE is input.txt by default.");
		return 1;
	}

	fpdbg = fopen("stdout", "w+");

	while((char_buffer = fgetc(fp)) != EOF)
	{
		if((buffer[i] = char_buffer) == '\n')
		{
			fprintf(fpdbg, "\nNext string\n");

			if(check_magic_strings(buffer))
				fprintf(fpdbg, "Didn't find magic strings\n");

			if(check_vowel(buffer))
				fprintf(fpdbg, "Found >= 3 vowels\n");
			
			if(check_double_letter(buffer))
				fprintf(fpdbg, "Found double letters\n");

			if(check_magic_strings(buffer) &&
					check_vowel(buffer) &&
					check_double_letter(buffer))
			{
				fprintf(fpdbg, "String passed!\n");
				nice++;
			}
			else
				fprintf(fpdbg, "String Failed tests!\n");

			/* Clear buffer for next line in file */
			memset(&buffer, '\0', sizeof(buffer));
			i = -1;
		}

		i++;
	}

	fclose(fp);

	fprintf(fpdbg, "Number of nice strings: %d\n", nice);
	printf("Number of nice strings: %d\n", nice);

	return 0;
}
