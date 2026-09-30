#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

const int M = 12;
const int N = 12;

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

    #pragma omp parallel num_threads(4)
    {
        int tid = omp_get_thread_num();
        int T = omp_get_num_threads();
        int chunk = M / T;

        int start = tid * chunk;
        int end = start + chunk;

        for (int i = start; i < end; i++) {
            printf("i = %d, поток = %d\n", i, tid);
            c[i] = 0;
            for (int j = 0; j < N; j++) {
                c[i] += A[i][j] * b[j];
            }
        }
    }
    printf("Вектор c:\n");
    for (int i = 0; i < M; i++) {
        printf("%4d\n", c[i]);
    }

    return 0;
}