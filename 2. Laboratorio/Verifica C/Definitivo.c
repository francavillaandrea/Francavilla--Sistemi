#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool IsPrime(int n);
void SelSort(int arr[], int len);
void PrintArr(int arr[], int len, char msg[100]);
void SrNotOrdRip(int arr[], int len);
void SrNotOrdDis(int arr[], int len);
void SrOrdRip(int arr[], int len);
void SrOrdDis(int arr[], int len);

int main()
{
	char choice; 
	char opt[4] = {'q', 'p', 'o', 'r'};
	int n;

	do
	{
		system("clear");
		printf("P. Numero primo\n");
		printf("O. Ordina array\n");
		printf("R. Ricerca array\n");
		printf("Q. Esci\n");
		scanf("%c", &choice);

		switch(choice)
		{
			case 'p':
				printf("Numero:");
				scanf("%d", &n);
				if(IsPrime(n))
				{
					printf("Primo\n");
				}
				else
				{
					printf("Non primo\n");
				}

				break;

			case 'o':
				int arr1[5] = { 7, 3, 2, 5, 1};
				int size1 = sizeof(arr1) / sizeof(int);
				char msg1[100] = "Array prima dell'ordinamento: ";	
				char msg2[100] = "Array dopo l'ordinamento: ";

				PrintArr(arr1, size1, msg1);
				SelSort(arr1, size1);
				PrintArr(arr1, size1, msg2);

				break;

			case 'r':
				int rChoice;
				
				system("clear");
				printf("1. Disordinato ripetizioni\n");
				printf("2. Disordinato distinti\n");
				printf("3. Ordinato ripetizioni\n");
				printf("4. Ordinato distinti\n");
				scanf("%d", &rChoice);

				switch(rChoice)
				{
					case 1:
						int arr2[] = {5, 2, 5, 7, 3}; 
						int len2 = sizeof(arr2) / sizeof(int);
						char msg3[100]; 
						
						PrintArr(arr2, len2, msg3); 
						SrNotOrdRip(arr2, len2);
						break;

					case 2:
						int arr3[] = {5, 2, 4, 7, 3}; 
						int len3 = sizeof(arr3) / sizeof(int);
						
						PrintArr(arr3, len3, msg3); 
						SrNotOrdDis(arr3, len3);
						break;

					case 3:
						int arr4[] = {2, 2, 3, 5, 7}; 
						int len4 = sizeof(arr4) / sizeof(int);
						
						PrintArr(arr4, len4, msg3); 
						SrOrdRip(arr4, len4);
						break;
						
					case 4:
						int arr5[] = {2, 3, 5, 7, 9};
						int len5 = sizeof(arr5) / sizeof(int);

						PrintArr(arr5, len5, msg3); 	
						SrOrdDis(arr5, len5);
						break;
				}
		}
	}
	while(strchr(opt, choice) == NULL);
}

void PrintArr(int arr[], int len, char msg[100])
{
	printf("%s", msg);
	for(int i = 0; i < len; i++)
	{
		printf("%d", arr[i]); 
	}
	printf("\n");
}

bool IsPrime(int n)
{
    if(n <= 1 || n % 2 == 0)
        return false;
    if(n == 2)
        return true;
    
	int i = 3;

	while(i * i <= n)
	{
		if (n % i == 0)
		{
			return false;
		}
		i+=2;
	}

	return true;
}

void Swap(int *v1, int *v2)
{
	int aus = *v1;
	*v1 = *v2;
	*v2 = aus;
}

void SelSort(int arr[], int len)
{
	int posmin;

	for(int i = 0; i < len - 1; i++)
	{
		posmin = i;

		for(int j = i + i; j < len; j++)
		{
			if(arr[j] < arr[posmin])
			{
				posmin = j;
			}
		}

		if(posmin != i)
		{
			Swap(&arr[posmin], &arr[i]);
		}
	}
}

void SrNotOrdRip(int arr[], int len)
{
	int n;
	
	printf("Numero da cercare: ");
	scanf("%d", &n);
	
	bool found = false;
	
	for(int i = 0; i < len; i++)
	{
		if(arr[i] == n)
		{
			printf("\n%d trovato in posizione %d\n", n, i);
			found = true;
		}
	}
	
	if(!found)
	{
		printf("\n%d non trovato \n", n);
	}
}

void SrNotOrdDis(int arr[], int len)
{
	int n;
	
	printf("Numero da cercare: ");
	scanf("%d", &n);
	
	int i = 0;
	
	while(arr[i] != n && i != len - 1)
	{
		i++;
	}
	
	if(arr[i] == n)
	{
		printf("\n%d trovato in posizione %d\n", n, i);
	}
	else
	{
		printf("\n%d non trovato\n", n);
	}
}

void SrOrdRip(int arr[], int len)
{
	int n;
	
	printf("Numero da cercare: ");
	scanf("%d", &n);
	
	int i = 0;
	bool found = false, sup = false;
	
	while(!sup && i <= len - 1)
	{
		if(arr[i] == n)
		{
			printf("\n%d trovato in posizione %d\n", n, i);
			found = true;
			i++;
		}
		else
		{
			if(arr[i] > n)
			{
				sup = true;
			}
			else
			{
				i++;
			}
		}
	}
	
	if(!found)
	{
		printf("\n%d non trovato\n", n);
	}
}

void SrOrdDis(int arr[], int len)
{
	int n;
	
	printf("Numero da cercare: ");
	scanf("%d", &n);
	
	int i = 0;
	
	while(arr[i] < n && i != len - 1)
	{
		i++;
	}
	
	if(arr[i] == n)
	{
		printf("\n%d trovato in posizione %d\n", n, i);
	}
	else
	{
		printf("\n%d non trovato\n", n);
	}
}
