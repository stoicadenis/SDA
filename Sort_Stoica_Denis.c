#include<stdio.h>
#include<stdlib.h>

int citire(int a[])
{
    FILE *f;
    int i=0;
    if ((f = fopen("sortare.txt", "rt")) == NULL) 
    {
        printf("Fisierul nu a fost gasit");
    } 
    else 
    {
        while (!feof(f))
        {
            fscanf(f,"%d",&a[i]);
            i++;
        }

        fclose(f);
    }
    return i;
}

void afisare(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");
}

void insertie(int a[], int n)
{
    int i,j=0,aux;
    for(i=1;i<n;i++)
    {
        aux=a[i];
        j=i-1;
        while(aux<a[j]&&j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=aux;
    }
}

void selectie(int a[], int n)
{
    int i,j,kmin,min;
    for(i=0;i<n;i++)
    {
        kmin=i;
        min=a[i];
        for(j=i+1;j<n;j++)
        if(min>a[j])
        {
            kmin=j;
            min=a[j];
        }
        a[kmin]=a[i];
        a[i]=min;
    }
}

void amestecare(int a[], int n)
{
    int s=1,d=n-1,k=n-1,i,aux;
    do
    {
        for(i=d;i>=s;i--)
        if(a[i-1]>a[i])
        {
            aux=a[i];
            a[i]=a[i-1];
            a[i-1]=aux;
            k=i;
        }
        s=k+1;
        for(i=s;i<=d;i++)
        if(a[i-1]>a[i])
        {
            aux=a[i-1];
            a[i-1]=a[i];
            a[i]=aux;
            k=i;
        }
        d=k-1;
    } while (s<=d); 
}

void bubblesort(int a[], int n)
{
    int i,aux,k;
    do
    {
        k=1;
        for(i=1;i<n;i++)
        if(a[i]<a[i-1])
        {
            aux=a[i];
            a[i]=a[i-1];
            a[i-1]=aux;
            k=0;
        }      
    } while(!k);  
}

void selectie_performanta(int a[], int n)
{
    int i,j,kmin,min,aux;
    for(i=0;i<n;i++)
    {
        kmin=i;
        for(j=i+1;j<n;j++)
        if(a[kmin]>a[j])
        kmin=j;
        aux=a[kmin];
        a[kmin]=a[i];
        a[i]=aux;
    }
}

int main()
{
    int a[20],n;
    n=citire(a);
    printf("Tabloul initial: "); afisare(a,n);
    insertie(a,n); printf("Insertie: "); afisare(a,n);
    selectie(a,n); printf("Selectie: "); afisare(a,n);
    amestecare(a,n); printf("Amestecare: "); afisare(a,n);
    bubblesort(a,n); printf("Bubblesort: "); afisare(a,n);
    selectie_performanta(a,n); printf("Selectie performanta: "); afisare(a,n);
    return 0;
}