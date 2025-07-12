#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nota {
   char titulo[100];
   char conteudo[1000];
};

int main() {
   struct Nota notas[100];
   int opcao, numNotas = 0;

   do {
      printf("Selecione uma opção:\n");
      printf("1 - Adicionar nota\n");
      printf("2 - Visualizar notas\n");
      printf("3 - Editar nota\n");
      printf("4 - Excluir nota\n");
      printf("5 - Sair\n");

      scanf("%d", &opcao);

      switch (opcao) {
         case 1: {
            printf("Digite o título da nota: ");
            scanf("%s", notas[numNotas].titulo);

            printf("Digite o conteúdo da nota: ");
            scanf(" %[^\n]s", notas[numNotas].conteudo);

            numNotas++;

            printf("Nota adicionada com sucesso.\n");
            break;
         }
         case 2: {
            printf("Notas cadastradas:\n");

            for (int i = 0; i < numNotas; i++) {
               printf("Título: %s\n", notas[i].titulo);
               printf("Conteúdo: %s\n", notas[i].conteudo);
               printf("----------------------\n");
            }
            break;
         }
         case 3: {
            char titulo[100];

            printf("Digite o título da nota que deseja editar: ");
            scanf("%s", titulo);

            for (int i = 0; i < numNotas; i++) {
               if (strcmp(notas[i].titulo, titulo) == 0) {
                  printf("Digite o novo título da nota: ");
                  scanf("%s", notas[i].titulo);

                  printf("Digite o novo conteúdo da nota: ");
                  scanf(" %[^\n]s", notas[i].conteudo);

                  printf("Nota editada com sucesso.\n");
                  break;
               }
            }
            break;
         }
         case 4: {
            char titulo[100];

            printf("Digite o título da nota que deseja excluir: ");
            scanf("%s", titulo);

            for (int i = 0; i < numNotas; i++) {
               if (strcmp(notas[i].titulo, titulo) == 0) {
                  for (int j = i; j < numNotas - 1; j++) {
                     notas[j] = notas[j + 1];
                  }

                  numNotas--;

                  printf("Nota excluída com sucesso.\n");
                  break;
               }
            }
            break;
         }
         case 5:
            printf("Encerrando o programa...\n");
            break;
         default:
            printf("Opção inválida.\n");
            break;
      }
   } while (opcao != 5);

   return 0;
}