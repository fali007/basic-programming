class node:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None
class heap:
    def __init__(self):
        self.root=None
    def height(self):
        h=0
        node=self.root
        while node:
            node=node.left
            h+=1
        return h
    def insert(self,data):
        temp=node(data)
        if self.root==None:
            self.root=temp
        else:
            q=[]
            q.append(self.root)
            while len(q):
                temp1=q[0]
                q.pop(0)
                if temp1.left==None:
                    temp1.left=temp
                    break
                else:
                    q.append(temp1.left)
                if temp1.right==None:
                    temp1.right=temp
                    break
                else:
                    q.append(temp1.right)
    def inorder(self,node):
        if node:
            self.inorder(node.left)
            print(node.data)
            self.inorder(node.right)
    def max_heapiyi(self,node):
        if node.left==None:
            return
        if node.left:
            self.max_heapiyi(node.left)
            if node.right:
                self.max_heapiyi(node.right)
            if node.left.data>node.data:
                temp=node.data
                node.data=node.left.data
                node.left.data=temp
            if node.right:
                if node.right.data>node.data:
                    temp=node.data
                    node.data=node.right.data
                    node.right.data=temp
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
h=heap()
h.insert(0)
h.insert(1)
h.insert(2)
h.insert(3)
h.insert(4)
h.insert(5)
h.insert(6)
h.insert(7)
h.insert(8)
for i in range(h.height()-1):
    h.max_heapiyi(h.root)
h.inorder(h.root)
h.insert(9)
print("new")
for i in range(h.height()-1):
    h.max_heapiyi(h.root)
h.inorder(h.root)
print("min")
for i in range(h.height()-1):
    h.min_heapiyi(h.root)
h.inorder(h.root)
