#include <bits/stdc++.h>
using namespace std;
int maxD=0;
struct node {
	int data; int lh; int rh;
	node *l, *r;
};
int query(node *);
node *newNode(int val);
int main() {
	int t, x;
	string path;
	node *root, *ptr;
	scanf("%d%d", &t, &x);
	root= newNode(x); t--;
	while(t) {
		cin>>path>>x;	
		ptr=root;
		for(int i=0; i<path.length(); i++) {
			if(path[i]=='L') {
				if(ptr->l==NULL) {
					ptr->l= newNode(x);
					break;
				}
				ptr=ptr->l;
			}
			else {
				if(ptr->r==NULL) {
					ptr->r= newNode(x);
					break;
				}
				ptr=ptr->r;
			}			
		}
		t--;
	}
	x=query(root);
	printf("%d\n", maxD);		
	return 0;
}
int query(node *curr) {
	if(curr==NULL)
		return 0;
	curr->lh= query(curr->l);
	curr->rh= query(curr->r);
	
	if(maxD<1+(curr->lh)+(curr->rh))
		maxD=1+(curr->lh)+(curr->rh);
	
	return 1+max(curr->lh, curr->rh);
}
node *newNode(int val) {
	node *temp= new node;
	temp->data= val;
	temp->l=NULL; temp->r=NULL;
	return temp;
}
