class Graph:
    def __init__(self):
        self.vertices=[]
        self.edges=[]

    def add_edge(self,nod1,nod2,weight):
        if [nod1,nod2] in self.edges[:2]:
            print("nodes are already present")
            return
        if nod1 not in self.vertices:
            self.vertices.append(nod1)
        if nod2 not in self.vertices:
            self.vertices.append(nod2)
        self.edges.append([nod1,nod2,weight])
        self.edges=sorted(self.edges,key=lambda x:x[2])

    def display(self):
        print(self.vertices)
        print(self.edges)

    def makeset(self):
        temp=self.vertices
        self.parent={vertice:vertice for vertice in temp}

    def find(self,vertice):
        if self.parent[vertice] != vertice:
            self.parent[vertice] = self.find(self.parent[vertice])
        return self.parent[vertice]

    def union(self,vertice1,vertice2):
        root1 = self.find(vertice1)
        root2 = self.find(vertice2)
        if root1 != root2:
            if self.rank[root1] > self.rank[root2]:
                self.parent[root2] = root1
        else:
	        self.parent[root1] = root2
        if self.rank[root1] == self.rank[root2]: self.rank[root2] += 1

    def min_tree(self):
        self.makeset()
        edge=self.edges
        self.rank={a:0 for a in self.vertices}
        ans=[]
        for edg in edge:
            vertice1, vertice2 = edg[:2]
            if self.find(vertice1) != self.find(vertice2):
                self.union(vertice1, vertice2)
                ans.append(edg)
        print(ans)

gr=Graph()
gr.add_edge('a','b',8)
gr.add_edge('b','c',7)
gr.add_edge('c','d',9)
gr.add_edge('d','e',10)
gr.add_edge('e','f',2)
gr.add_edge('f','g',1)
gr.add_edge('g','h',8)
gr.add_edge('a','g',11)
gr.add_edge('h','a',4)
gr.add_edge('b','i',2)
gr.add_edge('i','f',6)
gr.add_edge('g','i',7)
gr.add_edge('b','e',4)
gr.add_edge('c','e',14)
gr.min_tree()
