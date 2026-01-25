#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int val){
			data = val;
			next = NULL;
		}
};

class Circularlist{
	Node* head;
	Node* tail;
	
	public:
		Circularlist(){
			head=tail=NULL;
		}
		
		void insertedathead(int val){
			Node* newNode= new Node(val);
			
			if(head==NULL){
				head=tail=newNode;
				tail->next=head;
			}else{
				newNode->next=head;
				head=newNode;
				tail->next=head;// with head
                
//                newNode->next=tail->next;
//                tail->next=newNode;


			}
		}
		
			void insertedattail(int val){
			Node* newNode= new Node(val);
			
			if(tail==NULL){
				head=tail=newNode;
				tail->next=head;
			}else{
				newNode->next=head;
				
				tail->next=newNode;
				tail=newNode;


			}
		}
		
		
		void deletehead(){
			if(head==NULL){
				return;
			}else if(head==tail){
				delete head;
				head=tail=NULL;
			}else{
				Node* temp = head;
				head=head->next;
				tail->next=head;
				temp->next=NULL;
				delete temp;
			}
		}
		
		void deletetail(){
			if(tail==NULL){
				return;
			}else if(head==tail){
				delete head;
				head=tail=NULL;
			}else{
				Node* temp = tail;
				Node* prev=head;
				while(prev->next!=tail){
					prev=prev->next;
				}
				tail=prev;
				tail->next=head;
				temp->next=NULL;
				delete temp;
			}
		}
		
		void print(){
			if(head==NULL) return;
			
			cout<<head->data<<"->";
			
			Node* temp= head->next;
			
			while(temp!=head){
				
					cout<<temp->data<<"->";
					temp=temp->next;
			}
			
			cout<<temp->data<<endl;
		}
};


int main(){
	
	Circularlist cl;
	cl.insertedathead(1);
	cl.insertedathead(2);
	cl.insertedathead(3);
	cl.deletehead();
	
	cl.insertedattail(4);
	cl.deletetail();
		cl.insertedattail(5);
	
	cl.print();
	
}