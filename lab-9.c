#include <stdio.h>
#include <math.h>

#define N_MAX 20
#define NO_ROOT 1e38

int main() {
    system("chcp 65001");
    int N;
    double P[N_MAX], Q[N_MAX], Z[N_MAX];
    
    printf("Введіть розмір масивів (N < 20): ");
    scanf("%d", &N);
    
    if (N >= 20 || N <= 0) {
        printf("Помилка: N має бути в межах 1..19.\n");
        return 1;
    }
    
    printf("Введіть елементи масиву P:\n");
    for (int i = 0; i < N; i++) {
        printf("P[%d] = ", i);
        scanf("%lf", &P[i]);
    }
    
    printf("Введіть елементи масиву Q:\n");
    for (int i = 0; i < N; i++) {
        printf("Q[%d] = ", i);
        scanf("%lf", &Q[i]);
    }
    
    for (int i = 0; i < N; i++) {
        double D = P[i] * P[i] - 4 * Q[i];
        
        if (D >= 0) {
            double sqrt_D = sqrt(D);
            double root1 = (-P[i] - sqrt_D) / 2;
            double root2 = (-P[i] + sqrt_D) / 2; 
            Z[i] = root1;
        } else {
            Z[i] = NO_ROOT; 
        }
    }
    
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
