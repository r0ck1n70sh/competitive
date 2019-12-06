#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	int t, n, i, ans;
	char *str;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		str=(char*)malloc(sizeof(char)*(n+1));
		scanf("%s", str);
		ans=0;
		if((str[1]=='0'&&str[0]=='0')||(str[0]=='0'&&n==1)) {
			str[0]='1';
			ans+=1;
		}
		for(i=1;i<n-1;i++) {
			if(str[i-1]=='0'&&str[i+1]=='0'&&str[i]!='1') {
				str[i]='1';
				ans+=1;
			}
		}
		if(str[n-2]=='0'&&str[n-1]=='0')
			ans+=1;
			
		printf("%d\n",ans);
		free(str);
	}
	return 0;
}
