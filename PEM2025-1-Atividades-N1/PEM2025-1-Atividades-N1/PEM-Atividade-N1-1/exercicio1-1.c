//Nome: Henrique de Castro Pereira, RA: 2040482422035

#include <stdio.h>

int main(){

    int N, i, j, k, l, m;
    float PE[4], AC[5], PP[10], EB[3];
    float nPE, nAC, nPP, nEB; //Aqui eu declarei as variaveis

printf("Digite uma quantidade de ate 50 candidatos: \n");
scanf("%d", &N); //Pedi para o usuario digitar a quantidade de candidatos

    char nome[N][100];
    float snPE[N], snAC[N], snPP[N], snEB[N], NF[N]; 
    //Criei os vetores que vão armazenar as somas dentro do loop.
    //Também criei um vetor de strings para armazenar o nome de cada candidato, definindo o limite de caracteres para 100.

if(N<=50){
    for(i = 0; i < N; i++){ 
        printf("Digite o nome do %do candidato: \n", i+1);
        scanf("%s", nome[i]); 
        //Utilizei o condicional "if" para permitir que essa parte do codigo funcione apenas se tiver uma quantidade igual ou inferior a 50 candidatos.
        //Criei um loop que é limitado pelo numero de candidatos "com a variavel N" 
        //Pedi para o usuario digitar o nome do candidato e armazenei no vetor com base na posição atual da variavel i.
    
        nPE = nAC = nPP = nEB = 0;
        //Aqui eu defino que todas as somas das notas vão começar em 0, para depois ir somando as notas conforme o usuario digita.

        for(j = 0; j < 4; j++){
            printf("Digite a %do nota da PE: \n", j+1);
            scanf("%f", &PE[j]);

            nPE += PE[j];
        }
            for(k = 0; k < 5; k++){
                printf("Digite a %do nota da AC: \n", k+1);
                scanf("%f", &AC[k]);

                nAC+= AC[k];
            }
                for(l = 0; l < 10; l++){
                    printf("Digite a %do nota da PP: \n", l+1);
                    scanf("%f", &PP[l]);

                    nPP+= PP[l];
                }
                    for(m = 0; m < 4; m++){
                        printf("Digite a %do nota da EB: \n", m+1);
                        scanf("%f", &EB[m]);

                        nEB+= EB[m];

        }
        //Nesta parte eu fiz laços de repetição 4 for idênticos para pedir pro usuario digitar as notas dos candidatos.
        //Os valores são armazenadas em vetores com limites baseados na quantidade de notas por atividades, 
        //logo após o valor de cada nota é somado a e atribuido na variavel n(X).

    snPE[i] = nPE;
    snAC[i] = nAC;
    snPP[i] = nPP;
    snEB[i] = nEB;
        //Aqui eu atribuo a soma das notas do candidato à respectiva posição em que ele ocupa segundo a variavel i.

    NF[i] = ((snPE[i]*0.3) + (snAC[i]*0.1) + (snPP[i]*0.4) + (snEB[i]*0.2));
    }
        //Defino então a "nota final" do usuario com a formula fornecida e armazeno ela em um vetor que possue a posição de cada candidato.
    
    float NF_aux;
    char Nome_aux[100];
        //Criei duas variaveis auxiliares

    for(i = 0; i < N-1; i++){
        for(j = i+1; j<N; j++){
            if (NF[i] < NF[j]){

                NF_aux = NF[i];
                NF[i] = NF[j];
                NF[j] = NF_aux;
                //Pesquisei na internet e utilizei o algoritmo chamado Bubble Sort.
                //Basicamente é utilizado um loop aninhado junto de laço condicional if para verificar se a nota
                //do usuario "i" é maior que o do usuario "j".
                //Caso a condição for verdadeira, é utilizada uma variavel auxiliar para armazenar a nota que estava na variavel NF[i]
                //e depois substituir o conteudo dela pelo da variavel NF[j]. 
                //Por fim, a nota que estava na variavel temporavel é atribuida a NF[j] 
                //assim fazendo com que as maiores notas fiquem nas primeiras posições

                for(k = 0; k < 100; k++){

                    Nome_aux[k] = nome[i][k];
                    nome[i][k] = nome[j][k];
                    nome[j][k] = Nome_aux[k];
                //Esse é um codigo semelhante, porém ele troca letra por letra dos nomes dos candidatos.
                    
                }
            }
        }
    }

    printf("Lista de classificacao:\n");

    for (i=0; i < (N < 15 ? N : 15); i++){

        printf("%do Candidato: %s  -Media Final: %.1f\n", i+1, nome[i], NF[i]);
    }
    //foi criado aqui um laço usando os operadores ternarios para limitar o tamanho da lista a 15 aprovados caso "N" seja maior que 15,
    //caso contrario ele imprimira o numero equivalente a "N"
} else {
    
    printf("A quantidade maxima e de 50 candidatos, tente novamente");
    //Caso "N" for maior que 50 sera retornada uma mensagem para o usuario
}
    return 0;
}
   