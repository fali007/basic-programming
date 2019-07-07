#include <iostream>
using namespace std;

class node{
public:
	int data;
	node *next;
}*root;

class stack{
public:
	node* createNode(int);
	void display(void);
	void push(int);
	void pop(void);
};
node* stack::createNode(int val){
	node *temp=new node;
	temp->data=val;
	temp->next=NULL;
	return temp;
}
void stack::display(){
	node *ptr;
	ptr=root;
	while(ptr!=NULL){
		cout<<ptr->data;
		ptr=ptr->next;
	}
}
void stack::push(int val){
	node *temp,*p;
	temp=createNode(val);
	if(root==NULL){
		root=temp;
		root->next=NULL;
	}
	else{
		p=root;
		while(p->next!=NULL)
			p=p->next;
		p->next=temp;
	}
	return;
}
void stack::pop(){
	node *p,*temp;
	p=root;
	root=root->next;
	cout<<p->data;
	delete p;
	return;
}

int main(){
	cout<<"hi";
	stack a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	a.push(6);
	a.push(7);
	a.push(8);
	a.display();
	cout<<"asd";
	a.pop();
	return 0;
}