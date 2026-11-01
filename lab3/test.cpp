#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            printf("Секция 1 выполняется потоком %d\n", omp_get_thread_num());
        }

        #pragma omp section
        {
            printf("Секция 1 выполняется потоком %d\n", omp_get_thread_num());
        }
    }
    return 0;
}