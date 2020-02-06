#include <bits/stdc++.h>
using namespace std;
int rand(int a, int b){
	return a+rand()%(b-a+1);
}
int main(int argv, char *argc[]){
	srand(atoi(argc[1]));
	int n=rand(1,10), a=rand(1,10), b=rand(1,10);
	printf("%d\n%d %d\n", n, a, b);
	return 0;
}
