#include <bits/stdc++.h>
using namespace std;
#define max1 100000+1
#define max 1000000+1
#define PII pair<unsigned, pair<int, int>>
//#define PIIt pair<unsigned, pair<int, int>>::iterator
unsigned kruskal();
bool compCost(PII, PII);
int root(int);
void union1(int, int);
void initialize(int);
int id[max1];
vector<PII> V;
int N, M;
int main() {
	unsigned minCost , w;
	int x, y;
	scanf("%d%d", &N, &M);
	for(int i=0; i<M; i++) {
		scanf("%d%d%u", &x, &y, &w);
		V.push_back({w, {x, y}});
	}
	sort(V.begin(), V.end(), compCost);
	initialize(N);
	minCost= kruskal();
	printf("%d\n", minCost);
}
unsigned kruskal(){
	int x, y;
	unsigned minCost=0, cost;
	PII curr;
	
	for(int i=0; i<M; i++) {
		curr=V[i];	
		x=curr.second.first;
		y=curr.second.second;
		cost=curr.first;
		if(root(x)==root(y))
			continue;
		minCost+=cost;
		union1(x, y);	
	}
	return minCost;
}
int root(int x){
	while(id[x]!=x) {
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}
void union1(int x, int y) {
	int p=root(x), q=root(y);
	id[q]=id[p];
}
void initialize(int N) {
	for(int i=0; i<N; i++)
		id[i]=i;
}
bool compCost(PII a1, PII a2) {
	return (a1.first<a2.first);
}
