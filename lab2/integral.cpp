#include <stdio.h>
#include <math.h>
#include <omp.h>
#include <numbers>


double f(double x) {
    return x * x;
}

int main() {
    double a = 0.0;
    // double pi = std::acos(-1.0);
    double b = 1.0;

    int N = 1000;
    double h =(b - a) / N;

    double sum = 0.0;
    
    int i;
    #pragma omp parallel for reduction(+:sum)
    for (i = 0; i < N; i++) {
        double x = a + (i + 0.5) * h;
        sum += f(x);
    }
    double integral = sum * h;

    double exact = 1.0 / 3.0;
    double error = fabs(integral - exact);

    printf("Приближенное значение интеграла: %.10f\n", integral);
    printf("Точное значение интеграла: %.10f\n", exact);
    printf("Абсолютная погрешность: %.10f\n", error);
}
