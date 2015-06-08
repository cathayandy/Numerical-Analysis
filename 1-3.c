#include <stdio.h>

int main() {
	float ans = 0, last;
	int n = 1;
	int i;
	long long dN = 0x0fffffffffffff80;
	double dAns = 0, delta;
	while(1) {
		last = ans;
		ans += 1 / (float)n;
		if(n % 100000 == 1)
			printf("n=%d sum=%.6f\n", n, ans);
		if(last == ans)
			break;
		n ++;
	}
	printf("The sum does not vary when n is greater than or equals to %d.\nThe sum is %.6f.\n", n, ans);
	for(i = 1; i <= n; i ++)
		dAns += 1 / (double)i;
	printf("The sum in double is %f.\n", dAns);
	printf("%lld\n", dN);
	delta = 1 / (double)dN;
	if(16.0 + delta == 16.0)
		printf("Yes.\n");
	else
		printf("No.\n");
	return 0;
}