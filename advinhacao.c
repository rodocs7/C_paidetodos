#include <stdio.h>
#include <locale.h>
#include <string.h>


int main() {
    setlocale(LC_ALL, "Portuguese");    
    printf("*******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhação! *\n");
    printf("*******************************************\n");


    int numeroSecreto = 42; // Número secreto para adivinhação
    int chute;

    printf("Qual e o seu chute? ");
    scanf("%d", &chute);
    printf("Seu chute foi %d\n", chute);


    printf("%d,\n%d\n", numeroSecreto, chute);


}