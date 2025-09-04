#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x * x - 5 * x + 1;
}

int main() {
    double x0 = 0.0, x1 = 1.0, tol = 0.000001;
    double x2, f0, f1;
    int iter = 0, max_iter = 100;

    while (iter < max_iter) {
        f0 = f(x0);
        f1 = f(x1);
        if (fabs(f1 - f0) < 1e-12) {
            return 1;
        }
        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        printf("Iteration %d: x = %.6f\n", iter, x2);
        if (fabs(x2 - x1) < tol)
            break;
        x0 = x1;
        x1 = x2;
        iter++;
    }
    printf("Approximate root: %.6f\n", x2);
    return 0;
}
