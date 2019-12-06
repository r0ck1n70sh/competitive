#include <bits/stdc++.h>
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
using namespace std;
void simpleSieve(int,vector<int>&);
void segmentedSieve(int);
int n, m;
int main() {
	int T;
	scanf("%d", &T);
	while(T) {
		scanf("%d%d", &m, &n);
		segmentedSieve(n+1);
		cout<<endl;
		T--;
	}
}
void simpleSieve(int limit, vector<int> &prime) {
	bool mark[limit+1];
	memset(mark, 1, sizeof(mark));
	
	for(int p=2; p*p<limit; p++) {
		if(mark[p])
			for(int i=p*2; i<limit; i+=p)
				mark[i]=0;
	}
	F(p,2,limit)
	 if(mark[p]) {
		 prime.push_back(p);
		 if(p>=m)
		 printf("%d\n",p);
	}
}

void segmentedSieve(int n) {
	int limit=floor(sqrt(n))+1;
	vector<int>prime;
	simpleSieve(limit, prime);
	
	int low=limit;
	int high=2*limit;
	
	while(low<n) {
		if(high>=n) high=n;
		
		bool mark[limit+1];
			memset(mark, 1, sizeof mark);
		
		F(i,0,prime.size()) {
			 int loLim=floor(low/prime[i])*prime[i];
			 if(loLim<low)
				loLim+=prime[i];
				
			for(int j=loLim; j<high; j+=prime[i])
				mark[j-low]=false;
		}
			F(i,low,high)
				if(mark[i-low]&&i>=m)
					printf("%d\n",i);
					
					
			low=low+limit;
			high=high+limit;
	}
}

