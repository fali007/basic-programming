// #include<iostream>
// using namespace std;

// class node{
// public:
//     int data;
//     node* next;
// }*root;

// class list{
// public:
//     node* create_node(int data){
//         node* temp=new node;
//         temp->data=data;
//         temp->next=NULL;
//         return temp;
//     }
//     void add_node(int data){
//         node* temp=create_node(data);
//         if(root==NULL){
//             root=temp;
//             return;
//         }
//         else{
//             node* temp1=root;
//             while(temp1->next)
//                 temp1=temp1->next;
//             temp1->next=temp;
//             return;
//         }
//     }
//     void disp(void){
//         node* temp=root;
//         while(temp){
//             cout<<temp->data<<"-";
//             temp=temp->next;
//         }
//         return;
//     }
//     void del(void){
//         node* temp=root;
//         node *temp1,*prev;
//         while(temp){
//             temp1=temp->next;
//             prev=temp;
//             while(temp1){
//                 if(temp1->data==temp->data){
//                     cout<<"dup found "<<endl;
//                     cout<<prev->data;
//                     cout<<temp1->data;
//                     prev->next=temp1->next;
//                     delete temp1;
//                 }
//                 prev=temp1;
//                 temp1=temp1->next;
//             }
//             temp=temp->next;
//         }
//     }
// };

// int main(){
//     list li;
//     li.add_node(1);
//     li.add_node(1);
//     li.add_node(1);
//     li.add_node(1);
//     li.add_node(1);
//     li.add_node(1);
//     li.add_node(1);
//     li.add_node(1);
//     li.add_node(1);
//     li.disp();
//     li.del();
//     li.disp();
//     return 0;
// }

#include<iostream>
using namespace std;
template<typename felix>
felix add(felix a,felix b){
	return a+b;
} 
int main(){
	double a=4.02;
	double b=4;
	cout<<add(a,b);
}