#include <bits/stdc++.h>
using namespace std;
class que {
    public:
        const int arr_size=101;
        int arr[101];
        int front=0, rear=0, count=0;
        bool isEmpty();
        int size();
        void enqueue(int);
        int dequeue();
};
bool que::isEmpty() {
    return (count==0);
}
int que::size() {
    return count;
}
void que::enqueue(int value) {
//	if(rear==front)
//		printf("Quene Overflow\n");
    ++count;
	arr[rear]=value;
	rear=(rear+1)%arr_size;
} 
int que::dequeue() {
	int res;
	if(count==0)
		return -1;
	--count;
	res=arr[front];
	front=(front+1)%arr_size;
	return res;
}
int main() {
	char query;
	int n, v;
	que q;
	scanf("%d", &n);
	while(n) {
		//scanf("%c",	&query);
		cin>>query;
		if(query-'D') {			//E case
		//	scanf("%d", &v);
			cin>>v;
			q.enqueue(v);
		}
		else				//D case
			printf("%d ", q.dequeue());
		printf("%d\n", q.size());
		--n;
	}
	return 0;
}
