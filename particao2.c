#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printarVetor (int const *vetor, int const tamanhoImpressao) {
    for (int  i = 0; i < tamanhoImpressao; i++) {
        printf("%d ", vetor[i]);
    }
}

int temNumeroRepetido (int const *vetorOrdenado, int const tamanho) {
    for (int  i = 0; i < tamanho; i++) {
        if (i+1 != tamanho && vetorOrdenado[i] == vetorOrdenado[i+1]) { 
            return 1;
        }
    }
    return 0;
}

void gerarParticoesDistintas(int const n, int const k) {
    int totalParticoes = 0;
    int posUltimoElemento = 0;
    int valorParaAtualizar = 0;
    int* particoes = malloc(sizeof(int)*n);

    particoes[posUltimoElemento] = n;

    while (true) {
        if (posUltimoElemento + 1 == k && temNumeroRepetido(particoes, posUltimoElemento + 1) == 0) { 
            printarVetor(particoes, posUltimoElemento + 1);
            printf("\n");
            totalParticoes++;
        }

        valorParaAtualizar = 0;

        while (particoes[posUltimoElemento] == 1 && posUltimoElemento >= 0) {
            valorParaAtualizar = valorParaAtualizar + particoes[posUltimoElemento];
            posUltimoElemento--;

            if (posUltimoElemento < 0) {
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
    int n, k;
    printf("Digite números n e k para gerar todas as partições de n por k inteiros distintos e a quantidade de partições geradas: ");
    scanf("%d %d", &n, &k);
    gerarParticoesDistintas(n, k);

    return 0;
}