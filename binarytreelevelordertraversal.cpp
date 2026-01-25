#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int val){
			data=val;
			left=right=NULL;
		}
};


static int idx=-1;
Node* buildTree(vector<int> preorder){
	idx++;
	if(preorder[idx]==-1){
		return NULL;
	}
	
	Node* root = new Node(preorder[idx]);
	root->left=buildTree(preorder);
	root->right=buildTree(preorder);
	return root;
}

void levelOrder(Node* root){
	queue<Node*> q;
	
	q.push(root);
	q.push(NULL);
	
	while(q.size()>0){
		Node* cur=q.front();
		q.pop();
		if(cur==NULL){
			if(!q.empty()){
			cout<<endl;
			q.push(NULL);
			continue;
		}
		else{
			break;
		}
		}
		cout<<cur->data<<" ";
		if(cur->left!=NULL){
			q.push(cur->left);
		}
		if(cur->right!=NULL){
			q.push(cur->right);
		}
	}
}

int main(){
	vector<int> preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
	
	Node* root = buildTree(preorder);
	levelOrder(root);
	cout<<endl;
	
}