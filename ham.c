
#include <stdio.h>

int main()
{
	int d[7], rec[7], i, c1, c2, c3, c;
	printf("Enter the data bits:");
	scanf("%d%d%d%d", &d[0], &d[1], &d[2], &d[4]);
	d[6] = d[0] ^ d[2] ^ d[4];
	d[5] = d[0] ^ d[1] ^ d[4];
	d[3] = d[0] ^ d[1] ^ d[2];
	for (i = 0; i < 7; i++)
	{
		printf("%d\t", d[i]);
	}
	printf("Enter receive bits:");
	for (i = 0; i < 7; i++)
	{
		scanf("%d", &rec[i]);
	}
	c1 = rec[6] ^ rec[4] ^ rec[2] ^ rec[0];
	c2 = rec[5] ^ rec[4] ^ rec[1] ^ rec[0];
	c3 = rec[3] ^ rec[2] ^ rec[1] ^ rec[0];
	c = (c3 * 4) + (c2 * 2) + c1;
	if (c == 0)
	{
		printf("No error");
	}
	else
	{
		if (rec[7 - c] == 0)
		{
			rec[7 - c] = 1;
		}
		else
		{
			rec[7 - c] = 0;
		}
	}
	printf("Error occured in bit position %d\n", c);
	printf("After correction the msg will be:\n");
	for (i = 0; i < 7; i++)
	{
		printf("%d\t", rec[i]);
	}
}
