#include <stdio.h>
#include <omp.h>
#include <math.h>

double f(double x) {
    // return sin(x);
    return 4 - x * x;
    // return x * x - 3;
}

// метод дихотомии
double find_root(double a, double b, double eps) {
    double c;
    while (b - a > eps) {
        c = (a + b) / 2.0;
        if (f(a) * f(c) <= 0)
            b = c;
        else
            a = c;
    }
    return (a + b) / 2.0;
}

double find_max(double a, double b, double eps) {
    double phi = (1 + sqrt(5)) / 2.0;
    double x1;
    double x2;
    while (b - a > eps) {
        x1 = b - (b - a) / phi;
        x2 = a + (b - a) / phi;

        if (f(x1) < f(x2))
            a = x1;
        else
            b = x2;
    }
    return (a + b) / 2.0;
}

int main() {
    // double root = find_root(-1.0, 3.0, 1e-6);
    // printf("Корень: %f\n", root);

    // double max = find_max(-1.0, 3.0, 1e-6);
    // printf("Максимум: %f\n", max);
    // return 0;

    double a = -1.0;
    double b = 3.0;
    double eps = 1e-6;

    double root;
    double max;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            root = find_root(a, b, eps);
            printf("Поток %d: Корень = %f\n", omp_get_thread_num(), root);
        }

        #pragma omp section
        {
            max = find_max(a, b, eps);
            printf("Поток %d: Максимум в точке x = %f, f(x) = %f\n", omp_get_thread_num(), max, f(max));
        }
    }
    return 0;
}


