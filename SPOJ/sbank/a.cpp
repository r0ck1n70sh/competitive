#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t;
	string str;
	scanf("%d", &t);
	for(int i=0; i<t; i++) {
		map<string, int> M;
		scanf("%d\n", &n);
		for(int i=0; i<n; i++) {
			getline(cin, str);
			M[str]++;
		}
		for(auto it=M.begin(); it!=M.end(); it++)
			printf("%s %d\n",(*it).first.c_str(), (*it).second);
		if(t>1)
			printf("\n");
	}
	return 0;
}
