//dp with no recursion

#include <bits/stdc++.h>
#define maxl 2025
#define charl 26
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define ll long long unsigned int
using namespace std;
int val[charl];
ll l[maxl][maxl];
ll hcs(int, int, string&, string&);
int main() {
	int n, m;
	string a1, a2;
	scanf("%d%d", &n, &m);
	F(i,0,charl)
		scanf("%d", val+i);
	cin>>a1>>a2;
	printf("%llu\n", hcs(n,m,a1,a2));
	
	return 0;
}
ll hcs(int n1, int n2, string &s1, string &s2) {
	F(i,0,n2)
		l[i][0]=0;
	F(j,0,n1)
		l[0][j]=0;
	
	F(i,1,n2+1) {
		F(j,1,n1+1) {
			if(s1[i-1]==s2[j-1])
				l[i][j]=val[(s1[i-1]-'a')]+l[i-1][j-1];
			else
				l[i][j]=max(l[i-1][j], l[i][j-1]);
		}
	}	
	return l[n2][n1];
}
