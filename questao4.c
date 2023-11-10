#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* alocaString(int tamanho) {
    char *str = (char *)malloc((tamanho + 1) * sizeof(char));
    if (str == NULL) {
        printf("Falha na alocacao de memoria.\n");
        exit(1);
    }
    return str;
}
 
int main() {
    int tamanho;
 
    printf("Digite o tamanho da string: ");
    scanf("%d", &tamanho);
 
    char *minhaString = alocaString(tamanho);
 
    printf("Digite o conteudo da string: ");
    scanf(" %[^\n]s", minhaString);
 
    printf("String sem as vogais: ");
    for (int i = 0; i < tamanho; i++) {
        char caractere = minhaString[i];
        if (!strchr("AEIOUaeiou", caractere)) {
            printf("%c", caractere);
        }
    }
    printf("\n");
 
    free(minhaString);
 
    return 0;
}