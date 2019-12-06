#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define maxl 100000
#define min(a,b) (a<b)?a:b
double avg(int *a, int n);
int main() {
	int *a;
	int n, k, m;
	int i, meani, meanf;
	scanf("%d %d %d\n", &n, &k, &m);
	a=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d", a+i);
	std::sort(a, a+n);
	i=0;
	meanf=avg(a,n);
	do{
		i++;
		meani=meanf;
		meanf=avg(a+i, n-i);
	}while(meanf>meani&&i<=n&&i<=m);
	i-=1;
	if((m-i)/(n-i)>k)
		m=k+i;

	printf("%lf\n", (double)avg(a+i, n-i)+(double)(m-i)/(double)(n-i));
	return 0;
}
double avg(int *a, int n) {
	int i, sum=0;
	for(i=0; i<n; i++)
		sum+=a[i];
	return (double)sum/(double)n;
}
