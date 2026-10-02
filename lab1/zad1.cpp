#include <omp.h>
#include <cstdio>

int main(){
    #pragma omp parallel num_threads(4)
    {
        int id = omp_get_thread_num();

        if (id % 2 == 0) {
            printf("\nEven-numbered thread: %d", id);
        }
        else {
            printf("\nOdd-numbered thread: %d", id);
        }
    }

    return 0;
}