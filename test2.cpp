#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <omp.h>

int main() {
    // статические случаи
    double total_time_2_stat = 0.0;
    for (int run = 1; run <= 5; run++) {
        double start_time = omp_get_wtime();

        #pragma omp parallel for num_threads(2) schedule(static)
        for (int i = 1; i <= 10000; i++) {
            std::vector<int> arr(i);

            for (int j = 0; j < i; j++) {
                arr[j] = rand() % 100;
            }
            std::sort(arr.begin(), arr.end());
        }

        double end_time = omp_get_wtime();
        total_time_2_stat += (end_time - start_time);
    }
    double avg_time_2_stat = total_time_2_stat / 5;

    double total_time_4_stat = 0.0;
    for (int run = 1; run <= 5; run++) {
        double start_time = omp_get_wtime();

        #pragma omp parallel for num_threads(4) schedule(static)
        for (int i = 1; i <= 10000; i++) {
            std::vector<int> arr(i);

            for (int j = 0; j < i; j++) {
                arr[j] = rand() % 100;
            }
            std::sort(arr.begin(), arr.end());
        }

        double end_time = omp_get_wtime();
        total_time_4_stat += (end_time - start_time);
    }
    double avg_time_4_stat = total_time_4_stat / 5;

    // динамические случаи
    double total_time_2_dyn = 0.0;
    for (int run = 1; run <= 5; run++) {
        double start_time = omp_get_wtime();

        #pragma omp parallel for num_threads(2) schedule(dynamic, 10)
        for (int i = 1; i <= 10000; i++) {
            std::vector<int> arr(i);

            for (int j = 0; j < i; j++) {
                arr[j] = rand() % 100;
            }
            std::sort(arr.begin(), arr.end());
        }

        double end_time = omp_get_wtime();
        total_time_2_dyn += (end_time - start_time);
    }
    double avg_time_2_dyn = total_time_2_dyn / 5;

    double total_time_4_dyn = 0.0;
    for (int run = 1; run <= 5; run++) {
        double start_time = omp_get_wtime();

        #pragma omp parallel for num_threads(4) schedule(dynamic, 10)
        for (int i = 1; i <= 10000; i++) {
            std::vector<int> arr(i);

            for (int j = 0; j < i; j++) {
                arr[j] = rand() % 100;
            }
            std::sort(arr.begin(), arr.end());
        }

        double end_time = omp_get_wtime();
        total_time_4_dyn += (end_time - start_time);
    }
    double avg_time_4_dyn = total_time_4_dyn / 5;

    // guided случаи
    double total_time_2_guid = 0.0;
    for (int run = 1; run <= 5; run++) {
        double start_time = omp_get_wtime();

        #pragma omp parallel for num_threads(2) schedule(guided)
        for (int i = 1; i <= 10000; i++) {
            std::vector<int> arr(i);

            for (int j = 0; j < i; j++) {
                arr[j] = rand() % 100;
            }
            std::sort(arr.begin(), arr.end());
        }

        double end_time = omp_get_wtime();
        total_time_2_guid += (end_time - start_time);
    }
    double avg_time_2_guid = total_time_2_guid / 5;

    double total_time_4_guid = 0.0;
    for (int run = 1; run <= 5; run++) {
        double start_time = omp_get_wtime();

        #pragma omp parallel for num_threads(4) schedule(guided)
        for (int i = 1; i <= 10000; i++) {
            std::vector<int> arr(i);

            for (int j = 0; j < i; j++) {
                arr[j] = rand() % 100;
            }
            std::sort(arr.begin(), arr.end());
        }

        double end_time = omp_get_wtime();
        total_time_4_guid += (end_time - start_time);
    }
    double avg_time_4_guid = total_time_4_guid / 5;

    std::cout << "Static (2 potoka) - Srednee vremia: " << avg_time_2_stat << " sekund." << std::endl;
    std::cout << "Static (4 potoka) - Srednee vremia: " << avg_time_4_stat << " sekund." << std::endl;
    std::cout << "Dynamic (2 potoka) - Srednee vremia: " << avg_time_2_dyn << " sekund." << std::endl;
    std::cout << "Dynamic (4 potoka) - Srednee vremia: " << avg_time_4_dyn << " sekund." << std::endl;
    std::cout << "Guided (2 potoka) - Srednee vremia: " << avg_time_2_guid << " sekund." << std::endl;
    std::cout << "Guided (4 potoka) - Srednee vremia: " << avg_time_4_guid << " sekund." << std::endl;

    return 0;
}