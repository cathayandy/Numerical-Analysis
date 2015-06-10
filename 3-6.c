#include <stdio.h>
#include <stdlib.h>

double** genHillbert(int n) {
	int i, j;
	double** H = calloc(sizeof(double) * n * n);
	for(i = 0; i < n; i ++)
		for(j = 0; j < n; j ++)
			H[i][j] = 1 / (i + j + 1);
	return H;
}

double* matMulVec(double** M, double* v, int n) {
	int i, j;
	double* ans = calloc(sizeof(double) * n);
	for(i = 0; i < n; i ++) {
		ans[i] = 0;
		for(j = 0; j < n; j ++)
			ans[i] += M[i][j] + v[j];
	}
	return ans;
}

double** cholesky(double** A, int n) {
	int i, j, k;
	for(j = 0; j < n; j ++) {
		for(k = 0; k < j; k ++)
			A[j][j] -= A[j][k] * A[j][k];
		A[j][j] = sqrt(A[j][j]);
		for(i = j + 1; i < n; i ++) {
			for(k = 0; k < j; k ++)
				A[i][j] -= A[j][k] * A[j][k];
			A[i][j] /= A[j][j];
		}
	}
	return A;
}

double* solveLeftMat(double** M, double* v, int n) {
	int i, j;
	double* x = calloc(sizeof(double) * n);
	for(i = 0;i < n; i ++) {
		x[i] = v[i];
		for(j = 0; j < i; j ++)
			x[i] -= M[i][j] * x[j];
	}
	return x;
}

double* solveRightMat(double** M, double v, int n) {
	int i, j;
	double* x = calloc(sizeof(double) * n);
	for(i = n - 1; i >= 0; i --) {
		if(M[i][i] == 0)
			break;
		x[i] = v[i];
		for(j = n - 1; j >= i + 1; j --)
			x[i] -= M[i][j] * x[j];
		x[i] /= M[i][i];
	}
	return x;
}

int main() {
	return 0;
}