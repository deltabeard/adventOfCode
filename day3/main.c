/* Day 3: Perfectly Spherical Houses in a Vacuum
 *
 * Mahyar Koshkouei
 */

/* I can't guarantee how large of an area Santa is going to visit, so defining
 * a very large array.
 */
#define ARRAY_SIZE 1000
#define ARRAY_MID (ARRAY_SIZE / 2)

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE		*fp;
	char		char_buffer;
	static int	houses[ARRAY_SIZE][ARRAY_SIZE];
	int		x = ARRAY_MID;
	int		y = ARRAY_MID;
	int		houses_with_presents = 0;

	fp = fopen("input.txt", "r");
	if(fp == NULL)
	{
		puts("Unable to open file.");
		return 1;
	}

	while((char_buffer = fgetc(fp)) != EOF)
	{
		/* Delivery at the starting location */
		houses[x][y]++;

		switch(char_buffer) {
			case '^' :
				y++;
				break;
			case '>' :
				x++;
				break;
			case 'v' :
				y--;
				break;
			case '<' :
				x--;
				break;
			default :
				printf("Invalid character \"%c\" found.\n",
						char_buffer);
				return 1;
		}

		/* Delivery at destination location */
		houses[x][y]++;

		/* Debug: Avoiding seg failts. */
		if( x == 1 || x == ARRAY_SIZE || y == 1 || y == ARRAY_SIZE)
		{
			printf("Approaching array limit. x = %d, y = %d\n",
					x, y);
			return 1;
		}
	}

	fclose(fp);

	for(int x = 0; x < ARRAY_SIZE; x++)
	{
		for(int y = 0; y < ARRAY_SIZE; y++)
		{
			if(houses[x][y] > 0)
				houses_with_presents++;
		}
	}

	printf("Houses with at least one present: %d\n", houses_with_presents);

	return 0;
}
