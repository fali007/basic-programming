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
    int get_balance(node *nod){
    	if(nod==NULL)
    		return 0;
    	return height(nod->left)-height(nod->right);
    }
    node* left_rotate(node *x){
    	node *y=x->right;
    	node *t2=y->left;
    	y->left=x;
    	x->right=t2;
    	set_height(root);
    	cout<<"left rotation"<<endl;
    	return y;
    }
    node* right_rotate(node *y){
    	node *x=y->left;
    	node *t2=x->right;
    	x->right=y;
    	y->left=t2;
    	set_height(root);
    	cout<<"right rotation"<<endl;
    	return x;
    }
    void bst(node *nod,int data){
    	node *temp1;
    	if(nod->data>data){
    		if(nod->left!=NULL){
    			bst(nod->left,data);
                int a=set_height(root);
                cout<<set_height(root)<<"height ";
                int balance=1+get_balance(nod);
                cout<<data<<" balance: "<<balance<<endl;
                if(balance>1){
                    nod=right_rotate(nod);
                }
                if(balance<-1){
                    nod->right=right_rotate(nod->right);
                    nod=left_rotate(nod);
                }
                return;
            }

    		if(nod->left==NULL){
    			temp1=create_node(data);
    			nod->left=temp1;
    			nod->height+=1;
    			// cout<<endl<<"added as left node "<<data;
    			int a=set_height(root);
                cout<<set_height(root)<<"height ";
    			int balance=1+get_balance(nod);
    			cout<<data<<" balance: "<<balance<<endl;
    			if(balance>1){
    				nod=right_rotate(nod);
                }
    			if(balance<-1){
    				nod->right=right_rotate(nod->right);
    				nod=left_rotate(nod);
    			}
    			return;
    		}
    	}
    	else{
    		if(nod->right!=NULL){
    			bst(nod->right,data);
                int a=set_height(root);
                cout<<set_height(root)<<"height ";
                int balance=1+get_balance(root);
                cout<<data<<" balance: "<<balance<<endl;
                if(balance>1){
                    nod->left=left_rotate(nod->left);
                    right_rotate(nod);
                }
                if(balance<-1)
                    left_rotate(nod);
                return;
            }
    		if(nod->right==NULL){
    			temp1=create_node(data);
    			nod->right=temp1;
    			nod->height+=1;
    			// cout<<endl<<"added as right node "<<data;
    			int a=set_height(root);
                cout<<set_height(root)<<"height ";
    			int balance=1+get_balance(root);
    			cout<<data<<" balance: "<<balance<<endl;
    			if(balance>1){
    				nod->left=left_rotate(nod->left);
    				right_rotate(nod);
    			}
    			if(balance<-1)
    				left_rotate(nod);
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
    // cout<<endl<<"inorder :";
    // tr.inorder(root);
    // cout<<endl<<"preorder :";
    // tr.preorder(root);
    // // tr.delet(root->left);
    // // cout<<"success";
    // // cout<<endl<<"preorder :";
    // // tr.preorder(root);
    // tr.set_height(root);
    // cout<<endl<<"preorder :";
    // tr.preorder(root);
    // cout<<endl<<"postorder :";
    tr.postorder(root);
    // cout<<endl<<"inorder :";
    tr.inorder(root);
    return 0;
}