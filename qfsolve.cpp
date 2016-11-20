
#include <iostream>
#include <cmath>

using namespace std;

double qfsolve(double a, double b, double c){
	/**
	 * @brief Solves the given quadratic equation.
	 *
	 * This function, given real coefficients A, B, C to the equation
	 * A*x*x + B*x + C = 0, returns the real part of a solution to the
	 * equation thus defined. Where two real solutions exist, the one
	 * closer to positive infinity is chosen.
	 *
	 * @param a the quadratic coefficient.
	 * @param b the linear coefficient.
	 * @param c the constant coefficient.
	 *
	 * @return the real part of a solution to the defined quadratic equation,
	 *         as described.
	 */
	return (-b + (sqrt((b * b) - (4 * a * c)))) / (2 * a);
}

int main(int argc, char ** argv)
{
	double a, b, c;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;
	
	double answer = qfsolve(a, b, c);
	cout << "Answer = " << answer << endl;
	
	return 0;
}
