//
// Created by vicebaraban
//
// Simple program for analysis quad equation (do all moments)
//

#include <stdio.h>
#include "quadEquAnalysis.h"


int main() {
    double a, b, c, x1, x2, cxa, cxb;
    scanf("%lf%lf%lf",&a, &b, &c); // input equation coeffs

    // check status and do valid output
    switch (quadEquAnalysis(a, b, c, &x1, &x2, &cxa, &cxb)) {
        case TWO_REAL_ROOTS:
            printf("Status: two real roots\nResult: %.3lf, %.3lf" , x1, x2);
            break;
        case ONE_MULT_ROOT:
            printf("Status: one multiple real root\nResult: %.3lf" , x1);
            break;
        case TWO_COMPLEX_ROOTS:
            printf("Status: two complex roots\n"
                   "Result: %.3lf+%.3lfi, %.3lf-%.3lfi", cxa, cxb, cxa, cxb);
            break;
        case ONE_ROOT_LINEAR_EQUATION:
            printf("Status: it's linear equation, one real root\n"
                   "Result: %.3lf" , x1);
            break;
        case NO_ROOTS:
            printf("Result: no roots");
            break;
        case ANY_REAL_ROOT:
            printf("Result: root is any real number");
            break;
        case INVALID_COEFFS:
            printf("Invalid coefficients of the equation");
            break;
    }
    return 0;
}