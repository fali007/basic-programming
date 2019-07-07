#include <iostream>
using namespace std;
class node{
public:
	int data;
	node *left;
	node *right;
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
class maxheap{
public:
	node* create_node(int data){
		node* temp=new node;
		temp->data=data;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
	void swap(node *nod1,node *nod2){
		int temp;
		temp=nod1->data;
		nod1->data=nod2->data;
		nod2->data=temp;
		return;
	}
	void check(node *nod){
		node *temp,*temp1;
		temp=nod->left;
		temp1=nod->right;
		if(nod->data<temp->data)
			swap(nod,temp);
		if(nod->data<temp1->data)
			swap(nod,temp1);
		return;
	}
	void maxheapify(node* nod){
		if(nod==NULL)
			return;
		if(nod->left!=NULL){
			maxheapify(nod->left);
			check(nod);
			return;
		}
		if(nod->right!=NULL){
			maxheapify(nod->right);
			check(nod);
			return;
		}
		if(nod->right==NULL)
			return;
		if(nod->left==NULL)
			return;
	}
	void insert_heap(int data){
		node *temp=create_node(data);
		if(root==NULL){
			root=temp;
			cout<<endl<<"added as root node "<<data<<endl;
			return;
		}
		else{
			node *temp1;
			queue q;
			q.enqueue(root);
			while(q.len()!=0){
				temp1=q.dequeue();
				if(temp1->left==NULL){
					temp1->left=temp;
					cout<<"added as left node "<<data<<endl;
					break;
				}
				else
					q.enqueue(temp1->left);
				if(temp1->right==NULL){
					temp1->right=temp;
					cout<<"added as right node "<<data<<endl;
					break;
				}
				else
					q.enqueue(temp1->right);
			}
		}
		return;
	}
	void inorder(node *temp){
		if(temp){
			inorder(temp->left);
			cout<<temp->data;
			inorder(temp->right);
		}
	}
};

int main(){
	maxheap h;
	h.insert_heap(1);
	h.insert_heap(2);
	h.insert_heap(3);
	h.insert_heap(4);
	h.insert_heap(5);
	h.insert_heap(6);
	h.insert_heap(7);
	h.insert_heap(8);
	h.inorder(root);
	// h.maxheapify(root);
	if(root->data<root->left->data)
		cout<<"hiii";
}