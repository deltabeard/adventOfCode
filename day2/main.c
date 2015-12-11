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
	char	char_buffer;
	char	buffer[20];
	int	i = 0;
	int	length;
	int	width;
	int	height;
	int	lw;	// 2*l*w
	int	wh;	// 2*w*h
	int	hl;	// 2*h*l
	long	total = 0;

	// For sorting
	int	dimensions[2];

	fp = fopen("input.txt", "r");
	if(fp == NULL)
	{
		puts("Unable to open file.");
		return 1;
	}

	while((char_buffer = fgetc(fp)) != EOF)
	{
		if((buffer[i] = char_buffer) == '\n')
		{
			sscanf(buffer, "%dx%dx%d", &length, &width, &height);

			/* Debug to check sscanf */
			printf("length %d, width %d, height %d\n", length,
					width, height);

			lw = 2 * length * width;
			wh = 2 * width * height;
			hl = 2 * height * length;

			dimensions[0] = lw;
			dimensions[1] = wh;
			dimensions[2] = hl;

			/* Bubble sort */
			for(int j = 0; j < 2; j++)
			{
				for(int k = 0; k < 2; k++)
				{
					if(dimensions[k] > dimensions[k+1])
					{
						int temp = dimensions[k+1];
						dimensions[k+1] = dimensions[k];
						dimensions[k] = temp;
					}
				}
			}

			/* Debug to check bubble sort */
			printf("Sort from lowest: %d, %d, %d\n", dimensions[0],
					dimensions[1], dimensions[2]);

			total = total + (lw + wh + hl) + (dimensions[0] / 2);

			// Resetting variables
			length = 0;
			width = 0;
			height = 0;

			/* Clear buffer for next line in file */
			memset(&buffer, '\0', sizeof(buffer));
			i = -1;
		}

		i++;
	}

	printf("Total: %ld\n", total);

	fclose(fp);

	return 0;
}
