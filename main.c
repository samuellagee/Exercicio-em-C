#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int coef;
    int expo;
} Termo;

// IMPRIMIR POLINOMIO
void imprimePolinomio(Termo termos[], int n) {
    printf("f(x) = ");
    for (int i = 0; i < n; i++) {
        if (termos[i].coef == 0){
            continue;
        }
        if (i > 0 && termos[i].coef > 0) {
            printf("+");
        }
        if (termos[i].expo == 0){
            printf("%d", termos[i].coef);
        }
        else if (termos[i].expo == 1) {
            if (termos[i].coef == 1){
                printf("x");
            }
            else if (termos[i].coef == -1){
                printf("-x");
            }
            else{
                printf("%dx", termos[i].coef);
            }
        }
        else {
            if (termos[i].coef == 1){
                printf("x^%d", termos[i].expo);
            }
            else if (termos[i].coef == -1){
                printf("-x^%d", termos[i].expo);
            }
            else{
                printf("%dx^%d", termos[i].coef, termos[i].expo);
            }
        }
    }
    printf("\n");
}

// CALCULAR DERIVADA
void derivaPolinomio(Termo termos[], Termo derivada[], int n) {
    for (int i = 0; i < n; i++) {
        derivada[i].coef = termos[i].coef * termos[i].expo;
        derivada[i].expo = termos[i].expo - 1;
    }
}

// SUBSTITUIR A
int substituiPolinomio(Termo termos[], int n, int x) {
    int resultado = 0;
    for (int i = 0; i < n; i++) {
        resultado += termos[i].coef * pow(x, termos[i].expo);
    }
    return resultado;
}

int main() {
    int n;
    printf("Quantos termos tem o polinômio? ");
    scanf("%d", &n);

    Termo termos[n];
    Termo derivada[n];

    printf("Insira os termos no formato coeficiente expoente (por exemplo, para 5x^3 insira '5 3') OBS: para declarar um termo independente basta digitar 0 como expoente. :\n");
    for (int i = 0; i < n; i++) {
        printf("Termo %d: ", i + 1);
        scanf("%d %d", &termos[i].coef, &termos[i].expo);
    }

    imprimePolinomio(termos, n);
    derivaPolinomio(termos, derivada, n);
    // IMPRIMINDO A DERIVADA
    printf("f'(x) = ");
    for (int i = 0; i < n; i++) {
        if (derivada[i].coef == 0){
            continue;
        }
        if (i > 0 && derivada[i].coef > 0) {
            printf("+");
        }
        if (derivada[i].expo == 0){
            printf("%d", derivada[i].coef);
        }
        else if (derivada[i].expo == 1) {
            if (derivada[i].coef == 1){
                printf("x");
            }
            else if (derivada[i].coef == -1){
                printf("-x");
            }
            else{
                printf("%dx", derivada[i].coef);
            }
        }
        else {
            if (derivada[i].coef == 1){
                printf("x^%d", derivada[i].expo);
            }
            else if (derivada[i].coef == -1){
                printf("-x^%d", derivada[i].expo);
            }
            else{
                printf("%dx^%d", derivada[i].coef, derivada[i].expo);
            }
        }
    }
    printf("\n");

    char opcao;
    printf("Deseja calcular valor funcional? (s/n) ");
    scanf(" %c", &opcao);

    if (opcao == 's' || opcao == 'S') {
        int a;
        printf("Qual o valor de a? ");
        scanf("%d", &a);

        int fa = substituiPolinomio(termos, n, a);
        int fpa = substituiPolinomio(derivada, n, a);

        printf("f(%d) = %d\n", a, fa);
        printf("f'(%d) = %d\n", a, fpa);
        printf("P(%d, %d)\n", a, fa);

        printf("Deseja calcular equacao da reta tangente ao gráfico de f no ponto P(%d, %d)? (s/n) ", a, fa);
        scanf(" %c", &opcao);

        if (opcao == 's' || opcao == 'S') {
            printf("A equacao da reta tangente ao gráfico de f no ponto P(%d, %d) é\n", a, fa);
            if (fpa != 0) {
                int b = fa - fpa * a;
                if (b >= 0) {
                    printf("y = %dx + %d\n", fpa, b);
                } else {
                    printf("y = %dx - %d\n", fpa, -b);
                }
            } else {
                printf("y = %d\n", fa);
            }
        }
    }

    return 0;
}
