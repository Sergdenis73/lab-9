#include <stdio.h>
#include <math.h>

#define N_MAX 20
#define NO_ROOT 1e38  // 10^38

int main() {
    system("chcp 65001");
    int N;
    double P[N_MAX], Q[N_MAX], Z[N_MAX];
    
    // Введення розміру масиву
    printf("Введіть розмір масивів (N < 20): ");
    scanf("%d", &N);
    
    if (N >= 20 || N <= 0) {
        printf("Помилка: N має бути в межах 1..19.\n");
        return 1;
    }
    
    // Введення масиву P
    printf("Введіть елементи масиву P:\n");
    for (int i = 0; i < N; i++) {
        printf("P[%d] = ", i);
        scanf("%lf", &P[i]);
    }
    
    // Введення масиву Q
    printf("Введіть елементи масиву Q:\n");
    for (int i = 0; i < N; i++) {
        printf("Q[%d] = ", i);
        scanf("%lf", &Q[i]);
    }
    
    // Обчислення масиву Z
    for (int i = 0; i < N; i++) {
        double D = P[i] * P[i] - 4 * Q[i]; // Дискримінант для Z^2 + P[i]Z + Q[i] = 0
        
        if (D >= 0) {
            double sqrt_D = sqrt(D);
            double root1 = (-P[i] - sqrt_D) / 2; // Менший корінь
            double root2 = (-P[i] + sqrt_D) / 2; // Більший корінь
            Z[i] = root1; // Беремо менший корінь
        } else {
            Z[i] = NO_ROOT; // 10^38, якщо коренів немає
        }
    }
    
    // Виведення результату
    printf("\nРезультат (масив Z):\n");
    for (int i = 0; i < N; i++) {
        if (Z[i] == NO_ROOT) {
            printf("Z[%d] = 1e38 (немає дійсних коренів)\n", i);
        } else {
            printf("Z[%d] = %.6f\n", i, Z[i]);
        }
    }
    
    return 0;
}