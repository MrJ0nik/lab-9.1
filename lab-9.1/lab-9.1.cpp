#include <iostream>
#include <iomanip>
#include <cmath>
#include "var.h"
#include "sum.h"

using namespace std;
using namespace nsVar;
using namespace nsSum;

int main() {
    cout << "xp = "; cin >> x_p;
    cout << "xk = "; cin >> x_k;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-----------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(10) << "cos(x)" << " |"
        << setw(10) << "S" << " |"
        << setw(5) << "n" << " |" << endl;
    cout << "-----------------------------------------" << endl;

    x = x_p;
    while (x <= x_k) {
        s = S(x, eps, n, s);
        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(10) << setprecision(5) << cos(x) << " |"
            << setw(10) << setprecision(5) << s << " |"
            << setw(5) << n << " |" << endl;

        x += dx;
    }

    cout << "-----------------------------------------" << endl;
    return 0;
}
