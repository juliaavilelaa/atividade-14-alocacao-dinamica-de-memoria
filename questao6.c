#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int *memoria = NULL;
    int tamanho_memoria = 0;
 
    printf("Digite o tamanho da memoria (em bytes, multiplo de sizeof(int)): ");
    scanf("%d", &tamanho_memoria);
 
    if (tamanho_memoria % sizeof(int) != 0) {
        printf("O tamanho da memoria deve ser um multiplo de sizeof(int).\n");
        return 1;
    }
 
    memoria = (int *)malloc(tamanho_memoria);
 
    if (memoria == NULL) {
        printf("Falha na alocacao de memoria.\n");
        return 1;
    }
 
    int opcao;
    int posicao, valor;
 
    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1. Inserir um valor em uma posicao\n");
        printf("2. Consultar um valor em uma posicao\n");
        printf("3. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
 
        switch (opcao) {
            case 1:
                printf("Digite a posicao (0 a %d): ", tamanho_memoria / sizeof(int) - 1);
                scanf("%d", &posicao);
                if (posicao < 0 || posicao >= tamanho_memoria / sizeof(int)) {
                    printf("Posicao invalida.\n");
                } else {
                    printf("Digite o valor: ");
                    scanf("%d", &valor);
                    memoria[posicao] = valor;
                }
                break;
            case 2:
                printf("Digite a posicao (0 a %d): ", tamanho_memoria / sizeof(int) - 1);
                scanf("%d", &posicao);
                if (posicao < 0 || posicao >= tamanho_memoria / sizeof(int)) {
                    printf("Posicao invalida.\n");
                } else {
                    printf("Valor na posicao %d: %d\n", posicao, memoria[posicao]);
                }
                break;
            case 3:
                free(memoria);
                printf("Memoria liberada. Saindo...\n");
                return 0;
            default:
                printf("Opcao invalida.\n");
        }
    }
}