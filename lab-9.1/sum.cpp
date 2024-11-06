#include "sum.h"
#include "dod.h"
#include "var.h"
#include <math.h>

using namespace nsDod;
using namespace nsVar;

namespace nsSum {
    double S(const double x, const double eps, int& n, double s) {
        n = 0;
        double a = 1;
        s = a;
        do {
            n++;
            a = A(x, n, a);
            s += a;
        } while (fabs(a) >= eps);
        return s;
    }
}
