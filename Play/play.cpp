#include<stdio.h>
int main()
{
	unsigned int a1, b1, a2, b2;
	float t1, t2;
	scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);
	t1 = 1.0 * a1 / b1;
	t2 = 1.0 * a2 / b2;
	if (t1 < t2)
		printf("%d/%d<%d/%d", a1,b1, a2,b2);
	if (t1 == t2)
		printf("%d/%d=%d/%d", a1, b1, a2, b2);
	if (t1 > t2)
		printf("%d/%d>%d/%d", a1, b1, a2, b2);
	return 0;
}