#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int *vetor = NULL; 
    int tamanho = 0;
    int capacidade = 1;
    int numero;
 
    while (1) {
        printf("Digite um numero (ou um numero negativo para parar): ");
        scanf("%d", &numero);
 
        if (numero < 0) {
            break; 
        }
 
        if (tamanho == capacidade) {
            capacidade *= 2;
            int *temp = (int *)realloc(vetor, capacidade * sizeof(int));
 
            if (temp == NULL) {
                printf("Erro ao realocar memoria.\n");
                free(vetor);
                return 1;
            }
 
            vetor = temp;
        }
 
        vetor[tamanho] = numero;
        tamanho++;
    }
 
    printf("Vetor lido: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
 
    free(vetor);
 
    return 0;
}