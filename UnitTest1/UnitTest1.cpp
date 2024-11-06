#include "pch.h"
#include "CppUnitTest.h"
#include "../lab-9.1/lab-9.1.cpp"
#include "../lab-9.1/sum.cpp"
#include "../lab-9.1/dod.cpp"
#include "../lab-9.1/var.cpp"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nsVar;
using namespace nsSum;
using namespace nsDod;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Test_SFunctionAccuracy)
		{
			// Тест точності функції S
			double x = 0.5;
			double eps = 1e-6;
			int n = 0;
			double s = 0;

			double result = S(x, eps, n, s);
			double expected = cos(x);

			Assert::AreEqual(expected, result, eps, L"S function did not return expected value for cos(x)");
		}

		TEST_METHOD(Test_AFunctionCalculation)
		{
			// Тест функції A для першого члена ряду
			double x = 0.5;
			int n = 1;
			double a = 1.0;

			double result = A(x, n, a);
			double expected = -x * x / 2.0;

			Assert::AreEqual(expected, result, 1e-6, L"A function did not return expected value for first term of cos(x)");
		}

		TEST_METHOD(Test_SFunctionWithMultipleX)
		{
			// Перевірка точності S при змінних значеннях x
			double eps = 1e-6;
			int n = 0;
			double s;

			for (double x = 0.0; x <= 1.0; x += 0.2) {
				s = 0; // Скидаємо значення s перед кожним обчисленням
				s = S(x, eps, n, s);
				double expected = cos(x);

				Assert::AreEqual(expected, s, eps, L"S function did not converge to expected cos(x) value");
			}
		}

		TEST_METHOD(Test_SFunctionSmallEpsilon)
		{
			// Перевірка S на точність з маленьким epsilon
			double x = 0.5;
			double eps = 1e-12;
			int n = 0;
			double s = 0;

			double result = S(x, eps, n, s);
			double expected = cos(x);

			Assert::AreEqual(expected, result, eps, L"S function did not return expected value with high precision (small epsilon)");
		}
	};
}
