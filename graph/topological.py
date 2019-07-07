# directed graph
gr = { "a" : ["c","d"],
          "b" : ["c", "f"],
          "c" : [],
          "d" : ["e"],
          "e" : ["f"],
          "f" : []
        }

class graph:
    def __init__(self,graph):
        self.graph=graph
    def set_graph(self):
        vertex_no={i:0 for i in self.graph}
        for i in self.graph:
            for j in self.graph:
                for k in self.graph[j]:
                    if k==i:
                        vertex_no[i]+=1
        return vertex_no
    def topo(self,visited=None,ans=None):
        vertex=self.set_graph()
        print(vertex)
        if ans==None:
            ans=[]
        if visited==None:
            visited=[]
        for i in vertex:
            if vertex[i]==0:
                visited.append(i)
                ans.append(i)
        while len(visited):
            temp=self.graph[visited[0]]
            visited.pop(0)
            for k in temp:
                print(k)
                vertex[k]-=1
                if vertex[k]==0:
                    visited.append(k)
                    ans.append(k)
            print(vertex)
        return ans
gra=graph(gr)
print(gra.topo())
