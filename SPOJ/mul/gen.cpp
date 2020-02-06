#include <bits/stdc++.h>
#define MAX 100001
int rand(int a, int b){
	return a+ rand()%(b-a+1);
}
int main(int argv, char *argc[]){
	srand(atoi(argc[1]));
	int t= rand(1,10);
	printf("%d\n", t);
	while(t--){
		printf("%d %d\n", rand(0,MAX), rand(0,MAX));
	}
	return 0;
}
