#include <iostream>
#include <cstdlib>
#include <ctime>
#include <omp.h>

int main() {
    int B[4];

    #pragma omp parallel num_threads(4)
    {
        int tid = omp_get_thread_num();
        B[tid] = tid * 100;
    }

    for (int i = 0; i < 4; i++) {
        std::cout << B[i] << "\n";
    }
    return 0;
    
    // int sum = 0;

    // #pragma omp parallel num_threads(4)
    // {
    //     sum = sum + 1;
    // }

    // std::cout << sum << "\n";
    // return 0;
    
    // #pragma omp parallel num_threads(3)
    // {
    //     int tid = omp_get_thread_num();
    //     #pragma omp critical
    //     {
    //         std::cout << "Potok:" << tid << "\n";
    //     }
    // }
    // return 0;

    // #pragma omp parallel
    // {
    //     int tid = omp_get_thread_num();
    //     int total = omp_get_num_threads();
    //     #pragma omp critical
    //     {
    //         std::cout << "I thread" << tid << "from" << total << "\n";
    //     }
    // }
    // return 0;
    
    // #pragma omp parallel
    // {
    //     std::cout << "Привет!\n";
    // }
    // return 0;
    // int A[5] = {1, 2, 3, 4, 5};

    // int prod = 1;

    // for (int i = 0; i < 5; i++) {
    //     prod = prod * A[i];
    // }

    // std::cout << prod << "\n";
    // return 0;


    // srand(time(0));

    // for (int i = 0; i < 5; i++) {
    //     int r = rand() % 10;
    //     std::cout << r << "\n";
    // }

    // return 0;
    // std::cout << "привет\n";
    // return 0;
    // int x = 5;
    // int y = 3;
    // int z = x + y;
    // std::cout << z << "\n";
    // return 0;
    // int A[5];
    // A[0] = 10;
    // A[1] = 20;
    // A[2] = 30;
    // A[3] = 40;
    // A[4] = 50;

    // std::cout << A[0] << "\n";
    // std::cout << A[4] << "\n";
    // return 0;

    // for (int i = 0; i < 5; i++) {
    //     std::cout << i << "\n";
    // }
    // return 0;

    // int A[5];

    // for (int i = 0; i < 5; i++) {
    //     A[i] = i * 10;
    // }

    // for (int i = 0; i < 5; i++) {
    //     std::cout << A[i] << "\n";
    // }

    // return 0;
}
