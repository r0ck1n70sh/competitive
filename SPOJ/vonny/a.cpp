#include <bits/stdc++.h>
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
using namespace std;
int box[7][8];
bool vis[7][8];
bool check[7][7];
int ways;
int c;
void rotate(int&, int&, int);
bool possible(int, int);
int main() {
	int t;
	scanf("%d", &t);
	while(t) {
		memset(vis,0,sizeof vis);
		memset(check,0, sizeof check);
		ways=0;
		c=28;
		F(i,0,7)
			F(j,0,8)
				scanf("%d", &box[i][j]);
		possible(0,0);
		printf("%d\n", ways);
		--t;
	}
	return 0;
}
bool possible(int x, int y) {
	if(c==0) {
		return 1;
		ways++;
	}		
	F(i,x,7) {
		F(j,y,8) {
			if(vis[i][j])
				continue;
			vis[i][j]=1;
			
			F(k,0,4) {
				int p=i, q=j;
				rotate(p, q, k);
				if(p>6||q>7)
					continue;
				int ma=max(box[i][j], box[p][q]);
				int mi=min(box[i][j], box[p][q]);
				if(vis[p][q]&&check[mi][ma])
					continue;
				vis[p][q]=1;
				check[mi][ma]=1;
				c--;
				if(possible(i,j+1))
					return 1;
				check[mi][ma]=0;
				vis[p][q]=0;				
			}
			vis[i][j]=0;	
		}
	}
	return 0;	
}
void rotate(int &p, int &q, int k) {
	switch(k) {
		case 0: p++;
		break;
		case 1: q++;
		break;
		case 2: p--;
		break;
		default: q--;
	}
}
