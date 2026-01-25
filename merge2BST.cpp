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


Node* insert(Node* root,int val){
	if(root==NULL) return new Node(val);
	
	if(val<root->data){
		root->left=insert(root->left,val);
	}else{
		root->right=insert(root->right,val);
	}
	return root;
}


Node* buildBST(vector<int> arr){
	Node* root=NULL;
	
	for(int val : arr ){
		root=insert(root,val);
	}
	return root;
}


void inOrder(Node* root,vector<int>& arr){
	if(root==NULL){
		return;
	}
	

	inOrder(root->left,arr);
	arr.push_back(root->data);
	inOrder(root->right,arr);
}

Node* buildBSTsorted(vector <int> temp,int start,int end){
	if(start>end) return NULL;
	
	int mid=start+(end-start)/2;
	Node* root= new Node(temp[mid]);
root->left = buildBSTsorted(temp, start, mid-1);
	root->right = buildBSTsorted(temp, mid+1, end);
	return root;
	
}

Node* merge2BST(Node* root1,Node* root2){
	vector <int> arr1,arr2;
	inOrder(root1,arr1);
	inOrder(root2,arr2);
	int i=0,j=0;
   vector <int> temp;
   
   while(i<arr1.size()&&j<arr2.size())	{
   	if(arr1[i]<arr2[j]){
   		temp.push_back(arr1[i]);
   		i++;
	   }else{
	   	temp.push_back(arr2[j]);
   		j++;
	   }
   }
   
   while(i<arr1.size()){
   		temp.push_back(arr1[i]);
   		i++;
   }
   
   while(j<arr2.size()){
   		temp.push_back(arr2[j]);
   		j++;
   }
   return buildBSTsorted(temp,0,temp.size()-1);
   
}



int main() {
    vector<int> arr1 = {8, 2, 1, 10};
    vector<int> arr2 = {5, 3, 0};

    Node* root1 = buildBST(arr1);
    Node* root2 = buildBST(arr2);

    Node* root = merge2BST(root1, root2);
    vector<int> seq;
    inOrder(root, seq);
    for(int v : seq) {
        cout << v << " ";
    }

    cout << endl;
   
}
