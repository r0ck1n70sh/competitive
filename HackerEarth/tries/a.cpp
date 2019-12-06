#include <bits/stdc++.h>
#define F(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
using namespace std;
class trieNode {
	public:
	char data;
	int priority;
	trieNode *child[26];
	trieNode (char d, int p) {
		this->data=d;
		this->priority=p;
		memset((this->child), 0, sizeof(this->child));
	}
};
class trie {
	public:
		trieNode *head;
		trie() {
			head=new trieNode(0, 0);
		}
		void insert(string &, int);
		int maxPriority(string &);
};
int main() {
	string str;
	trie T;
	int n, q, p;
	scanf("%d%d", &n, &q);
	while(n) {
		cin>>str>>p;
		T.insert(str,p);
		--n;
	}
	while(q) {
		cin>>str;
		printf("%d\n", T.maxPriority(str));
		--q;
	}
	return 0;
}
void trie::insert(string &str, int priority) {
	trieNode *curr=this->head;
	F(i,0,str.length()) {
		int index= str[i]-'a';
		int p=max(priority, curr->priority);
		curr->priority=p;
		if(curr->child[index]==NULL)
			curr->child[index]= new trieNode(str[i], priority);
		
		curr=curr->child[index];
	}
}
int trie::maxPriority(string &str) {
	trieNode *curr=this->head;
	int maxP=0;
	F(i,0,str.length()) {;
		int index= str[i]-'a';
		curr=curr->child[index];
		if(curr==NULL)
			return -1;
 	}
 //	maxP=curr->priority;
 	while(curr) {
		int index=0;
		F(i,0,26) {
			trieNode *temp=curr->child[i];
			if(temp==NULL) continue;
			if(maxP<=(temp->priority)) {
				maxP=temp->priority;
				index=i;
			}
		}
		curr=curr->child[index];
	}
	return maxP;
}
