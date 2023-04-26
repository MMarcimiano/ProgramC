#include <stdio.h>

int main() {
    int placa; int estado; int cidade; int unidade;

    printf("Digite sua placa: ");
    scanf("%d", &placa);
    estado = placa / 1000;
    cidade = (placa%1000) / 100;
    unidade = (placa%100) / 1;

    printf("Sua placa é: %d\n\n", placa);
    printf("O estado referente da placa é: %d\n\n", estado);
    printf("A cidade da placa é: %d\n\n", cidade);
    printf("A unidade de seu carro é: %d\n\n", unidade);
    
}