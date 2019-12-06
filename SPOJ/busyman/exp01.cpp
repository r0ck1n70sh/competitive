#include <bits/stdc++.h>

class activity {
	public:
		int start, end;
};

bool compEnd(activity a, activity b);

int main(){
	int t, n, ans;
	int currEnd, thisStart;
	scanf("%d", &t);
	
	while(t) {
		ans=1;
		scanf("%d", &n);
		activity *arr= (activity*)malloc(2*n*sizeof(int));
		
		for(int i=0; i<n; i++)
			scanf("%d%d", &arr[i].start, &arr[i].end);
		
		std::sort(arr, arr+n, compEnd);
		
	//	for(int i=0; i<n; i++)
	//		printf("%d %d | ", arr[i].start, arr[i].end);
	
		for(int i=0; i<n; i++) {
			currEnd=arr[i].end;
			for(int j=i+1; j<n; j++) {
				thisStart= arr[j].start;
				if(thisStart>=currEnd) {
					ans++;
					i=j-1;
					break;
				}
			}
		}
		printf("%d\n", ans);
		t--;
	}
}

bool compEnd(activity a, activity b) {
	return (a.end<b.end);
}
