#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pt;
const int maxl=3e5+3, P=550;
int n, a[maxl];
vector<int> pos[maxl];
pt ans[maxl];

int cnt[maxl];
int tot;
void add(int x){
	++cnt[x]; if(cnt[x]==1) ++tot;
}
void rem(int x){
	if(cnt[x]==1) --tot; --cnt[x];
}
int f[maxl];
void udp(int x){
	for(int i=x;i>=0;i=(i&(i+1))-1) ++f[i];
}
int get(int x){
	int res=0;
	for(int i=x; i<maxl; i|=i+1) res+=f[i];
	return res;
}
int main(){
	
}
