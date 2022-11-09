#include <stdio.h>

int main()
{
	int skaicius = 0;

	printf("Iveskite skaiciu\n");
	scanf("%d", &skaicius);

	if(skaicius > 0)
	{
		for(int i = 9; i >= 0; i--)
		{
			for(int u = skaicius; u > 0; u /= 10)
			{	
				if(u % 10 == i)
				{
					printf("%d", i);
				}
			}
		}
	}

	else
	{
		skaicius *= -1;

		for(int i = 0; i >= -9 ; i--)
		{
			for(int u = skaicius; u > 0; u /= 10)
			{	
				if(u % 10 * -1  == i)
				{
					printf("%d", i);
				}
			}
		}
	}

	printf("\n");

	return 0;
}
