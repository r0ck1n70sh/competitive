#include <bits/stdc++.h>
#define MAX 256
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
using namespace std;

class Node {
	public:
	Node *children[MAX];
	Node *suffixLink;
	
	int start;
	int *end;
	int suffixIndex;
	
	Node(int, int*);
};
//typedef struct suffixTreeNode Node;

string text;
Node *root=NULL;

Node *lastNewNode=NULL;
Node *activeNode=NULL;

int activeEdge=-1;
int activeLength=0;

int remaining=0;
int leafEnd=-1;
int *rootEnd=NULL;
int *splitEnd=NULL;
int size=-1;

int edgeLength(Node *);
int walkDown(Node *);
void extendSuffix(int);

int main() {
	cin>>text;
	buildSuffixTree();
	return 0;
}
Node::Node(int start, int *end) {
	F(i,0,MAX)
		this->children[i]=NULL;
	this->suffixLink=root;
	this->start=start;
	this->end=end;
	this->suffixIndex=-1;
}
int edgeLength(Node *n) {
	if(n==root)
		return 0;
	return *(n->end)-(n->start)+1;
}
int walkDown(Node *currNode) {
	if(activeLength>=edgeLength(currNode)) {
		activeEdge+= edgeLength(currNode);
		activeLength-=edgeLength(currNode);
		activeNode= currNode;
		return 1;
	}
	return 0;
}
void extendSuffix(int pos) {
	leafEnd=pos;
	remaining++;
	lastNewNode=NULL;
	
	while(remaining) {
		if(activeLength==0)
			activeEdge=pos;
			
		if(activeNode->children==NULL) {
			activeNode->children= new Node(pos, &leafEnd);
		
			if(lastNewNode) {
				lastNewNode->suffixLink=activeNode;
				lastNewNode=NULL;
			}
		}
		else {
			Node *next= activeNode->children;
			
			if(walkDown(next))
				continue;
			
			if(text[next->start+activeLength]==text[pos]) {
				if(lastNewNode!=NULL && activeNode!=root) {
					lastNewNode->suffixLink= activeNode;
					lastNewNode=NULL;
				}
				activeLength++;
				break;
			}
			
			splitEnd=(int*)malloc(sizeof(int));
			*splitEnd= next->start+activeLength-1;
		}
	}
}
