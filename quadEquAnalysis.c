//
// Analysis function
//

#include <math.h>
#include <stddef.h>
#include "quadEquAnalysis.h"


enum status quadEquAnalysis(double a, double b, double c,
        double *x1, double *x2, double *cxa, double *cxb) {
    double d, sqrt_d;

    // count roots if it's possible
    if (isnan(a) || isinf(c) ||
        isnan(b) || isinf(b) ||
        isnan(c) || isinf(c))
        return INVALID_COEFFS;
    else if (a != 0) {
        d = b * b - 4 * a * c; // discriminant
        if (d > 0) {
            sqrt_d = sqrt(d);
            if (x1 != NULL) *x1 = (-b + sqrt_d) / 2 / a;
            if (x2 != NULL) *x2 = (-b - sqrt_d) / 2 / a;
            return TWO_REAL_ROOTS;
        }
        else if (d == 0) {
            if (x1 != NULL) *x1 = -b / 2 / a;
            return ONE_MULT_ROOT;
        }
        else if (d < 0) {
            sqrt_d = sqrt(-d);
            if (cxa != NULL) *cxa = -b / 2 / a;
            if (cxb != NULL) *cxb = sqrt_d / 2 / a;
            return TWO_COMPLEX_ROOTS;
        }
    }
    else if (b != 0) {
        if (x1 != NULL) *x1 = -c / b;
        return ONE_ROOT_LINEAR_EQUATION;
    }
    else if (c != 0) return NO_ROOTS;
    return ANY_REAL_ROOT;
}