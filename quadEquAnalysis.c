//
// Created by USER on 28.10.2022.
//

#include <math.h>

enum status {TWO_REAL_ROOTS, ONE_MULT_ROOT, TWO_COMPLEX_ROOTS,
    ONE_ROOT_LINEAR_EQUATION, NO_ROOTS, ANY_REAL_ROOT,
    INVALID_COEFFS};


enum status quadEquAnalysis(double a, double b, double c,
        double *x1, double *x2, double *cxa, double *cxb) {
    double d, sqrt_d;
    d = b * b - 4 * a * c;
    if (isnan(a) || a == 0.0/0.0 ||
        isnan(b) || b == 0.0/0.0 ||
        isnan(c) || c == 0.0/0.0)
        return INVALID_COEFFS;
    else if (a != 0) {
        if (d > 0) {
            sqrt_d = sqrt(d);
            *x1 = (-b + sqrt_d) / 2 / a;
            *x2 = (-b - sqrt_d) / 2 / a;
            return TWO_REAL_ROOTS;
        }
        else if (d == 0) {
            *x1 = -b / 2 / a;
            return ONE_MULT_ROOT;
        }
        else if (d < 0) {
            sqrt_d = sqrt(-d);
            *cxa = -b / 2 / a;
            *cxb = sqrt_d / 2 / a;
            return TWO_COMPLEX_ROOTS;
        }
    }
    else if (b != 0) {
        *x1 = -c / b;
        return ONE_ROOT_LINEAR_EQUATION;
    }
    else if (c != 0) return NO_ROOTS;
    return ANY_REAL_ROOT;
}