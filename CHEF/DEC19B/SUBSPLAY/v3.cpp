//dp approach

#include <bits/stdc++.h>
#define maxl (int)(1e5+5)
using namespace std;

int main(){
	int T, N;
	char S[maxl];
	int index[26];
	scanf("%d", &T);
	
	while(T) {
		memset(index, 0, sizeof(index));
		scanf("%d\n", &N);
		
		for(int i=0; i<N; i++)
			scanf("%c", S+i);
			
		int k=0;
		set<char> s; 
		for(int i=0; i<N; i++){
			if(s.count(S[i])==0)
				s.insert(S[i]);
			else 
				k= max(k, index[S[i]-'0']+1);
			index[S[i]-'0']=i;
		}
		
		printf("%d\n", k);		
		--T;
	}
	return 0;
}

