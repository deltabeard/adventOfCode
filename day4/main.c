/* Day 4: The Ideal Stocking Stuffer
 *
 * Mahyar Koshkouei
 */

#include <openssl/md5.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	unsigned char md[MD5_DIGEST_LENGTH];
	const char* key = "bgvyzdsv";
	int answer = 0;
	char concat_buf[50];
	char md5str[50];
	MD5_CTX c;
	int i;
	int found_five = 0;
	int found_six = 0;

	while(1)
	{
		sprintf(concat_buf, "%s%d", key, answer);

		MD5_Init(&c);
		MD5_Update(&c, concat_buf, strlen(concat_buf));
		MD5_Final(&(md[0]), &c);

		/* Converting MD5 to string */
		for(i = 0; i < 31; i++)
			sprintf(&md5str[i*2], "%02x", md[i]);

		md5str[i+1] = '\0';

		if(strncmp(md5str, "000000", 6) == 0)
		{
			printf("MD5 (6 zeroes) found: %s\n", md5str);
			printf("Answer: %d\n", answer);
			found_six = 1;
		}

		if((found_six == 1) && (found_five == 1))
			goto out;

		if(strncmp(md5str, "00000", 5) == 0)
		{
			printf("MD5 (5 zeroes) found: %s\n", md5str);
			printf("Answer: %d\n", answer);
			found_five = 1;
		}

		if((found_six == 1) && (found_five == 1))
			goto out;

		answer++;
	}

out:
	return 0;
}
