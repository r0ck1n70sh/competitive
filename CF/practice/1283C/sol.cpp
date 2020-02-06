#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	vector<int> f(n), in(n), out(n);
	for(int i=0;i<n;i++){
		cin>>f[i]; --f[i];
		if(f[i]!=-1){++out[i]; ++in[f[i]];}
	}
	vector<int> loops;
	for(int i=0;i<n;i++)
		if(in[i]==0&&out[i]==0) loops.push_back(i);
	if(loops.size()==1){
		int idx=loops[0];
		for(int i=0;i<n;i++){
			if(in[i]==0&&i!=idx){
				f[idx]=i; ++out[idx]; ++in[i]; break;
			}
		}
	}
	else {
		for(int i=0;i<int(loops.size());i++) {
			int cur=loops[i];
			int nxt=loops[(i+1)%int(loops.size())];
			f[cur]=nxt; ++out[cur]; ++in[cur];
		}
	}
	loops.clear(); vector<int> ins, outs;
	for(int i=0;i<n;i++){
		if(in[i]==0) ins.push_back(i);
		if(out[i]==0) outs.push_back(i);
	}
	for(int i=0;i<int(outs.size());i++) f[outs[i]]=ins[i];
	for(int i=0;i<int(f.size());i++) cout<<f[i]+1<<" ";
	cout<<"\n";
}
