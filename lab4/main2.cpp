#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_max(int arr[], int left, int right) {
    if (left == right) {
        return arr[left];
    }

    int mid = (left + right) / 2;
    int max_left, max_right;

    #pragma omp task shared(max_left)
    max_left = find_max(arr, left, mid);
    
    #pragma omp task shared(max_right)
    max_right = find_max(arr, mid + 1, right);

    #pragma omp taskwait
    if (max_left > max_right) {
        return max_left;
    } else {
        return max_right;
    }
}

int main() {
    srand(time(NULL));

    int n = 10;
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10;
        printf("%d ", arr[i]);
    }
    printf("\n");

    int result;
    #pragma omp parallel
    {
        #pragma omp single
        result = find_max(arr, 0, n - 1);
    } 
    printf("max_element: %d\n", result);
    
    return 0;
}