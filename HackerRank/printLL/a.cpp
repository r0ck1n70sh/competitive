#include <bits/stdc++.h>
using namespace std;
struct nodeLL {
	int data;
	nodeLL *next;
};
nodeLL *newNode(int e);
class linkedL {
	public:
		nodeLL *head;
		linkedL() {
			this->head=NULL;
	    }
		void printLL();
		void push_back(int);
};
void linkedL::printLL() {
	if(head==NULL)
		return;
	nodeLL *temp1= head;
	while(temp1->next!=NULL) {
		temp1=temp1->next;
		printf("%d\n",temp1->data);
	}
}
void linkedL::push_back(int e) {
	if(head==NULL)
		head=newNode(e);
	nodeLL *temp1=head;
	while(temp1->next!=NULL)
		temp1=temp1->next;
	
	temp1->next= newNode(e);
}
int main() {
	int t, x;
	linkedL Q;
	scanf("%d", &t);
	while(t) {
		scanf("%d", &x);
		Q.push_back(x);
		t--;
	}
	Q.printLL();
	return 0;
}
nodeLL *newNode(int e) {
	nodeLL *temp=new nodeLL;
	temp->data=e;
	temp->next=NULL;
	return temp;
}
