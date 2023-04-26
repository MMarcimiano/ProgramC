#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
//definições e criação do header igual exemplo video
#ifndef TABELA_H_INCLUDED
#define TABELA_H_INCLUDED
#define LEN_FOR_STRING 20
#define BUFFER_SIZE 4096
#define ARRAY 20

typedef enum {
  janeiro,
  fevereiro,
  marco,
  abril,
  maio,
  junho,
  julho,
  agosto,
  setembro,
  outubro,
  novembro,
  dezembro
} meses;

typedef struct {
  char genero;
  char nome[LEN_FOR_STRING];
  int idade;
  double altura;
  meses mes;
  int peso;
  
} type_jogadores;
//funções read e write do p1
bool leituraTexto(char *filename, type_jogadores *aqvs);
bool escreveBinario(char *filename, type_jogadores *data, int total);

//funções read e write do p2
type_jogadores *leituraBinario(char *filename, int *total);
bool escreveTxt(char *filename, type_jogadores *data, int total);
//aba do menu de escolhas
void menuEscolhas(type_jogadores *arr);
double media(double a[], int n);

//funções de verificação, menu e escolha
void menuMedia(type_jogadores *aqvs);
void limpaBuffer();
bool verificaArq(int arqv);

#endif 