#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define VERMELHO "\033[31m"
#define AMARELO "\033[33m"
#define VERDE "\033[32m"
#define RESET "\033[0m"

#define gotoxy(x, y) printf("\033[%d;%df", y, x)

void desenharBomba() {
  gotoxy(20, 10);
  printf("  .-._   _.-.  ");
  gotoxy(20, 11);
  printf(" /   o\\o /o   \\ ");
  gotoxy(20, 12);
  printf("| _.--.,.--._ |");
  gotoxy(20, 13);
  printf("| '-;-`-;-'/ |");
  gotoxy(20, 14);
  printf("|  '-'   '-'  |");
  gotoxy(20, 15);
  printf("| _.-.,.--._ |");
  gotoxy(20, 16);
  printf("| '-;-`-;-'/ |");
  gotoxy(20, 17);
  printf(" \\   ^   /  ");
  gotoxy(20, 18);
  printf("  '-._____.-'  ");
}

void explodir() {
  int i, j;
  system("clear"); // Limpa a tela antes da explosão

  // Desenha uma explosão em forma de chama
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 40; j++) {
      gotoxy(20 - j / 2, 10 - i);
      printf("%s%c%s", VERMELHO, rand() % 2 == 0 ? '*' : '+', RESET);
      gotoxy(20 + j / 2, 10 - i);
      printf("%s%c%s", VERMELHO, rand() % 2 == 0 ? '*' : '+', RESET);
    }
    usleep(100000); // Aguarda 100 milissegundos entre os passos da explosão
  }

  // Adiciona um som de alerta ao final
  printf("\a");
  usleep(500000); // Aguarda 500 milissegundos
  printf("\a");
  usleep(500000);
  printf("\a");
}

int main() {
  int tempo, segundos, minutos, horas;
  char opcao;

  // Limpando a tela
  system("clear");

  // Definindo o título da janela do terminal (pode não funcionar em todos os terminais)
  printf("\033]0;Cronômetro Retroativo com Explosão\007");

  do {
    // Lendo o tempo em segundos
    printf("Digite o tempo em segundos: ");
    scanf("%d", &tempo);

    // Convertendo segundos para horas, minutos e segundos
    horas = tempo / 3600;
    minutos = (tempo % 3600) / 60;
    segundos = tempo % 60;

    // Iniciando a contagem regressiva
    while (tempo > 0) {
      // Limpando a tela novamente
      system("clear");

      // Desenhando a bomba
      desenharBomba();

      // Mostrando o tempo restante
      gotoxy(10, 5);
      printf("%sTempo restante: %02d:%02d:%02d%s", AMARELO, horas, minutos, segundos, RESET);

      // Decrementando o tempo
      tempo--;
      segundos--;

      // Verificando se os segundos chegaram a zero
      if (segundos == -1) {
        minutos--;
        segundos = 59;
      }

      // Verificando se os minutos chegaram a zero
      if (minutos == -1) {
        horas--;
        minutos = 59;
      }

      // Mudando a cor de acordo com o tempo restante
      if (tempo <= 10) {
        printf("%s", VERMELHO); // Vermelho
      } else if (tempo <= 30) {
        printf("%s", AMARELO); // Amarelo
      } else {
        printf("%s", VERDE); // Verde
      }

      usleep(1000000); // Aguarda 1 segundo
    }

    // Explosão ao final do tempo
    explodir();

    // Pergunta se deseja iniciar outro cronômetro
    printf("\nDeseja iniciar outro cronômetro? (S/N): ");
    scanf(" %c", &opcao);

  } while (opcao == 'S' || opcao == 's');

  return 0;
}
