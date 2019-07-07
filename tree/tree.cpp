#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
}*root;

class link{
public:
    node* data;
    link* next;
}*q;

class queue{
public:
    link* create_link(node* data){
        link *temp=new link;
        temp->data=data;
        temp->next=NULL;
        return temp;
    }
    void enqueue(node* data){
        link *temp,*ptr;
        temp=create_link(data);
        if(q==NULL){
            q=temp;
            q->next=NULL;
            // cout<<"added as root ";
        }
        else{
            ptr=q;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=temp;
            // cout<<"added as link ";
        }
        return;
    }
    node* dequeue(void){
        node* data=q->data;
        q=q->next;
        // cout<<"dequed ";
        return data;
    }
    int len(void){
        link *ptr=q;
        int count=0;
        while(ptr!=NULL){
            ptr=ptr->next;
            count+=1;
        }
        return count;
    }
};

class tree{
public:
    node* create_node(int data){
        node* temp;
        temp=new node;
        temp->data=data;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    void insert(int data){
        node *temp,*temp1;
        temp1=create_node(data);
        if(root==NULL){
            root=temp1;
            cout<<"added as root node "<<data<<endl;
            return;
        }
        else{
            queue q;
            q.enqueue(root);
            while(q.len()!=0){
                temp=q.dequeue();
                if(temp->left==NULL){
                    temp->left=temp1;
                    cout<<"added as left node "<<data<<endl;
                    break;
                }
                else
                    q.enqueue(temp->left);
                if(temp->right==NULL){
                    temp->right=temp1;
                    cout<<"added as right node "<<data<<endl;
                    break;
                }
                else
                    q.enqueue(temp->right);
            }
        }
        return;
    }
    void inorder(node* ptr){
        if(ptr){
            inorder(ptr->left);
            cout<<ptr->data<<" ";
            inorder(ptr->right);
        }
    }
    void preorder(node* ptr){
        if(ptr!=NULL){
            cout<<ptr->data;
            preorder(ptr->left);
            preorder(ptr->right);
        }
    }

    void postorder(node* ptr){
        if(ptr!=NULL){
            postorder(ptr->left);
            postorder(ptr->right);
            cout<<ptr->data;
        }
    }

    void delet(node* nod){
        node *temp;
        temp=root;
        while(temp->right!=NULL)
            temp=temp->right;
        nod->data=temp->data;
        delete temp;
        cout<<endl<<"delete success"<<endl;
        return;
    }

};
int main(){
    tree tr;
    tr.insert(1);
    tr.insert(2);
    tr.insert(3);
    tr.insert(4);
    tr.insert(5);
    tr.insert(6);
    tr.insert(7);
    cout<<endl<<"inorder :";
    tr.inorder(root);
    cout<<endl<<"preorder :";
    tr.preorder(root);
    tr.delet(root->left);
    cout<<"success";
    cout<<endl<<"preorder :";
    tr.preorder(root);
    tr.insert(8);
    cout<<endl<<"preorder :";
    tr.preorder(root);
    cout<<endl<<"postorder :";
    tr.postorder(root);
    return 0;
}