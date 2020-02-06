#include <bits/stdc++.h>
using namespace std;
const int maxl=(1e6+10);
char text[maxl], pat[maxl]; int lps[maxl];
void prefix(char *s){
	int n=strlen(s), j=0; lps[0]=0;
	for(int i=1; i<n; i++){
		while(j>0&&s[j]!=s[i]) j=lps[j-1]; 
		if(s[i]==s[j]) j++; lps[i]=j;
	}
	//for(int i=0; i<n; i++) printf("%d ", lps[i]); printf("\n");
}
void search(char *text, char *pat){
	int len=strlen(text), m=strlen(pat), j=0, flag=1;
	for(int i=0; i<len; i++){
		if(j>0&&text[i]!=pat[j]) j=lps[j-1];
		if(text[i]==pat[j]) j++;
		if(j==m) {printf("%d\n", i-m+1); j=lps[j-1]; flag=0;}
	}
	if(flag) printf("\n");
}
int main(){
	int n;while(scanf("%d\n",&n)!=EOF){
		memset(lps, 0, sizeof(lps)); scanf("%s", pat); prefix(pat);
		scanf("%s", text); search(text,pat);
	}
	return 0;
}
