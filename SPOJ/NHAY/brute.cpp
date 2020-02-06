#include <bits/stdc++.h>
using namespace std;
const int maxl=(1e6+10);
char pat[maxl], text[maxl], lsp[maxl];
void prefix(char *s){
	int n=strlen(s), j=0, i; bool flag=1; lsp[0]=0;
	for(int i=1; i<n; i++){
		while(j>0&&s[j]!=s[i]){
			j=lsp[j-1]; if(s[i]==s[j]) j++; lsp[i]=j;
		}
	}
}
void search(char *text, char *pat){
	int len=strlen(text), m=strlen(pat), j=0; bool flag=1;
	for(int i=0; i<len; i++){
		while(j>0&&text[i]!=text[j]) j=lsp[j-1];
		if(text[i]==pat[j]) j++;
		if(j==m) {printf("%d\n", i-m+1); j=lsp[j-1];}
	}
	if(flag) printf("\n");
}
int main(){
	int n;while(scanf("%d\n",&n)!=EOF){
		memset(lsp, 0, sizeof(lsp)); scanf("%s", pat); prefix(pat);
		scanf("%s", text); search(text,pat);
	}
	return 0;
}
