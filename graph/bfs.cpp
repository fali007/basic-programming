#include<iostream>
#include<list>
using namespace std;

class graph{
public:
    int v;
    list<int> *adj;
    graph(int v){
        this->v=v;
        adj=new list<int>[v];
    }
    void add_edge(int nod1,int nod2){
        adj[nod1].push_back(nod2);
    }
    void bfs(int s){
        bool *visited= new bool[v];
        for(int i=0;i<v;i++)
            visited[i]=false;
        list<int> q;
        visited[s]=true;
        q.push_back(s);
        list<int>::iterator i;
        while(!q.empty()){
            s=q.front();
            cout<<s<<" ";
            q.pop_front();
            for(i=adj[s].begin();i!=adj[s].end();i++){
                if(!visited[*i]){
                    visited[*i]=true;
                    q.push_back(*i);
                }
            }
        }

    }
};
int main() 
{ 
    graph g(6); 
    g.add_edge(0, 1); 
    g.add_edge(0, 2); 
    g.add_edge(1, 2); 
    g.add_edge(2, 0); 
    g.add_edge(2, 3); 
    g.add_edge(3, 3);
    g.bfs(0); 
    return 0; 
} 
