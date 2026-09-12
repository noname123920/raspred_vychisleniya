#include <iostream>
#include <omp.h>

int main(){
#pragma omp parallel num_threads(4)
{
int id = omp_get_thread_num();

if (id % 2 == 0) {
std::cout << "Even-numbered thread: " << id << "\n";
}
else {
std::cout << "Odd-numbered thread: " << id << "\n";
}
}

return 0;
}