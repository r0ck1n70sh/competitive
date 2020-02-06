#include <bits/stdc++.h>
using namespace std;
string multiply(string &F, string &S){
	int n= F.length(), m=S.length();
	reverse(F.begin(), F.end());
	reverse(S.begin(), S.end());
	vector<int> res(n+m+1, 0);
	int n1=0;
	for(int s=0; s<m; s++){
		int carry=0;
		int n2=0;
		for(int f=0; f<n; f++){
			int ans=(F[f]-'0')*(S[s]-'0')+res[n1+n2]+carry;
			res[n1+n2]=(ans%10);
			carry=ans/10;
			n2++;
		}
		if(carry>0){
			res[n1+n2]+=carry;
		}
		n1++;
	}
	int l;
	for(l=n+m; l>=0; l--)
		if(res[l])
			break;
	//printf("%d: ", res[l]);
	if(l==-1)
		return "0";
	string str="";
	reverse(res.begin(),res.begin()+l+1);
	for(int i=0; i<=l; i++)
		str+=res[i]+'0';
	return str;
}
int main(){
	int t;
	string l1, l2;
	scanf("%d", &t);
	while(t--){
		cin>>l1>>l2;
		//cout<<l1<<" "<<l2<<"\n";
		if(l1.length()<l2.length())
			swap(l1, l2);
		cout<<multiply(l1, l2)<<"\n";
		l1.clear(); l2.clear();		
	}
	return 0;
}
