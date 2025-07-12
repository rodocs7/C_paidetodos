#include <stdio.h>

char tabuleiro[3][3] = {
   {'-', '-', '-'},
   {'-', '-', '-'},
   {'-', '-', '-'}
};

char jogadorAtual = 'X';
int jogoAcabou = 0;

void inicializarTabuleiro() {
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         tabuleiro[i][j] = '-';
      }
   }
}

void exibirTabuleiro() {
   printf("-----\n");
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         printf("%c", tabuleiro[i][j]);
      }
      printf("\n");
   }
   printf("-----\n");
}

void fazerJogada() {
   int linha, coluna;

   printf("Jogador %c, faça sua jogada.\n", jogadorAtual);

   printf("Digite a linha: ");
   scanf("%d", &linha);

   printf("Digite a coluna: ");
   scanf("%d", &coluna);

   if (tabuleiro[linha][coluna] == '-') {
      tabuleiro[linha][coluna] = jogadorAtual;
   } else {
      printf("Essa posição já está ocupada. Tente novamente.\n");
      fazerJogada();
   }
}

int verificarVencedor() {
   // Verificar linhas
   for (int i = 0; i < 3; i++) {
      if (tabuleiro[i][0] == jogadorAtual && tabuleiro[i][1] == jogadorAtual && tabuleiro[i][2] == jogadorAtual) {
         return 1;
      }
   }

   // Verificar colunas
   for (int i = 0; i < 3; i++) {
      if (tabuleiro[0][i] == jogadorAtual && tabuleiro[1][i] == jogadorAtual && tabuleiro[2][i] == jogadorAtual) {
         return 1;
      }
   }

   // Verificar diagonais
   if ((tabuleiro[0][0] == jogadorAtual && tabuleiro[1][1] == jogadorAtual && tabuleiro[2][2] == jogadorAtual) ||
       (tabuleiro[0][2] == jogadorAtual && tabuleiro[1][1] == jogadorAtual && tabuleiro[2][0] == jogadorAtual)) {
      return 1;
   }

   return 0;
}

int verificarEmpate() {
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         if (tabuleiro[i][j] == '-') {
            return 0;
         }
      }
   }
   return 1;
}

void alternarJogador() {
   jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
}

int main() {
   inicializarTabuleiro();

   while (!jogoAcabou) {
      exibirTabuleiro();
      fazerJogada();

      if (verificarVencedor()) {
         exibirTabuleiro();
         printf("Jogador %c venceu!\n", jogadorAtual);
         jogoAcabou = 1;
      } else if (verificarEmpate()) {
         exibirTabuleiro();
         printf("O jogo empatou.\n");
         jogoAcabou = 1;
      }

      alternarJogador();
   }

   return 0;
}