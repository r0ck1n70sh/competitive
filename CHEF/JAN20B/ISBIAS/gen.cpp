#include <bits/stdc++.h>
using namespace std;
int rand(int a, int b){
	return a+rand()%(b-a+1);
}
int main(int argc, char* argv[]) {
	srand(atoi(argv[1]));
	int n=rand(2, 10) ,q=rand(2,n);
	printf("%d %d\n", n, q);
	set<int> used;
	for(int i=0; i<n; i++){
		int x;
		do {
			x=rand(1,20);
		}while(used.count(x));
		printf("%d ", x);
		used.insert(x);
	}
	printf("\n");
	for(int i=0; i<q; i++){
		int r=rand(2,n);
		int l= rand(1, r-1);
		printf("%d %d\n", l ,r);
	}
	puts("");
}
