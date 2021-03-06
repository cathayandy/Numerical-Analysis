#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const double D1 = 0.1;
const double D2 = 1e-4;
const double L = 0.999;
FILE* out;

typedef double (*PDD)(double);

double f1(double x) {
	return x * x * x - x - 1;
}

double f2(double x) {
	return -x * x * x + 5 * x;
}

double dF1(double x) {
	return 3 * x * x - 1;
}

double dF2(double x) {
	return -3 * x * x + 5;
}

double newton(double x0, PDD f, PDD df, double delta1, double delta2, double lamda) {
	int k = 0;
	double x[2] = {x0, f(x0)}, ans = x0;
	fprintf(out, "Before the 1st iteration: lamda = %f, epsilon = %f\n", lamda, delta2);
	while(fabs(f(ans)) > delta1 || fabs(x[1] - x[0]) > delta2) {
		double s = f(ans) / df(ans);
		double l = lamda;
		ans = x[1] - s;
		while(fabs(f(ans)) >= fabs(f(x[1]))) {
			ans = x[1] - l * s;
			l /= 2;
		}
		k ++;
		fprintf(out, "Iteration%d: x = %f, lamda = %f\n", k, ans, l);
		x[0] = x[1];
		x[1] = ans;
	}
	return ans;
}

int main() {
	FILE* fileout = fopen("../result/ex2_2.txt", "w");
    out = fileout;
    fprintf(out, "The final answer is: %f\n", newton(0.6, &f1, &dF1, D1, D2, L));
	fprintf(out, "The final answer is: %f\n", newton(1.2, &f2, &dF2, D1, D2, L));
    fclose(fileout);
	return 0;
}