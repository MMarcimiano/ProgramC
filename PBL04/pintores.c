#include <stdio.h>
#include <string.h>
#define NUM_MESES 12

const int NUM_PINTORES = 20;

enum Mes {JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ};

char mes_str[NUM_MESES][10] = { "janeiro", "fevereiro", "março", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"
};

struct Pessoa
{
    char nome[50];
    enum Mes mes; // mês de aniversário
};

int main()
{
    struct Pessoa pintor[NUM_PINTORES];
    pintor[0].mes = JAN; strcpy(pintor[0].nome, "Leonardo da Vinci");
    pintor[1].mes = ABR; strcpy(pintor[1].nome, "Sandro Botticelli");
    pintor[2].mes = AGO; strcpy(pintor[2].nome, "Georges Seurat");
    pintor[3].mes = ABR; strcpy(pintor[3].nome, "Vincent van Gogh");
    pintor[4].mes = SET; strcpy(pintor[4].nome, "Paul Gauguin");
    pintor[5].mes = JUN; strcpy(pintor[5].nome, "Edouard Manet"); 
    pintor[6].mes = OUT; strcpy(pintor[6].nome, "Paul Cezanne"); 
    pintor[7].mes = JUN; strcpy(pintor[7].nome, "Auguste Renoir"); 
    pintor[8].mes = JUN; strcpy(pintor[8].nome, "Claude Monet");
    pintor[9].mes = AGO; strcpy(pintor[9].nome, "Pablo Picasso");
    pintor[10].mes = DEZ; strcpy(pintor[10].nome, "Edgar Degas");
    pintor[11].mes = ABR; strcpy(pintor[11].nome, "Edvard Munch");
    pintor[12].mes = JAN; strcpy(pintor[12].nome, "Michelangelo Merisi Caravaggio)");
    pintor[13].mes = JAN; strcpy(pintor[13].nome, "Michelangelo Buonarroti");
    pintor[14].mes = SET; strcpy(pintor[14].nome, "Tarsila do Amaral"); 
    pintor[15].mes = AGO; strcpy(pintor[15].nome, "Gustav Klimt"); 
    pintor[16].mes = NOV; strcpy(pintor[16].nome, "Rembrandt van Rijn"); 
    pintor[17].mes = MAI; strcpy(pintor[17].nome, "Amedeo Modigliani"); 
    pintor[18].mes = SET; strcpy(pintor[18].nome, "Caillebotte"); 
    pintor[19].mes = SET; strcpy(pintor[19].nome, "Joseph Turner"); 


    printf("Meses para pesquisa: \n (1) Janeiro \n (2) Fevereiro \n (3) Março \n (4) Abril \n (5) Maio \n (6) Junho \n (7) Julho \n (8) Agosto \n (9) Setembro \n (10) Outubro \n (11) Novembro \n (12) dezembro \n");

    int meses;
    int contador = 0;
    printf("Escolha um mês pelo seu número: ");
    scanf("%d", &meses);
    meses--;

    if(meses < 0 || meses > 11)
    {
      printf("Escolha não possível. Digite um mês de 1 á 12. ");
      return 1;
    }
    printf("Listagem de Pintores do mês: %s", mes_str[meses]);
    for(int i = 0; i < NUM_PINTORES; i++)
      if(pintor[i].mes == meses)
      {
        printf("\n (%d) %s", contador + 1, pintor[i].nome);
        contador++;
      }

    if(contador == 1)
      printf("\n==> apenas 1 pintor encontrado");
    else if(contador == 0)
      printf("\n==> Mês sem nenhum pintor aniversáriante ");
    else
      printf("\n==> %d pintor encontrados ", contador);

  
    return 0;
}