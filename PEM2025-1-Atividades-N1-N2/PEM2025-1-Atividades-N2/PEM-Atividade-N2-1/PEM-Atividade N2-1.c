#include <stdio.h>

void mostrar_vetor (int *vetor, int n)
{
    printf ("-> ");
        for (int i=0; i<n; i++)
        {
            printf ("%d, ", vetor[i]);
        }
    printf ("\n");
}

void bubblesort (int *vetor, int n)
{
    int i, j, temp;

    for (i=0; i < n-1; i++)
    {
        for (j=0; j < n-i-1; j++)
        {
            if (vetor[j] > vetor [j+1])
            {
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

int main ()
{

int n;

printf ("Digite quantos numeros voce quer ordenar: ");
scanf ("%d", &n);

int vetor [n];

printf ("Digite os valores do vetor: \n");
for (int i=0; i<n; i++)
{
    printf ("Digite o %do valor: ", i+1);
    scanf ("%d", &vetor[i]);
}

bubblesort (vetor,n);

printf ("\nVetor em ordem ascendente: \n");

mostrar_vetor (vetor, n);

    return 0;
}