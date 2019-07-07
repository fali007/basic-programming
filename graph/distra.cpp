#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* link;
}*root;

class graph{
public:
	int data;
	int flag;
	graph* link[10];
}*ini;

class dist{
public:
	node* create_node(int val){
		node* address;
		address=new node;
		address->data=val;
		address->link=NULL;
		return address;
	}
	int printa(int val){
		node* a=create_node(val);
		return a->data;
	}
	void add_node(int val){
		node *a,*b;
		b=create_node(val);
		if(root==NULL)
			root=b;
		else{
			a=root;
			while(a->link!=NULL)
				a=a->link;
			a->link=b;
			cout<<"success\n";
		}
		return;
	}
	void disp(void){
		node *a;
		a=root;
		while(a!=NULL){
			cout<<a->data;
			a=a->link;
		}
	}
	graph* create_graph(void){
		int num,tem;
		graph *temp=new graph;
		cout<<"enter the name of node :";
		cin>>temp->data;
		cout<<"enter the number of branches :";
		cin>>num;
		temp->link[0]=0;
		cout<<temp->link[0];
		for(int i=0;i<num;i++){
			cout<<"enter the "<<i<<" link of node: ";
			cin>>tem;
			graph *ord=new graph;
			ord->data=tem;
			ord->flag=0;
			temp->link[i]=ord;
		}
		return temp;
	}
	void disp_graph(void){
		graph *a;
		a=ini;
		while(a!=NULL){
			cout<<a->data;
			a=a->link[0];
			}
		return;
	}
	void add_graph_node(){
		graph *a,*b;
		a=create_graph();
		if(ini==NULL){
			ini=a;
			return;
		}
		else{
			b=ini;
			while(b->link[0]!=NULL){
				b=b->link[0];
			}
			b->link[0]=a;
		}
		return;
	}
	void init_graph(void){
		int a,b;
		int nodes[10];
		cout<<"enter the number of nodes(<10): ";
		cin>>a;
		for(int i=0;i<a;i++){
			cout<<"enter node"<<i+1<<": ";
			cin>>nodes[i];
		}
	}
};

int main(){
	dist a;
	cout<<a.printa(5);
	a.add_node(7);
	a.add_node(8);
	a.disp();
	a.add_graph_node();
	a.disp_graph();
	return 0;

}