#include <iostream>
using namespace std;

class graph{
public:
	int data;
	int flag;
	graph* link[10];
}*ini;

class dist{
public:
	graph* create_graph(void){
		graph *temp=new graph;
		int dat;
		if(ini==NULL){
			cout<<endl<<"enter the value of node :";
			cin>>dat;
			temp->data=dat;
			ini=temp;
			return temp;
		}
		else{
			cout<<endl<<"enter the value of node :";
			cin>>dat;
			temp->data=dat;
			return temp;
		}
	}
	void disp_graph(void){
		graph *a;
		a=ini;
		while(a!=NULL){
			cout<<a->data<<"-";
			a=a->link[0];
			}
		return;
	}
	int length(void){
		graph* a=ini;
		int count;
		while(a!=NULL){
			count+=1;
			a=a->link[0];
		}
		return count;
	}
	void init_graph(void){
		int a,b,c;
		graph* node[10];
		cout<<"enter the number of nodes(<10): ";
		cin>>a;
		node[0]=create_graph();
		ini->link[0]=node[0];
		for(int i=1;i<a;i++){
			node[i]=create_graph();
			node[i-1]->link[0]=node[i];
		}
		add_branch();
		return;
	}
	graph* get_node(int value){
		graph* ptr=ini;
		while(ptr->data!=value)
			ptr=ptr->link[0];
		return ptr;
	}
	void add_branch(void){
		graph* temp;
		graph* ptr=ini;
		int number,value;
		cout<<"enter the number of links of "<<ptr->data<<" :";
		cin>>number;
		for(int i=1;i<number;i++){
			cout<<"enter the value of link : ";
			cin>>value;
			temp=get_node(value);
			ptr->link[i]=temp;
		}
		return;
	}
};

int main(){
	dist a;
	a.init_graph();
	a.disp_graph();
	return 0;

}