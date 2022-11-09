#include <stdio.h>

int main()
{
	printf("Iveskite 3 sveikuosius skaicius\n");
	int S[3] = {0};
	
	for(int i = 0; i < 3; i++)
	{
		scanf("%d", &S[i]);	
	}

	int MAX = S[0], MIN = S[0];

	for(int i = 0; i < 3; i++)
	{
		MAX = (MAX < S[i]) ? S[i] : MAX;
		MIN = (MIN > S[i]) ? S[i] : MIN;	
	}

	printf("Maximumas: %d Minimumas: %d\n", MAX, MIN);
}
