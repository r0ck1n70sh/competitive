#include <bits/stdc++.h>
using namespace std;
#define ll long long unsigned int
#define maxl 100000
bool posible(int, int);
ll INF=-1;
ll decod(int);
ll memo[maxl];
char str[maxl];
int n;
int main() {
	while(true) {
		memset(memo,-1,sizeof memo);
	//	cin>>str;
	//	scanf("%[^\n]&*c", str);
		scanf("%s",str);
		n=strlen(str);
		if(str[0]=='0')	break;
		printf("%llu\n", decod(0));
	}
	return 0;
}
ll decod(int i) {
	if(memo[i]<INF)
		return memo[i];
	if(str[i]=='0')
		return memo[i]=0;
	if(i>n-2)
		return memo[i]=1;
	ll count=0;
	if(posible(i,i+1))
		count+=decod(i+2);
	count+=decod(i+1);
	return memo[i]=count;
}
bool posible(int a, int b) {
	if (str[a]=='0')
		return 0;
	int num=(str[a]-'0')*10+(str[b]-'0');
	if(num<27)
		return 1;
	else return 0;
}
