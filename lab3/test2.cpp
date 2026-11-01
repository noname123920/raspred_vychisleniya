#include <cstdio>
#include <omp.h>
#include <unistd.h>

// int main() {
//     int x;
//     #pragma omp parallel private(x)
//     {
//         #pragma omp single copyprivate(x)
//         {
//             x = 42;
//             // usleep(100);
//             // printf("Hello!, tid: %d\n", omp_get_thread_num());
//             printf("single: x = %d, tid = %d\n", x, omp_get_thread_num());
//         }
//         // printf("after single, tid: %d\n", omp_get_thread_num());
//         printf("tid = %d: x = %d\n", omp_get_thread_num(), x);
//     }
//     return 0;
// }


int main() {
    int sum = 0;
    #pragma omp parallel
    {
        #pragma omp sections reduction(+:sum)
        {
            #pragma omp section
            {
                for (int i = 1; i <=50; i++)
                sum += i;
                printf("section A: sum = %d, tid = %d\n", sum, omp_get_thread_num());
            }
            // printf("section A, tid = %d\n", omp_get_thread_num());

            #pragma omp section
            {
                for (int i = 51; i <= 100; i++)
                sum += i;
                printf("section B: sum = %d, tid = %d\n", sum, omp_get_thread_num());
            }
            // printf("section B, tid = %d\n", omp_get_thread_num());

        }
        // printf("Hello, tid: %d\n", omp_get_thread_num());
    }
    printf("Total: %d\n", sum);
}