#include <bits/stdc++.h>
#define maxl 100
#define F(i,a,b) for(int i=a; i<b; i++)
using namespace std;
bool solve(int);
struct Query {
	int hit, match;
	int guess[10];
	int freq[101];
}query[maxl];
int sol[10];
int P, C, M;
int main(){
	int T, g;
	scanf("%d", &T);	
	while(T) {
		memset(query,0,sizeof query);
		scanf("%d%d%d",&P,&C,&M);
		F(m,0,M) {
			F(i,0,P) {
				scanf("%d",&g);
				query[m].guess[i]=g-1;
				++query[m].freq[g-1];
			}
			scanf("%d%d", &query[m].hit, &query[m].match);
			query[m].match+=query[m].hit;
		}
		if(!solve(0))
			printf("You are cheating!");
		else
			F(i,0,P)
				printf("%d ", sol[i]+1);
		printf("\n");	
		--T;
	} 	
	return 0;
}
bool solve(int p) {
	F(m,0,M)
		if(query[m].hit<0 || query[m].hit>P-p || query[m].match<0 || query[m].match>P-p)
			return 0;
	if(p==P) return 1;
	
	F(c,0,C) {
		sol[p]=c;
		F(m,0,M) {
			if(query[m].guess[p]==c)	--query[m].hit;
			if(query[m].freq[c]-->0)	--query[m].match;
		}
		if(solve(p+1)) return 1;
		
		F(m,0,M) {
			if(query[m].guess[p]==c)	++query[m].hit;
			if(++query[m].freq[c]>0)	++query[m].match;
		}
	}
	return 0;
}
