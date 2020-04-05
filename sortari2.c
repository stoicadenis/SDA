#include<stdio.h>

int citire(int *a)
{
	FILE *f;
	int i = 0;
	if ((f = fopen("sortare2.txt", "rt")) == NULL)
		printf("Fisierul nu exista!");
	else
	{
		while (!feof(f))
		{
			i++;
			fscanf(f, "%d", &a[i]);
			

		}
		fclose(f);
	}
	return i;
}

void afisare(int *a, int n)
{
	int i;
	for (i = 1; i <=n; i++)
		printf("%d ", a[i]);
	    printf("\n");
}

void shellsort(int *a, int n)
{
	int i, j, k, w, kmin, min, h[3] = {3,2,1};
	for (w = 0; w < 3; w++)
	{
		k = h[w];
		for (i = k; i <=n; i++)
		{
			kmin = i;
			min = a[i];
			for (j = i + 1; j <=n; j++)
				if (min > a[j])
				{
					kmin = j;
					min = a[j];
				}
			a[kmin] = a[i];
			a[i] = min;
		}

	}

}

void quicksort(int s, int d, int *a)
{
	int i = s, j = d, m = (i + j) / 2, aux;
	do {
		while (a[i] < a[m] && i < d)
			i++;
		while (a[j] > a[m] && j > s)
			j--;
		if (i <= j)
		{
			aux = a[i];
			a[i] = a[j];
			a[j] = aux;
			i++;
			j--;
		}
	} while (i <= j);
	if (i < d) quicksort(i, d, a);
	if (j > s) quicksort(s, j, a);
}


int main()
{
	int a[20], n;
	n = citire(a);
	printf("Initial:   "); 
	afisare(a, n);
    shellsort(a, n);
	printf("Shellsort: "); 
	afisare(a, n);
    quicksort(1, n, a);
	printf("Quicksort: "); 
	afisare(a, n);
	return 0;
}