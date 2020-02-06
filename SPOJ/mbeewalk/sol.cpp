#include <bits/stdc++.h>
#define ll long long int
#define O 25
#define MAX_STEPS 15
#define MAX_NIE 6
using namespace std;
ll walk[MAX_STEPS][2*O+1][2*O+1];
int main(){
	int xdist[MAX_NIE]= {-1,-1,0,1,1,0};
	int ydist[MAX_NIE]= {0,1,1,0,-1,-1};
	memset(walk, 0, sizeof(walk));
	walk[0][O][O]=1;
	//printf("running1\n");
	for(int step=1; step<MAX_STEPS; step++){
		for(int x=1; x<2*O; x++){
			for(int y=1; y<2*O; y++){
				for(int nie=0; nie<MAX_NIE; nie++){
					int xnie= x+ xdist[nie];
					int ynie= y+ ydist[nie];
					//printf("{%d %d %d} ", step, x, y);
					walk[step][x][y]+= walk[step-1][xnie][ynie];
				}
			}
		}
	}
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%lld\n", walk[n][O][O]);
	}	
	return 0;
}
