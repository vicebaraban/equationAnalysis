#ifndef EQUATIONANALYSIS_QUADEQUANALYSIS_H
#define EQUATIONANALYSIS_QUADEQUANALYSIS_H
enum status {TWO_REAL_ROOTS, ONE_MULT_ROOT, TWO_COMPLEX_ROOTS,
    ONE_ROOT_LINEAR_EQUATION, NO_ROOTS, ANY_REAL_ROOT,
    INVALID_COEFFS};
enum status quadEquAnalysis(double a, double b, double c,
                            double *x1, double *x2, double *cxa, double *cxb);
#endif