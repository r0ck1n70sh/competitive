#include <cstdio>
class stack {
//	private:
	public:
		int end;
		char arr[150];
//	public:
		void push(char ch);
		char pop();
	stack() {
		end=-1;
	}
	~stack() {
//		printf("END:%d\n", end);
	}
};
void stack::push(char ch) {
//	printf("::%d\n", end);
	arr[++end]=ch;
}
char stack::pop() {
	if(end>-1)
		return arr[end--];
	else
		return '0';
}
int main() {
	int s, i;
	char ch;
	struct stack str;
	scanf("%d\n", &s);
	for(i=0;i<s;i++) {
		scanf("%c ", &ch);
		str.push(ch);
	}
	for(i=0;i<s;i++)
		printf("%c ", str.pop());
	return 0;
}
