#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int M = 3;
const int N = 3;
int A[M][N];
int b[N];
int c[M];

int main() {
    srand(42);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < N; i++) {
        b[i] = rand() % 10;
    }

    printf("Матрица A:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", A[i][j]);
        }
        printf("\n");
    }

    printf("Вектор b:\n");
    for (int i = 0; i < N; i++) {
        printf("%4d\n", b[i]);
    }    

    for (int i = 0; i < M; i++) {
        c[i] = 0;
        for (int j = 0; j < N; j++) {
            c[i] += A[i][j] * b[j];
        }
    }

    printf("Вектор c:\n");
    for (int i = 0; i < M; i++) {
        printf("%4d\n", c[i]);
    }

    return 0;
}

