#include<iostream>
#include<list>
using namespace std;
class node{
public:
    int data;
    list<node*> child;
}*root;
class parent{
public:
    node* create_node(int data){
        node* temp=new node;
        temp->data=data;
        return temp;
    }
    void add_node(int data){
        node* temp=create_node(data);
        if(root==NULL){
            root=temp;
            cout<<endl<<"added as root : "<<data;
        }
        else{
            root->child.push_back(temp);
            cout<<endl<<"added at root as child : "<<data;
        }
    }
    void disp(void){
        node* temp=root;
        list<node*>::iterator it = root->child.begin();
        while(it!=root->child.end()){
            cout<<"-"<<(*it)->data;
            it++;
        }
    }
};
int main(){
    parent p;
    p.add_node(1);
    p.add_node(4);
    p.add_node(2);
    p.add_node(3);
    p.disp();
}