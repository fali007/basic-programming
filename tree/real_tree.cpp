#include<iostream>
#include<list>
using namespace std;
// ..........................tree node..........................
class node{
public:
    int data;
    list<node*> child;
}*root;

// ..........................queue start..........................
class link{
public:
    node* data;
    link* next;
}*q;
class queue{
public:
    link* create_link(node* data){
        link* temp=new link;
        temp->data=data;
        temp->next=NULL;
        return temp;
    }
    void enqueue(node* data){
        link* temp=create_link(data);
        if(q==NULL){
            q=temp;
            // cout<<endl<<"successfully enqueued as root "<<(*data).data;
        }
        else{
            link* p=q;
            while(p->next)
                p=p->next;
            p->next=temp;
            // cout<<endl<<"successfully enqueued "<<(*data).data;
        }
    }
    node* dequeue(void){
        node* data=q->data;
        q=q->next;
        // cout<<endl<<"successfully dequeued "<<(*data).data;
        return data;
    }
    int length(void){
        int count;
        link* temp=q;
        while(temp){
            count+=1;
            temp=temp->next;
        }
        return count;
    }
};
// ..........................queue end..........................
// ..........................tree..........................
class tree{
public:
    node* create_node(int data){
        node* temp=new node;
        temp->data=data;
        return temp;
    }
    node* get_node(int name){
        queue q;
        q.enqueue(root);
        while(q.length()){
            node* temp=q.dequeue();
            if(temp->data==name){
                cout<<endl<<"found and returning";
                return temp;
            }
            else{
                list<node*>::iterator it=temp->child.begin();
                while(it!=temp->child.end()){
                    q.enqueue(*it);
                    it++;
                }
            }
        }
    }
    void add_node(int name,int data){
        node* temp=create_node(data);
        if(root==NULL){
            root=temp;
            cout<<endl<<"Added as root "<<data;
        }
        else{
            node* temp1=get_node(name);
            temp1->child.push_back(temp);
            cout<<endl<<"Added as child of "<<name<<" "<<data;
        }
    }
};
// ..........................tree end..........................
int main(){
    tree tr;
    tr.add_node(0,1);//shows seg fault when non created node is given as first argument
    tr.add_node(1,2);
    tr.add_node(1,3);
    tr.add_node(2,4);
    tr.add_node(3,5);
    return 0;
}