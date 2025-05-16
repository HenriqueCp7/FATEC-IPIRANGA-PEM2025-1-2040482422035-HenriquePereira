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

void insertionsort (int *vetor, int n)
{
    int i, j, chave;
    for (i=1; i < n; i++)
    {
        chave = vetor[i];
        j = i - 1;
        
        while (j >= 0 && vetor[j] > chave)
        {
            vetor[j+1] = vetor[j];
            j = j - 1;
        }
        vetor[j+1] = chave;
    }
}

int main ()
{
int n;

printf ("Digite quantos numeros voce quer ordenar: ");
scanf ("%d", &n);

int vetor [n];

printf ("Digite os valores do vetor:\n");
for (int i=0; i<n; i++)
{
    printf ("Digite o %do valor: ", i+1);
    scanf ("%d", &vetor[i]);
}

insertionsort (vetor,n);

printf ("\nVetor em ordem ascendente: \n");

mostrar_vetor (vetor, n);

    return 0;
}