#include "tabela.h"


int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "Portuguese");
  
  char *arquivo = "jogadores.txt";
  
  type_jogadores *array_jogadores;
  array_jogadores = malloc(sizeof(type_jogadores) * ARRAY);
  
    
  // Lê o conteúdo do arquivo .txt e armazena num array de struct
  if (leituraTexto("jogadores.txt", array_jogadores)) {
    printf("[%s]\tleitura realizada.\n\n", arquivo);
  } else {
    printf("[%s]\terro ao ler o arquivo.\n\n", arquivo);
    return 1;
  }
  
  // Pega o conteúdo do array de strutc e escreve (em binário) num arquivo .bin
  if (escreveBinario("jogadores.bin", array_jogadores, ARRAY)) {
    printf("[%s]\tescrita realizada.\n\n", arquivo);
  } else {
    printf("[%s]\terro ao escrever o arquivo.\n\n", arquivo);
    return 1;
  }
  free(array_jogadores);

  
  
  // P 2
  
  int total = 0;
  type_jogadores *arquivo_2;
  
  arquivo_2 = leituraBinario("jogadores.bin", &total);
  
  if (arquivo_2 == NULL) {
    printf("[%s]\tnão foi possivel ler o arquivo.\n\n", arquivo);
    return 1;
  }
  printf("[%s]\tleitura realizada.\n\n", arquivo);
  
  if (escreveTxt("jogadoresResult.txt", arquivo_2, ARRAY)) {
    printf("[%s]\tescrita realizada.\n\n", arquivo);
  } else {
    printf("[%s]\t erro ao escrever o arquivo.\n\n", arquivo);
    return 1;
  }
  
  int escolha;
  bool termina = false;
    
  do{
    puts("\t\t\t Escolhas:\n ");
    puts("*********************************");
    puts("|\t1 - Calculos de média");
    puts("|\t2 - Dados");
    puts("|\t0 - Encerrar");
    puts("*********************************");
    
    puts("\nOpcao: ");
    scanf("%d", &escolha);
    limparBuffer();
        
    switch(escolha) {
      case 0:
        system("cls || clear");
        termina = true;
        break;
      case 1:
        system("cls || clear");
        menuMedia(arquivo_2);
        break;
      case 2:
        system("cls || clear");
        menuEscolhas(arquivo_2);
        break;
      default:
      system("cls || clear");
      printf("\n Escolha invalida!\n\n");
    }
  }
  while (!termina);
  puts("\nAplicação encerrada\n");
  free(arquivo_2); 
  return 0;
}