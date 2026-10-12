#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define N 10000

int compare(void *a, void *b) {
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

double run_parallel(int num_threads, char* schedule_type, int chunk) {
    omp_set_num_threads(num_threads);
    double start = omp_get_wtime();
    
}