#include "dod.h"

namespace nsDod {
    double A(const double x, const int n, double a) {
        double R = (-1.0) * ((x * x) / ((2.0 * n) * (2.0 * n - 1.0)));
        a *= R;
        return a;
    }
}
