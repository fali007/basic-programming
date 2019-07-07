#include<iostream>
#include<list>
using namespace std;

class graph{
public:
    int data;
    list<int> *adj;
    graph(int data){
        this->data=data;
        adj=new list<int>[data];
    }
    void add_node(int n1,int n2){
        adj[n1].push_back(n2);
    }
    void dfs(int s){
        bool *visited=new bool[data];
        for(int i=0;i<data;i++){
            visited[i]=false;
        }
        list<int> stack;
        visited[s]=true;
        stack.push_back(s);
        list<int>::iterator i;
        while(!stack.empty()){
            s=stack.back();
            cout<<s<<" ";
            stack.pop_back();
            for(i=adj[s].begin();i!=adj[s].end();i++){
                if(!visited[*i]){
                    visited[*i]=true;
                    stack.push_back(*i);
                }
            }
        }
    }
};
int main(){
    graph gr(4);
    gr.add_node(0,1);
    gr.add_node(1,2);
    gr.add_node(0,2);
    gr.add_node(2,3);
    gr.dfs(0);
}