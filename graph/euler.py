class node:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None
    
class tree:
    def __init__(self):
        self.root=None
    def add_node(self,data):
        temp=node(data)
        if self.root==None:
            self.root=temp
            print("added as root")
        else:
            q=[]
            q.append(self.root)
            while(len(q)):
                temp1=q[0]
                q.pop(0)
                if temp1.left==None:
                    temp1.left=temp
                    print("added as left node")
                    break
                else:
                    q.append(temp1.left)
                if temp1.right==None:
                    temp1.right=temp
                    print("added as right node")
                    break
                else:
                    q.append(temp1.right)
    def inorder(self,node):
        if node.left:
            self.inorder(node.left)
        print(node.data)
        if node.right:
            self.inorder(node.right)
    def euler(self,node):
        print(node.data)
        if node.left==None and node.right==None:
            return
        if node.left:
            self.euler(node.left)
            print(node.data)
        if node.right:
            self.euler(node.right)
            print(node.data)

tr=tree()
tr.add_node(0)
tr.add_node(1)
tr.add_node(2)
tr.add_node(3)
tr.add_node(4)
tr.add_node(5)
tr.inorder(tr.root)
print("euler")
tr.euler(tr.root)