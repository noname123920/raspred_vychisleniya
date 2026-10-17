#include <stdio.h>
#include <vector>
// #define N 5

int main() {
    // int x = 42;
    // int *p = &x;
    // *p = 100;

    // printf("x = %d\n", x);
    // printf("&x = %p\n", &x);
    // printf("p = %p\n", p);
    // printf("*p = %d\n", *p);
    // printf("после *p = 100: x = %d\n", x);

    // int x = 42;
    // void *vp = &x;
    // printf("*(int*)vp = %d\n", *(int*)vp);

    for (int k = 1; k <= 5; k++) {
        std::vector<int> arr(k);
        std::cout << "Krug nomer: " << k << ". Sozdan shkaf razmerom: " << arr.size() << "yashikov" << std::endl;
    }

    return 0;
}