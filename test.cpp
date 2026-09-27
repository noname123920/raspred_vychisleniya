#include <stdio.h>
#include <omp.h>

// int main() {
//     int N = 13;

//     #pragma omp parallel for schedule(static) num_threads(4)
//     for (int i = 0; i < N; i++) {
//         printf("i = %2d, поток = %d\n", i, omp_get_thread_num());
//     }
//     return 0;
// }

// int main() {
//     int N = 2000;

//     #pragma omp parallel if (N > 1000) num_threads(4)
//     {
//         printf("потоков = %d, tid=%d\n", omp_get_num_threads(), omp_get_thread_num());
//     }
//     return 0;
// }

// int main() {
//     #pragma omp parallel num_threads(2)
//     {
//         printf("2 потока: потоков=%d, tid=%d\n", omp_get_num_threads(), omp_get_thread_num());
//     }

//     #pragma omp parallel num_threads(8)
//     {
//         printf("8 потоков: потоков=%d, tid=%d\n", omp_get_num_threads(), omp_get_thread_num());
//     }
//     return 0;
// }

// int main() {
//     #pragma omp parallel
//     {
//         if (omp_get_thread_num() == 1)
//             printf("По умолчанию: потоков=%d\n", omp_get_num_threads());
//     }
//     return 0;
// }

// int main() {
//     int x = 5;

//     #pragma omp parallel default(none) firstprivate(x) num_threads(2)
//     {
//         printf("x=%d\n", x);
//     }
//     return 0;
// }

// int main(){
//     int sum = 0;

//     #pragma omp parallel for reduction(+:sum)
//     for (int i = 1; i <= 100; i++) {
//         printf("i=%2d, tid=%d\n", i, omp_get_thread_num());
        
//         sum += i;
//     }

//     printf("sum=%d\n", sum);
//     return 0;
// }


// int main() {
//     int N = 12;

//     printf("=== schedule(static, 2) ===\n");
//     #pragma omp parallel for schedule(static, 2) num_threads(4)
//     for (int i = 0; i < N; i++) {
//         printf("i=%2d, tid=%d\n", i, omp_get_thread_num());
//     }

//     printf("=== schedule(dynamic, 2) ===\n");
//     #pragma omp parallel for schedule(dynamic, 2) num_threads(4)
//     for (int i = 0; i < N; i++) {
//         printf("i=%2d, tid=%d\n", i, omp_get_thread_num());
//     }

//     return 0;
// }

// int main() {
//     int N = 12;
//     int last_i = -1;

//     #pragma omp parallel for lastprivate(last_i) num_threads(4)
//     for (int i = 0; i < N; i++) {
//         last_i = i;
//         printf("i=%2d, tid=%d\n", i, omp_get_thread_num());
//     }

//     printf("last_i=%d\n", last_i);
//     return 0;
// }


// int main() {
//     int N = 12;
//     int priv_i = -1;

//     #pragma omp parallel for private(priv_i) num_threads(4)
//     for (int i = 0; i < N; i++) {
//         priv_i = i;
//         printf("i=%2d, tid=%d\n", i, omp_get_thread_num());
//     }

//     printf("priv_i=%d\n", priv_i);
//     return 0;
// }