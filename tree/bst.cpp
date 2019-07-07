// self balancing bst
// differnence btw heights cannot be greater than mod 1
#include <iostream>
using namespace std;

#include<iostream>
using namespace std;

class node{
public:
    int data;
    int height;
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
        temp->height=1;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    int max(int a, int b){
    	return (a>b)?a:b;
    }
    int set_height(node *nod){
    	int l=0;
    	int r=0;
    	if(nod->left==NULL)
    		l=0;
    	if(nod->right==NULL)
    		r=0;
    	if(nod->left!=NULL)
    		l=1+set_height(nod->left);
    	if(nod->right!=NULL)
    		r=1+set_height(nod->right);
    	nod->height=(l>r)?l:r;
    	return nod->height;
    }
    int height(node *nod){
    	if(nod==NULL)
    		return 0;
    	return nod->height;
    }
    void bst(node *nod,int data){
    	node *temp1;
    	if(nod->data>data){
    		if(nod->left!=NULL)
    			bst(nod->left,data);

    		if(nod->left==NULL){
    			temp1=create_node(data);
    			nod->left=temp1;
    			nod->height+=1;
    			// cout<<endl<<"added as left node "<<data;
    			return;
    		}
    	}
    	else{
    		if(nod->right!=NULL)
    			bst(nod->right,data);
                
    		if(nod->right==NULL){
    			temp1=create_node(data);
    			nod->right=temp1;
    			nod->height+=1;
    			// cout<<endl<<"added as right node "<<data;
    			return;
    		}
    	}
    }
    void insert(int data){
        node *temp1;
        temp1=create_node(data);
        if(root==NULL){
            root=temp1;
            // cout<<"added as root node "<<data;
            return;
        }
        else{
            bst(root,data);
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
            cout<<ptr->data<<" height :"<<ptr->height<<endl;
        }
    }

    void delet(node* nod){
        node *temp,*temp1;
        temp=nod->right;
        temp1=nod->left;
        if(nod->left==NULL && nod->right==NULL){
            delete nod;
            cout<<endl<<"delete success"<<endl;
            return;
        }
        if(temp->left==NULL){
            nod->data=temp->data;
            nod->right=temp->right;
            delete temp;
            cout<<endl<<"delete success"<<endl;
            return;
        }
        if(temp->left!=NULL){
            while(temp->left!=NULL)
                temp=temp->left;
            nod->data=temp->data;
            delete temp;
            cout<<endl<<"delete success"<<endl;
            return;
        }
        if(temp1->right==NULL && temp1->left!=NULL){
            nod->data=temp1->data;
            nod->left=temp1->left;
            delete temp1;
            cout<<endl<<"delete success"<<endl;
            return;
        }
        return;
    }
};
int main(){
    tree tr;
    tr.insert(5);
    tr.postorder(root);
    tr.insert(3);
    tr.postorder(root);
    tr.insert(2);
    tr.postorder(root);
    tr.insert(4);
    tr.postorder(root);
    tr.insert(1);
    tr.postorder(root);
    tr.insert(0);
    tr.insert(7);
    tr.insert(6);
    cout<<endl<<"inorder :";
    tr.inorder(root);
    cout<<endl<<"preorder :";
    tr.preorder(root);
    tr.delet(root->left);
    cout<<"success";
    cout<<endl<<"preorder :";
    tr.preorder(root);
    tr.insert(8);
    tr.set_height(root);
    cout<<endl<<"preorder :";
    tr.preorder(root);
    cout<<endl<<"postorder :";
    tr.postorder(root);
    cout<<endl<<"inorder :";
    tr.inorder(root);
    return 0;
}