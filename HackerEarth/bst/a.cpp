#include <bits/stdc++.h>
#define maxl 1000+1
#define F(i,a,b) for(int i=a; i<b; i++)
struct bstNode {
	int data;
	bstNode *left, *right;
};
bstNode *newbstNode(int);
bstNode *insert(bstNode *, int);
bstNode *findNode(bstNode *, int);
void preOrder(bstNode *);
int main() {
	bstNode *ptr, *root=NULL;
	int n ,q;
	int arr[maxl];
	scanf("%d", &n);
	F(i,0,n)
		scanf("%d", arr+i);
	scanf("%d", &q);
	F(i,0,n)
		root= insert(root, arr[i]);
	ptr= findNode(root, q);
	preOrder(ptr);
	
	return 0;
}
bstNode *newbstNode(int val) {
	bstNode *temp= new bstNode;
	temp->data=val;
	temp->left=NULL; temp->right=NULL;
	return temp;
}
bstNode *insert(bstNode *root, int data) {
	if(root==NULL)
		return newbstNode(data);
	if(data<=root->data)
		root->left= insert(root->left, data);
	else
		root->right= insert(root->right, data);
	return root;		
}
bstNode *findNode(bstNode *root, int data) {
	if(root->data==data)
		return root;
	if(data<=root->data)
		root= findNode(root->left, data);
	else
		root= findNode(root->right, data);
	return root;
}
void preOrder(bstNode *root) {
	if(root==NULL)
		return;
			
	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}
