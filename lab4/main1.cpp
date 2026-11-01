#include <omp.h>
#include <stdio.h>

int main() {
    int counter = 0;

    #pragma omp parallel num_threads(4)
    {
        int thread_id = omp_get_thread_num();
        printf("Поток №%d начал работу\n", thread_id);

        #pragma omp atomic
        counter++;
        printf("Поток №%d увеличил счетчик. Текущее значение: %d\n", thread_id, counter);

        // Обновляем память
        #pragma omp flush(counter)

        printf("Поток №%d: Я жду, пока не придут все 4 потока...\n", thread_id);

        while(counter < 4) {
            #pragma omp flush(counter)
        }

        printf("Поток №%d прошел барьер\n", thread_id);
    }

    return 0;
}