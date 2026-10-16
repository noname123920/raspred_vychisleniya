#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <string.h>

#define N 10000

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void do_work(int k) {
    int *arr = (int*) malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        arr[i] = rand() % 10;
    }
    qsort(arr, k, sizeof(int), compare);
    free(arr);
}

double run_serial() {
    double start = omp_get_wtime();
    for (int k = 1; k <= N; k++) {
        do_work(k); 
    } 
    return omp_get_wtime() - start;
}

double run_parallel(int num_threads, const char* schedule_type, int chunk) {
    omp_set_num_threads(num_threads);
    double start = omp_get_wtime();
    
    if (strcmp(schedule_type, "static") == 0) {
        #pragma omp parallel for schedule(static, chunk)
        for (int k = 1; k <= N; k++) do_work(k);
    } else if (strcmp(schedule_type, "dynamic") == 0) {
        #pragma omp parallel for schedule(dynamic, chunk)
        for (int k = 1; k <= N; k++) do_work(k);
    } else if (strcmp(schedule_type, "guided") == 0) {
        #pragma omp parallel for schedule(guided, chunk)
        for (int k = 1; k <= N; k++) do_work(k);
    }

    return omp_get_wtime() - start;
}

int main() {
    srand(time(NULL));

    double T1 = 0.0;
    for (int i = 0; i < 5; i++) {
        T1 += run_serial();
    }
    T1 /= 5.0;
    printf("T1 (последовательно) = %.6f сек\n\n", T1);


    const char* schedules[] = {"static", "dynamic", "guided"};
    int chunks[] = {100, 1, 1};

    printf("%-8s %-10s %-12s %-12s\n", "Потоки", "Schedule", "Tp (сред.)", "Ускорение S");
    printf("----------------------------------------------\n");

    for (int t = 2; t <= 4; t += 2) {
        for (int s = 0; s < 3; s++) {
            double total = 0.0;
            for (int run = 0; run < 5; run++) {
                total += run_parallel(t, schedules[s], chunks[s]);
            }
            double Tp = total / 5.0;
            double S = T1/ Tp;
            printf("%-8d %-10s %-12.6f %-12.4f\n", t, schedules[s], Tp, S);
        }
    }

    return 0;
}