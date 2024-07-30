# include <stdio.h>
# include <math.h>

double integrate(double (*exp)(double), double start, double end, double minimal) {
    printf("%.100lf\n", end - start);
    if ( end - start <= minimal ) return exp(start) * (end - start);
    return integrate(exp, start, (start + end) / 2.0, minimal) + integrate(exp, (start + end) / 2.0, end, minimal);
}

double myexp(double x) {
    return x / 2;
}

int main(int arg_number, char **arg_value) {
    double input = 0, minimal = 0;
    scanf("%lf %lf", &input, &minimal);
    printf("result = %lf\n", ceil(integrate(myexp, 0, input, minimal)));
    return 0;
}
