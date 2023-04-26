#include "tabela.h"
//função paraa limpar o buffer
void limparBuffer(){ 
    int buffer;
    while( (buffer = fgetc(stdin)) != EOF && buffer != '\n' ){} 
}
//função verifica arquivos
bool verificaArq(int arqv) {
  if (arqv < 1) {
    puts("nenhum arquivo foi encontrado!");
    return false;
  } else if (arqv == 2) {
    puts("parâmetros insuficientes.");
    return false;
  } else if (arqv > 3) {
    puts("Por favor informe no máximo 2 parâmetros");
    return false;
  }
  return true;
}
//fução da leitura de txt
bool leituraTexto(char *filename, type_jogadores *arr) {
  FILE *file;
  file = fopen(filename, "r");
  if (file == NULL) {
    puts("Arquivo não pode ser aberto!");
    return false;
  }
  char *opcao = "%c, %20[^,], %d, %lf, %d, %d\n";
  int leitura = 0;
  int cont = 0;
  while (!feof(file)) {
    leitura = fscanf(file, opcao, &arr[cont].genero, &arr[cont].nome,
                  &arr[cont].idade, &arr[cont].altura, &arr[cont].mes,
                  &arr[cont].peso);
    if (leitura == 6) {
      cont++;
    }
  }
  if (fclose(file) == EOF) return false;
  return true;
}

//escreve binario
bool escreveBinario(char *filename, type_jogadores *data, int total) {
  FILE *file;
  file = fopen(filename, "wb");

  if (file == NULL) {
    puts("Erro! Não foi possível abrir o arquivo.");
    return false;
  }
  if (fwrite(&total, sizeof(int), 1, file) != 1)
    return false;
  if (fwrite(data, sizeof(type_jogadores), total, file) != total)
    return false;
  if (fclose(file) == EOF)
    return false;

  return true;
}

type_jogadores *leituraBinario(char *filename, int *total) {
  FILE *file;
  file = fopen(filename, "rb");
  if (file == NULL) {
    return NULL;
  }
  if (fread(total, sizeof(int), 1, file) != 1) {
    return NULL;
  }
  type_jogadores *data = malloc(sizeof(type_jogadores) * *total);

  if (fread(data, sizeof(type_jogadores), *total, file) != *total) {
    free(data);
    return NULL;
  }
  if (fclose(file) == EOF) {
    free(data);
    return NULL;
  }
  return data;
}

bool escreveTxt(char *filename, type_jogadores *data, int total) {
  FILE *file;
  file = fopen("txtJogadores.txt", "w");
  if (file == NULL) {
    puts("Erro ao criar o arquivo!");
    return false;
  }
  for (int i = 0; i < total; i++) {
    fprintf(file, "%c, %s, %d, %lf, %d, %d\n", data[i].genero, data[i].nome, data[i].idade, data[i].altura, data[i].mes, data[i].peso);
    if (ferror(file)) {
      puts("Erro ao escrever arquivo.\n");
      return false;
    }
  }
  fclose(file);
  return true;
}

double media(double a[], int n)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
      sum += a[i];
  return (double)sum / n;
}

void menuMedia(type_jogadores *aqvs) {
  double mediaOf[ARRAY];
  int opcao, n;
  double avg;
  
  puts("\tIMPRIMIR CARACTERÍSTICA");
  puts("\t1. Idade");
  puts("\t2. Altura");
  puts("\t0. Voltar");

  puts("\nOpção: ");
  scanf("%d", &opcao);
  limparBuffer();
  
  switch (opcao) {
    case 0:
      system("cls || clear");
      break;
    case 1:
      system("cls || clear");
      for (int i = 0; i < ARRAY; i++) {
        mediaOf[i] = aqvs[i].idade;
      }
      avg = media(mediaOf, ARRAY);
      printf(">>> Média da idade dos jogadores %.1lf anos", avg);
      puts("\n\n");
      break;
    case 2:
      system("cls || clear");
      for (int i = 0; i < ARRAY; i++) {
        mediaOf[i] = aqvs[i].altura*100;
      }
      avg = media(mediaOf, ARRAY);
      printf(">>> Média da altura dos jogadores: %.1lf metros", avg);
      puts("\n\n");
      break;
    default:
      system("cls || clear");
      printf("\n[!!!]   Opcao invalida! Tente novamente.\n\n");
      break;
  }
}

void menuEscolhas(type_jogadores *aqvs) {
  int escolhe;
  puts("\tEscolhas");
  puts("\t1 - Gênero");
  puts("\t2 - Idade");
  puts("\t3 - Altura");
  puts("\t4 - Mês nascimento");
  puts("\t5 - Peso");
  puts("\t6 - Imprimir tudo");
  puts("\t0 - Voltar");

  puts("\nOpcao: ");
  scanf("%d", &escolhe);
  limparBuffer();
  
  switch (escolhe) {
    case 0:
      system("cls || clear");
      break;
    case 1:
      system("cls || clear");
      puts("Gênero Jogadores:");
      for (int i = 0; i < ARRAY; i++) {
        printf("\t%s - %c\n", aqvs[i].nome, aqvs[i].genero);
      }
      puts("\n\n");
      break;
    case 2:
      system("cls || clear");
      puts("Idade dos Jogadores:");
      for (int i = 0; i < ARRAY; i++) {
        printf("\t%s - %d anos\n", aqvs[i].nome, aqvs[i].idade);
      }
      puts("\n\n");
      break;
    case 3:
      system("cls || clear");
      puts("Altura dos Jogadores:");
      for (int i = 0; i < ARRAY; i++) {
        printf("\t%s - %.2lfm\n", aqvs[i].nome, aqvs[i].altura);
      }
      puts("\n\n");
      break;
    case 4:
      system("cls || clear");
      puts("Mês nascimento Jogadores:");
      for (int i = 0; i < ARRAY; i++) {
        printf("\t%s - %d\n", aqvs[i].nome, aqvs[i].mes);
      }
      puts("\n\n");
      break;
    case 5:
      system("cls || clear");
      puts("Peso Jogadores:");
      for (int i = 0; i < ARRAY; i++) {
        printf("\t%s - %d\n", aqvs[i].nome, aqvs[i].peso);
      }
      puts("\n\n");
      break;
    case 6:
      system("cls || clear");
      for (int i = 0; i < ARRAY; i++) {
        printf("----- Jogadores  -----\n");
        printf("\tGenero: %c\n", aqvs[i].genero);
        printf("\tNome: %s\n", aqvs[i].nome);
        printf("\tIdade: %d\n", aqvs[i].idade);
        printf("\tAltura: %.2lf\n", aqvs[i].altura);
        printf("\tMes nasc: %d\n", aqvs[i].mes);
        printf("\tPeso: %d\n\n", aqvs[i].peso);
      }
      puts("\n\n");
      break;
    default:
      system("cls || clear");
      printf("\n[!!!]   Opcao invalida! Tente novamente.\n\n");
      break;
  }
}
