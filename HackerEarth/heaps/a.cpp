#include <bits/stdc++.h>
#define F(i,a,b) for(int i=a; i<b; i++)
#define maxl 1000000
using namespace std;
void swap(int*, int*);
class heap {
	public:
	int length;	
	int maxE();
	void insert(int);
	
	heap() {
		memset((this->arr),-1,sizeof(this->arr));
		length=0;
	}
	
	private:
	int arr[maxl+1];
	void heapify(int);
	
};
int main() {
	int n,q,x,k;
	heap H;
	scanf("%d", &n);
	F(i,0,n) {
		scanf("%d", &x);
		H.insert(x);
	}
	scanf("%d", &q);
	F(i,0,q) {
		scanf("%d", &k);
		if(k==1) {
			scanf("%d", &x);
			H.insert(x);
		}
		else
			printf("%d\n", H.maxE());
	}	
	return 0;	
}
void swap(int *a, int *b) {
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void heap::heapify(int i) {
	int maxch=i;
	int leftch= 2*i;
	int rightch= 2*i+1;
	
	if((this->arr[i])<(this->arr[leftch])&&leftch<=(this->length))
		maxch=leftch;
	if((this->arr[maxch])<(this->arr[rightch])&&rightch<=this->length)
		maxch=rightch;
	
	if(maxch==i)
		return;
	
	swap(&(this->arr[i]), &(this->arr[maxch]));
	this->heapify(maxch);
		
}
int heap::maxE() {
	return this->arr[1];
}
void heap::insert(int entry) {
	int i=++(this->length);	
	(this->arr[length])=entry;
	
	while(i>1&&(this->arr[i])>(this->arr[i/2])) {
		swap(&(this->arr[i]),&(this->arr[i/2]));
		i/=2;
	}
}


