#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int tamanho;
 
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
 
    int *vetor = (int *)malloc(tamanho * sizeof(int));
 
    if (vetor == NULL) {
        printf("Falha na alocacao de memoria.\n");
        return 1;
    }
 
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o valor para a posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }
 
    printf("Vetor lido: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
 
    free(vetor);
 
    return 0;
}