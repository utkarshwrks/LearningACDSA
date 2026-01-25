#include <iostream>
#include <vector>
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

void inOrder(Node* root){
	if(root==NULL){
		return;
	}
	

	inOrder(root->left);
		cout<<root->data<<" ";
	inOrder(root->right);
}

Node* rightmostinleftsub(Node* root){
	Node* ans;
	
	while(root!=NULL){
		ans=root;
		root=root->right;
	}
	return ans;
}


Node* lefttmostinrightsub(Node* root){
	Node* ans;
	
	while(root!=NULL){
		ans=root;
		root=root->left;
	}
	return ans;
}

vector <int> getPredSucc(Node* root,int key){
	Node* cur =root;
	
	Node* pred=NULL;
	Node* succ=NULL;
	
	while(cur!=NULL){
		if(key<cur->data){
			succ=cur;
			cur=cur->left;
		}else if(key>cur->data){
			pred=cur;
			cur=cur->right;
		}else{
			if(cur->left!=NULL){
				pred=rightmostinleftsub(cur->left);
			}
			if(cur->right!=NULL){
					succ=lefttmostinrightsub(cur->right);
			}
			break;
		}
	}
	
	return {pred->data,succ->data};
}



int main() {
    Node* root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key = 3;
    vector<int> ans = getPredSucc(root, key);

    cout << "predecessor: " << ans[0] << endl;
    cout << "successor: " << ans[1] << endl;

    return 0;
}
