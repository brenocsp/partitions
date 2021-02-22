#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printarVetor (int const *vetor, int const tamanhoImpressao) {
    for (int  i = 0; i < tamanhoImpressao; i++) {
        printf("%d ", vetor[i]);
    }
}

void gerarParticoes(int const n) {
    int totalParticoes = 0;
    int posUltimoElemento = 0;
    int valorParaAtualizar = 0;
    int* particoes = malloc(sizeof(int)*n);

    particoes[posUltimoElemento] = n;

    while (true) {
        printarVetor(particoes, posUltimoElemento + 1);
        printf("\n");
        totalParticoes++;
        
        valorParaAtualizar = 0;

        while (particoes[posUltimoElemento] == 1 && posUltimoElemento >= 0) {
            valorParaAtualizar = valorParaAtualizar + particoes[posUltimoElemento];
            posUltimoElemento--;

            if (posUltimoElemento == -1) {
                printf("%d\n", totalParticoes);
                free(particoes);
                return;
            }
        }

        valorParaAtualizar++;
        particoes[posUltimoElemento]--;

        while (valorParaAtualizar > particoes[posUltimoElemento]) {
            particoes[posUltimoElemento + 1] = particoes[posUltimoElemento];
            valorParaAtualizar = valorParaAtualizar - particoes[posUltimoElemento];
            posUltimoElemento++;
        }

        particoes[posUltimoElemento + 1] = valorParaAtualizar;
        posUltimoElemento++;
    }

}

int main(void) {
    int n;
    printf("Digite um número para gerar todas as suas partições não-ordenadas e a quantidade de partições geradas: ");
    scanf("%d", &n);
    gerarParticoes(n);

    return 0;
}