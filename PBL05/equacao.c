#include <stdio.h>
#include <math.h>



double obter_coeficiente(char* prompt){
  double coef;
  printf(prompt);
  scanf("%lf", &coef);
  fflush(stdin);
  return coef;
}

double calcular_delta(double coef_a, double coef_b, double coef_c){
  float delta = pow(coef_b, 2) - 4 * coef_a * coef_c;
  
  return delta; 
}

int responder_sem_raiz(){
  printf("Não possui raízes reais. ");
}

int responder_uma_raiz(double coef_a, double coef_b){
  double raiz = -coef_b / (2 * coef_a);
  printf("A equação possui uma única raiz: %lf.", raiz);
}

int responder_duas_raizes(double coef_a, double coef_b, double delta){
  double raiz_um = (-coef_b + pow(delta, 0.5)) / (2 * coef_a);
  double raiz_dois = (-coef_b - pow(delta, 0.5)) / (2 * coef_a);
  printf("A equação possui duas raízes: %lf e %lf.", raiz_um, raiz_dois);
}

int main()
{
    printf("Forma geral da equação do segundo grau: a x**2 + b x + c = 0\n");
    double coef_a = obter_coeficiente("Digite o coeficiente a: ");
    if (coef_a == 0)
    {
        printf("O coeficiente a não pode ser zero!\n");
        return 0;
    }
    double coef_b = obter_coeficiente("Digite o coeficiente b: ");
    double coef_c = obter_coeficiente("Digite o coeficiente c: ");
  
    double delta = calcular_delta(coef_a, coef_b, coef_c);
    if (delta < 0)
        responder_sem_raiz();
    else if (delta == 0)
        responder_uma_raiz(coef_a, coef_b);
    else
        responder_duas_raizes(coef_a, coef_b, delta);
    return 0;
}