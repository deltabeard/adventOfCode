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
	long	total_ribbon = 0;

	// For sorting.
	int	square[2];
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

			square[0] = lw;
			square[1] = wh;
			square[2] = hl;

			/* Bubble sort */
			for(int j = 0; j < 2; j++)
			{
				for(int k = 0; k < 2; k++)
				{
					if(square[k] > square[k+1])
					{
						int temp = square[k+1];
						square[k+1] = square[k];
						square[k] = temp;
					}
				}
			}

			/* Debug to check bubble sort */
			printf("Sort from lowest: %d, %d, %d\n", square[0],
					square[1], square[2]);

			total = total + (lw + wh + hl) + (square[0] / 2);

			dimensions[0] = length;
			dimensions[1] = width;
			dimensions[2] = height;

			/* Bubble sort for Ribbpn */
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

			total_ribbon = total_ribbon + ((dimensions[0] * 2) +
					(dimensions[1] * 2) + (length * width * height));

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

	printf("Total wrapping: %ld, Total ribbon: %ld\n", total, total_ribbon);

	fclose(fp);

	return 0;
}
