class node:
    def __init__(self,data,name):
        self.data=data
        self.name=name
        self.left=None
        self.right=None

class heap:
    def __init__(self):
        self.root=None
        self.last=None
    def height(self):
        h=0
        node=self.root
        while node:
            node=node.left
            h+=1
        return h
    def add_node(self,data,name):
        temp=node(data,name)
        if self.root==None:
            self.root=temp
            self.last=self.root
        else:
            q=[]
            q.append(self.root)
            while(len(q)):
                temp1=q[0]
                q.pop(0)
                if temp1.left==None:
                    temp1.left=temp
                    self.last=temp1.left
                    break
                else:
                    q.append(temp1.left)
                if temp1.right==None:
                    temp1.right=temp
                    self.last=temp1.right
                    break
                else:
                    q.append(temp1.right)
    def min_heapiyi(self,node):
        if node.left==None:
            return
        if node.left:
            self.min_heapiyi(node.left)
            if node.right:
                self.min_heapiyi(node.right)
            if node.left.data<node.data:
                temp=node.data
                node.data=node.left.data
                node.left.data=temp
            if node.right:
                if node.right.data<node.data:
                    temp=node.data
                    node.data=node.right.data
                    node.right.data=temp
    def inorder(self,node):
        if node:
            self.inorder(node.left)
            print(node.data)
            self.inorder(node.right)
    def pop(self):
        temp=self.root
        self.root.data=self.last.data
        for _ in range(self.height()-1):
            self.min_heapiyi(self.root)
        return temp

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

    def set_distance(self,start):
        distance={v:1000 for v in self.vertices}
        distance[start]=0
        return distance

    def dijistra(self,start):
        temp=self.set_distance(start)
        hea=heap()
        hea.add_node(0,start)
        for i in self.edges:
            if start in i[:2]:
                if i[0]==start:
                    nod=i[1]
                else:
                    nod=i[0]
                hea.add_node(i[2],nod)
        hea.inorder(hea.root)
        var=hea.pop()
        print(var.data)
        hea.inorder(hea.root)        

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
gr.display()
gr.dijistra('a')