#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	char choice;
	menu(choice);
	switch (choice)
	{
	case 'A':
		printf("Exercise 1");
		nprimi();
		break;
	case 'B':
		printf("Exercise 2");
		ricerca();
		break;
	case 'C':
		printf("Exercise 3");
		ordinamento();
		break;
	case 'X':
		printf("Exit");
		break;
	default:
		printf("Invalid choice");
		break;
	}
	return choice;
}
char menu(choice)
{
	char choice;
	do
	{
		printf("A. Excersise 1\n");
		printf("B. Excersise 2\n");
		printf("C. Excersise 3\n");
		printf("X. Quit");
		scanf("%c", &choice);
	} while (choice != 'X');
	
}
void nprimi(){
int n;

	printf("Numero: ");
	scanf("%d", &n);

	bool prime = true;
	int i = 2;

	while (prime && i * i <= n)
	{
		if (n % i == 0)
			prime = false;
		i++;
	}

	if (prime && n > 1)
		printf("Il numero %d è primo\n", n);

	else
		printf("Il numero %d non è primo\n", n);
}
