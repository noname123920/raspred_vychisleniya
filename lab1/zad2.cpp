#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>

int main() {
    int T = 4;
    int N = 20;

    int A[N];
    int B[T];

    srand(time(0));
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 10;
    }

    #pragma omp parallel num_threads(T)
    {
        int tid = omp_get_thread_num(); // 0,1,2,3 - номера потоков
        int num_threads = omp_get_num_threads(); // это всегда 4

        int chunk = N / num_threads; // это всегда 5
        int start = tid * chunk; // 0, 5, 10, 15
        int end = start + chunk;
        
        int local_sum = 0;
        for (int i = start; i < end; i++) {
            local_sum += A[i];
        }

        B[tid] = local_sum;
        printf("\nПоток №%d из %d, сумма = %d\n", tid, num_threads, local_sum);
    }

    printf("\nМассив A: ");
    for (int i = 0; i < N; i++) {
        printf("%d", A[i]);
        if (i < N - 1)
            printf(", ");
    }
    printf("\n");

    printf("\nМассив B: ");
    for (int i = 0; i < T; i++) {
        printf("%d", B[i]);
        if (i < T - 1)
            printf(", ");
    }
    printf("\n");

    int sum = 0;
    for (int i = 0; i < T; i++) {
        sum += B[i];
    }
    printf("\nИтог = %d\n", sum);
}