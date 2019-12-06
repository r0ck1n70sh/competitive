#include <bits/stdc++.h>
using namespace std;
#define mod 100000+3
struct node {
	int roll;
	string name;
};
int hashF(int);
void addNode(node);
void findName(int);
array<vector<node>, mod> hashT;
int main() {
	int n, q, roll;
	string name;
	node p;
	scanf("%d", &n);
	while(n) {
		cin>>roll>>name;
		p.roll=roll;
		p.name=name;
		addNode(p);
		--n;
	}
	scanf("%d", &q);
	while(q) {
		scanf("%d", &roll);
		findName(roll);
		--q;
	}
	return 0;
}
void addNode(node curr) {
	int index=hashF(curr.roll);
	hashT[index].push_back(curr);
}
void findName(int roll) {
	int index=hashF(roll);
	for(auto it=hashT[index].begin(); it!=hashT[index].end(); ++it)
		if(it->roll==roll) {
			cout<<it->name<<"\n";
			break;
		}
}
int hashF(int n) {
	return n%mod;
}
