#include <bits/stdc++.h>
#define maxl 1510
using namespace std;
array<string, maxl> arr;
unordered_set <string> f;
int n, k, t=int('S'+'E'+'T');
char get(char c1, char c2){
	if(c1==c2) return c1;
	return t-c1-c2;
}
int main(){
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; i++){
		cin>>arr[i];
		f.insert(arr[i]);
	}
	int res=0;
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++){
			string s="";
			for(int p=0; p<k; p++)
				s.push_back(get(arr[i][p], arr[j][p]));
			if(f.count(s))
				res++;
		}
	printf("%d\n", res/3);			
}
