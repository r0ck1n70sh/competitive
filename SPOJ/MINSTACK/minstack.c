#include <stdio.h>
#define MAX 15 
int top=-1;
int stack[1000001];
char buf[MAX];
void pop();
void push(int v);
void minV();
int getV();

int main() {
	int n;
	scanf("%d", &n);
	n++;
	while(n--) {
		fgets(buf, MAX, stdin);
		switch(buf[1]) {
			case 73: minV();
			break;
			case 79: pop();
			break;
			case 85: push(getV());
		}
	}	
	return 0;
}

void minV() {
	int i, min=1000000001;
	if(top>-1) {	
		for(i=top; i>-1; i--)
		if(stack[i]<min)
			min=stack[i];	
		printf("%d\n", min);
	}
	else
		printf("EMPTY\n");
}

void pop() {
	if(top>-1)
		top--;
	else
		printf("EMPTY\n");
}

void push(int v) {
	if(top<1000001)
		stack[++top]=v;
}

int getV() {
	int v;
	sscanf(buf+5, "%d", &v);
	return v;
}
