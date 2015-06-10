#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	float ans = 0, last;
	int n = 1;
	long long i;
	long long dN = 0x0001000000000000;
	double dAns = 0, delta, sum, ori = 33.333, cha, tmp = 0, time, absolute_deviation, relative_deviation;
    clock_t s, t;
    FILE* fileout = fopen("../result/ex1_3.txt", "w"), *out = fileout;
	while(1) {
		last = ans;
		ans += 1 / (float)n;
		// if(n % 100000 == 1) printf("n=%d sum=%.6f\n", n, ans);
		if(last == ans)
			break;
		n ++;
	}
	fprintf(out, "Problem 1:\nThe sum does not vary when n is greater than or equals to %d in single precision. The sum is %.6f.\n", n, ans);
	for(i = 1; i <= n; i ++)
		dAns += 1 / (double)i;
    absolute_deviation = (double)ans - dAns;
    relative_deviation = ((double)ans - dAns) / dAns;
	fprintf(out, "Problem 2:\nThe sum in double is %f. The absolute deviation is %f. The relative deviation is %f.\n", dAns, absolute_deviation, relative_deviation);
	fprintf(out, "Problem 3:\nThe sum does not vary when n is greater than or equals to %lld in double precision.\n", dN);
	delta = 1 / (double)dN;
    sum = ori + delta;
    /* cha = sum - ori;
    printf("%016llx\n%016llx\n%016llx\n%016llx\n", *(long long *)(&delta), *(long long *)(&ori), *(long long *)(&sum), *(long long *)(&cha));
    printf("Does sum + delta == sum?\n");
	if(sum == ori)
		printf("Yes.\n");
	else
		printf("No.\n"); */
    s = clock();
    for(i = 1; i <= 100000000; i ++)
		tmp += 1 / (double)i;
    t = clock();
    time = (double)(t - s) / CLOCKS_PER_SEC;
    fprintf(out, "Time to calc 10^8 times is %fs. The total time will be %.0fs, which is about %d days.\n", time, time * dN / 1e8, (long long)(time * dN / 1e8 / 24) / 3600);
    fclose(fileout);
	return 0;
}